#include "led.h"
#include "unity.h"
void app_main(void) {
  led_config(1ULL << CONFIG_LED_USB_PIN | 1ULL << CONFIG_LED_AC_PIN |
             1ULL << CONFIG_LED_DC_PIN);
  unity_run_all_tests();
  unity_run_menu();
}