#include <stdio.h>
#include "pico/stdlib.h"

void liga_led_red(){
    gpio_put(led_pin_red, 1);
    sleep_ms(3000);
    gpio_put(led_pin_red, 0);
}

void liga_led_blue(){
    gpio_put(led_pin_blue, 1);
    sleep_ms(3000);
    gpio_put(led_pin_blue, 0);
}

void liga_led_green(){
    gpio_put(led_pin_green, 1);
    sleep_ms(3000);
    gpio_put(led_pin_green, 0);
}
