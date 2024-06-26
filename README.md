# LVGL GUITION
LVGL setup for GUITION  4848S040

## GUITION 4848S040 LVGL Demo build instructions

A lovely ESP32 S3 board.   

Information here:    
   https://homeding.github.io/boards/esp32s3/panel-4848S040.htm     
   https://github.com/esphome/esphome/discussions/6747     
   https://github.com/arendst/Tasmota/discussions/20527      
   https://community.home-assistant.io/t/guition-4-480x480-esp32-s3-4848s040-smart-display-with-lvgl/729271      

<p align="center">
  <img src="https://github.com/paulhamsh/LVGL_GUITION/blob/main/GUITION.jpg" width="400" title="GUITION">
</p>   

## Build LVGL demos with v8.4.0 and example code 

Board manager: ESP32 S3 Dev Module   
esp32 version 2.0.16   
Arduino IDE:   2.3.2   

Install Arduino libraries:
```
  GFX Library for Arduino by Moon On Our Nation   version 1.2.9
  lvgl                                            version 8.4.0
  TAMC-GT911                                      version 1.0.2
```

Copy folders ```Arduino\libraries\lvgl\demos``` and ```Arduino\libraries\lvgl\examples```  to ```lvgl\src```   

Get the 4.0inch_ESP32-4848S040.zip file from here: http://pan.jczn1688.com/directlink/1/ESP32%20module/4.0inch_ESP32-4848S040.zip
Copy folder ```4.0inch_ESP32-4848S040\1-Demo\Demo_Arduino\1_2_4.0_LvglWidgets``` somwhere.   

Copy the lv_conf.h from ```1_2_4.0_LvglWidgets\LVGL configuration replacement file``` to ```Arduino\libraries\lvgl\src\lv_conf.h```   
In lv_conf.h comment out ```#define LV_USE_FS_FATFS 1```

In 4.0_LvglWidgets.ino do the following edits.    

Add:   
```
    #include <lvgl.h>   
    #include <demos/lv_demos.h>   
```
Comment out:   
```
    #include "lv_demo_widgets.h"   
```

Delete these files: 
```
img_clothes.c
img_demo_widgets_avatar.c
img_lvgl_logo.c
lv_demo_widgets.c
lv_demo_widgets.b   
```

Ensure the Arduino settings are:
```
PSRAM:    OPI PSRAM
Partition Scheme: Huge App (3MB No OTA / 1MB SPIFFS)
```










## Build LVGL demos with v8.4.0 and code in v8 folder  

Board manager: ESP32 S3 Dev Module   
esp32 version 2.0.16   
Arduino IDE:   2.3.2   

Install Arduino libraries:
```
  lvgl           version 8.4.0
  LoyvyanGFX     version 1.1.16
  TAMC-GT911     version 1.0.2
```
Get the code in the v8 folder, in a folder named ```LVGL-8-7inch```   

Copy the lv_conf.h to ```Arduino\libraries\lvgl\src\lv_conf.h```   

Ensure the Arduino settings are:
```
PSRAM:    OPI PSRAM
Partition Scheme: Huge App (3MB No OTA / 1MB SPIFFS)
```
Copy folders ```Arduino\libraries\lvgl\demos``` and ```Arduino\libraries\lvgl\examples```  to ```lvgl\src```   

Compile and run    

## Build LVGL demos with v9.1.0

Board manager: ESP32 S3 Dev Module   
esp32 version 2.0.16   
Arduino IDE:   2.3.2   

Install Arduino libraries:
```
  lvgl           version 9.1.0
  LoyvyanGFX     version 1.1.16
```

Copy ```Arduino\libraries\lvgl\lv_conf_template.h``` to ```src\lv_conf.h```   
Copy folders ```Arduino\libraries\lvgl\demos``` and ```Arduino\libraries\lvgl\examples```  to ```Arduino\libraries\lvgl\src```     
Edit
```
#if 1 /*Set it to "1" to enable content*/
#define LV_USE_DEMO_WIDGETS 1
#define LV_FONT_MONTSERRAT_24 1
