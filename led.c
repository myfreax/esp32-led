#include "led.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "LED";

esp_err_t led_config(uint64_t pin_bit_mask) {
  gpio_config_t gpio_conf = {
      .intr_type = GPIO_INTR_DISABLE,
      .mode = GPIO_MODE_OUTPUT,
      .pin_bit_mask = pin_bit_mask,
      .pull_down_en = GPIO_PULLDOWN_ENABLE,
      .pull_up_en = GPIO_PULLUP_ENABLE,
  };
  return gpio_config(&gpio_conf);
}

void sos_freq(unsigned char gpio_pin, unsigned int delay) {
  gpio_set_level(gpio_pin, 1);
  vTaskDelay(delay / portTICK_PERIOD_MS);
  gpio_set_level(gpio_pin, 0);
  vTaskDelay(300 / portTICK_PERIOD_MS);
}

void sos(void* arg) {
  while (1) {
    unsigned char led_pin = *(unsigned char*)arg;
    for (char x = 1; x <= 3; x++) {
      sos_freq(led_pin, 300);
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
    for (char x = 1; x <= 3; x++) {
      sos_freq(led_pin, 800);
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
    for (char x = 1; x <= 3; x++) {
      sos_freq(led_pin, 300);
    }
  }
}

TaskHandle_t led_sos_open(unsigned char* led_pin) {
  TaskHandle_t xtask_id;
  xTaskCreate(&sos, "led_sos", 2048, led_pin, 10, &xtask_id);
  return xtask_id;
}

esp_err_t led_sos_close(TaskHandle_t xtask_id, unsigned char led_pin) {
  vTaskDelete(xtask_id);
  return gpio_set_level(led_pin, 0);
}