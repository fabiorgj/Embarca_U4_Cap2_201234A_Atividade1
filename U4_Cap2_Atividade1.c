#include <stdio.h>
#include "pico/stdlib.h"

void liga_led_red(){
    gpio_put(led_pin_red, 1);
    sleep_ms(3000);
    gpio_put(led_pin_red, 0);
}

