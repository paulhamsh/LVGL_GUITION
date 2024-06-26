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
  <img src="https://github.com/paulhamsh/Electrow-Terminal-7-LVGL/blob/main/Elecrow-Terminal-7.png" width="400" title="Elecrow Terminal">
</p>   

The wiki is here: https://www.elecrow.com/wiki/esp32-display-702727-intelligent-touch-screen-wi-fi26ble-800480-hmi-display.html  


## Build LVGL demos with v8.4.0 and standard code  

Board manager: ESP32 S3 Dev Module   
esp32 version 2.0.16   
Arduino IDE:   2.3.2   

Install Arduino libraries:
```
  lvgl           version 8.4.0
  LoyvyanGFX     version 1.1.16
  TAMC-GT911     version 1.0.2
```
Get the 4.0inch_ESP32-4848S040.zip file from here: http://pan.jczn1688.com/directlink/1/ESP32%20module/4.0inch_ESP32-4848S040.zip


Make a folder and copy over the folder ```HMI-7``` into it  (for board type  WZ8048C070 - if a different board type read the README.txt)   

Copy the UI folder from the zip file ```Arduino_7inch\libraries\UI``` to ```Arduino\libraries```

Copy the lv_conf.h from ```Arduino_7inch\Libraries\lv_conf.h``` to ```Arduino\libraries\lvgl\src\lv_conf.h```   

Ensure the Arduino settings are:
```
PSRAM:    OPI PSRAM
Partition Scheme: Huge App (3MB No OTA / 1MB SPIFFS)
```

Copy folders ```Arduino\libraries\lvgl\demos``` and ```Arduino\libraries\lvgl\examples```  to ```lvgl\src```   

There is a pre-built lv_conf.h in the v8 folder.   

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
