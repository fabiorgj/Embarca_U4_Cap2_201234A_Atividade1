#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"

//mapa de teclas
char mapa_TECLAS[4][4]={
  '1','2','3','A',
  '4','5','6','B',
  '7','8','9','C',
  '*','0','#','D'
};

// Definindo os pinos para linhas e colunas
const uint linhas[] = {8, 7, 6, 5};   // Pinos das linhas (GP5, GP6, GP7, GP8)
const uint colunas[] = {4, 3, 2, 1}; // Pinos das colunas (GP1, GP2, GP3, GP4)

// Protótipos das funções chamadas por cada tecla
void func_1(void);
void func_2(void);
void func_3(void);
void func_A(void);
void func_4(void);
void func_5(void);
void func_6(void);
void func_B(void);
void func_7(void);
void func_8(void);
void func_9(void);
void func_C(void);
void func_star(void);
void func_0(void);
void func_hash(void);
void func_D(void);


// Inicializando os GPIOs do teclado 
void inicializa_teclado() {
    // Configurando as linhas como saída
    for (int i = 0; i < 4; i++) {
        gpio_init(linhas[i]);
        gpio_set_dir(linhas[i], GPIO_OUT);
        gpio_put(linhas[i], 1); // Mantendo em nível alto
    }

    // Configurando as colunas como entrada com pull-up
    for (int i = 0; i < 4; i++) {
        gpio_init(colunas[i]);
        gpio_set_dir(colunas[i], GPIO_IN);
        gpio_pull_up(colunas[i]);
    }
}

//Lendo a tecla pressionada no teclado 
char ler_tecla() {
    for (int i = 0; i < 4; i++) {
        //Colocando a linha atual em nível baixo
        gpio_put(linhas[i], 0);

        //Verificando se alguma coluna está em nível baixo
        for (int j = 0; j < 4; j++) {
            if (gpio_get(colunas[j]) == 0) { //Coluna em nível baixo
                sleep_ms(20); //intervalo simples
                if (gpio_get(colunas[j]) == 0) {
                    //Restaurandi a linha para nível alto
                    gpio_put(linhas[i], 1);
                    return mapa_TECLAS[i][j];
                }
            }
        }

        //Restaurando a linha para nível alto
        gpio_put(linhas[i], 1);
    }
    return '\0'; //Sem teclas pressionadas
}

//definindo constantes
const uint led_pin_red = 18;
const uint led_pin_blue = 19;
const uint led_pin_green = 20;

//função que inicializa os LEDs
void inicializa_LEDs(){
  gpio_init(led_pin_red); //inicializando o pino 18
  gpio_set_dir(led_pin_red,GPIO_OUT); //configurando o pino como saída

  gpio_init(led_pin_blue); //inicializando o pino 19
  gpio_set_dir(led_pin_blue,GPIO_OUT); //configurando o pino como saída

  gpio_init(led_pin_green); //inicializando o pino 20
  gpio_set_dir(led_pin_green,GPIO_OUT); //configurando o pino como saída
  
  //apagando os LEDs inicialmente
  gpio_put(led_pin_red, 0);
  gpio_put(led_pin_blue, 0);
  gpio_put(led_pin_green, 0);

}

//main
int main(){
  //inicializando stdio
  stdio_init_all();
  //inicializando LEDs e teclado
  inicializa_LEDs();
  inicializa_teclado();
  while(true){
    //lendo a tecla
    char tecla = ler_tecla();
    //se for 8,chama a função que liga todos os LEDs
    switch (tecla) {
        case '1': func_1(); break;
        case '2': func_2(); break;
        case '3': func_3(); break;
        case 'A': aciona_buzzer(); break;
        case '4': func_4(); break;
        case '5': func_5(); break;
        case '6': func_6(); break;
        case 'B': aciona_buzzer(); break;
        case '7': func_7(); break;
        case '8': func_8(); break;
        case '9': func_9(); break;
        case 'C': aciona_buzzer(); break;
        case '*': aciona_buzzer(); break;
        case '0': aciona_buzzer(); break;
        case '#': aciona_buzzer(); break;
        case 'D': aciona_buzzer(); break;
        default: break; // Nenhuma tecla válida
    }
  }
return 0;
}

// Implementação das funções para cada tecla
//Liga os leds respectivamente
void func_1(void) { printf("Função 1 chamada!\n"); }
void func_2(void) { printf("Função 2 chamada!\n"); }
void func_3(void) { printf("Função 3 chamada!\n"); }


//Desliga os leds respectivamente
void func_4(void) { printf("Função 4 chamada!\n"); }
void func_5(void) { printf("Função 5 chamada!\n"); }
void func_6(void) { printf("Função 6 chamada!\n"); }

//Liga todos os leds por 3 segundos
void func_8(void) { 
    gpio_put(led_pin_red, 1);
    gpio_put(led_pin_blue, 1);
    gpio_put(led_pin_green, 1);
    sleep_ms(3000);
    gpio_put(led_pin_red, 0);
    gpio_put(led_pin_blue, 0);
    gpio_put(led_pin_green, 0);
 }

//Liga somente os leds azul e verde por um tempo determinado
void func_7(void) { printf("Função 7 chamada!\n"); }

//Liga somente os leds vermelho e azul por um tempo determinado
void func_9(void) { printf("Função 9 chamada!\n"); }

//Aciona o buzzer por 1 segundo
void aciona_buzzer() { printf("Buzzer acionado!\n"); }
