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


//main
int main(){
  //inicializando LEDs e teclado
  inicializa_LEDs();
  inicializa_teclado();
  while(true){
    //lendo a tecla
    char tecla = ler_tecla();
    //se for 8,chama a função que liga todos os LEDs
    if(tecla == '8' ){
      liga_todos_LEDs();}
    sleep_ms(100);
    // liga led verde
    if (tecla == '1'){
        liga_led_green();
        }
    // liga led azul
    else if (tecla == '2'){
        liga_led_blue();
    }
    // liga led vermelho
    else if(tecla == '3') {
        liga_led_red();
    }
  }
return 0;
}