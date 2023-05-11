#include "driver/gpio.h"
#include "led.h"
#include "unity.h"

TEST_CASE("led sos signal", "[led]") {
  unsigned char led_pin = 48;
  TaskHandle_t xtask_id = led_sos_open(&led_pin);
  vTaskDelay(2000 / portTICK_PERIOD_MS);
  led_sos_close(xtask_id, 48);
}