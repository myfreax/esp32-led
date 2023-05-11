#pragma once
#include "driver/gpio.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

esp_err_t led_config(uint64_t pin_bit_mask);
TaskHandle_t led_sos_open(unsigned char* led_pin);
esp_err_t led_sos_close(TaskHandle_t xtask_id, unsigned char led_pin);