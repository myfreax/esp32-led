# ESP32 LED Component
LED Unit Tool Component For ESP32

## Feature
- Open or close LED
- SOS Animation
- More...

## Usage

```shell
git submodule add git@github.com:myfreax/esp32-led.git components/led
```

```c
#include "led.h"

void app_main(void) {
  led_config(1ULL << CONFIG_LED_USB_PIN | 1ULL << CONFIG_LED_AC_PIN |
             1ULL << CONFIG_LED_DC_PIN);
  gpio_set_level(led_pin, 0)
}
```
## Example
The [ESP32 Example Project](https://github.com/myfreax/esp32-example-project) demonstrates how to use IDF framework build application of reusable component



