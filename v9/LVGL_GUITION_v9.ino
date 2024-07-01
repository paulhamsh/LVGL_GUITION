#include <demos/lv_demos.h>
#include <Arduino_GFX_Library.h>

#define GFX_DEV_DEVICE ESP32_4848S040_86BOX_GUITION
#define GFX_BL 38
Arduino_DataBus *bus = new Arduino_SWSPI(
    GFX_NOT_DEFINED /* DC */, 39 /* CS */,
    48 /* SCK */, 47 /* MOSI */, GFX_NOT_DEFINED /* MISO */);

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    18 /* DE */, 17 /* VSYNC */, 16 /* HSYNC */, 21 /* PCLK */,
    11 /* R0 */, 12 /* R1 */, 13 /* R2 */, 14 /* R3 */, 0 /* R4 */,
    8 /* G0 */, 20 /* G1 */, 3 /* G2 */, 46 /* G3 */, 9 /* G4 */, 10 /* G5 */,
    4 /* B0 */, 5 /* B1 */, 6 /* B2 */, 7 /* B3 */, 15 /* B4 */,
    1 /* hsync_polarity */, 10 /* hsync_front_porch */, 8 /* hsync_pulse_width */, 50 /* hsync_back_porch */,
    1 /* vsync_polarity */, 10 /* vsync_front_porch */, 8 /* vsync_pulse_width */, 20 /* vsync_back_porch */);

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    480 /* width */, 480 /* height */, rgbpanel, 1 /* rotation */, true /* auto_flush */,
    bus, GFX_NOT_DEFINED /* RST */, st7701_type9_init_operations, sizeof(st7701_type9_init_operations));


/*******************************************************************************
 * Please config the touch panel in touch.h
 ******************************************************************************/
#include "touch.h"

static uint32_t my_tick_function(void) {
  return millis();
}

/* Change to your screen resolution */
static const uint32_t screenWidth = 480;
static const uint32_t screenHeight = 480;
//int buf_size_in_bytes;
static const int buf_size_in_bytes = screenWidth * screenHeight * sizeof(lv_color_t) / 10;
static lv_color_t *disp_draw_buf;
// Use below if not dynamically allocating memory
//static uint16_t disp_draw_buf[buf_size_in_bytes / sizeof(lv_color_t)];

/* Display flushing */
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)px_map, w, h);
  lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_t *indev_driver, lv_indev_data_t *data)
{
  if (touch_touched()) {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touch_last_x;
    data->point.y = touch_last_y;
  }
  else 
    data->state = LV_INDEV_STATE_REL;
}

lv_display_t *disp;
lv_indev_t   *indev;

void setup()
{
  Serial.begin(115200);
  Serial.println("LVGL Widgets Demo");
  
  gfx->begin(16000000); /* specify data bus speed */
  gfx->fillScreen(BLACK);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif

  touch_init();
  lv_init();

#ifdef ESP32
  disp_draw_buf = (lv_color_t *) heap_caps_malloc(buf_size_in_bytes, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
#else
  disp_draw_buf = (lv_color_t *) malloc(buf_size_in_bytes);
#endif

  if (disp_draw_buf == nullptr)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
    while (1);
  }

  lv_tick_set_cb(my_tick_function);

  disp = lv_display_create(screenWidth, screenHeight);
  lv_display_set_flush_cb(disp, my_disp_flush);
  lv_display_set_buffers(disp, disp_draw_buf, NULL, buf_size_in_bytes, LV_DISPLAY_RENDER_MODE_PARTIAL);

  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  lv_demo_widgets();

  Serial.println("Setup done");
}

void loop()
{
  lv_timer_handler(); /* let the GUI do its work */
  delay(5);
}
