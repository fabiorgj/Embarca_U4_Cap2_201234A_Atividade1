#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"


// Mapeamento do teclado
char KEY_MAP[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'
};

// Pinos conectados às linhas e colunas
const uint ROW_PINS[4] = {8, 7, 6, 5};  // GP8, GP7, GP6, GP5
const uint COL_PINS[4] = {4, 3, 2, 1};  // GP4, GP3, GP2, GP1

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

// Inicializa os pinos do teclado
void keypad_init() {
    for (int i = 0; i < 4; i++) {
        gpio_init(ROW_PINS[i]);
        gpio_set_dir(ROW_PINS[i], GPIO_OUT); // Linhas como saída
        gpio_put(ROW_PINS[i], 0);           // Inicialmente baixas

        gpio_init(COL_PINS[i]);
        gpio_set_dir(COL_PINS[i], GPIO_IN); // Colunas como entrada
        gpio_pull_down(COL_PINS[i]);        // Puxar para baixo
    }
}


// Função para verificar se a tecla foi pressionada com debounce
char keypad_get_key() {
    static char last_key = '\0';
    char key = '\0';

    // Varre as linhas
    for (int row = 0; row < 4; row++) {
        gpio_put(ROW_PINS[row], 1); // Ativa a linha atual

        // Varre as colunas
        for (int col = 0; col < 4; col++) {
            if (gpio_get(COL_PINS[col])) { // Verifica se a coluna está ativada
                key = KEY_MAP[row * 4 + col]; // Captura a tecla pressionada
                break;
            }
        }

        gpio_put(ROW_PINS[row], 0); // Desativa a linha
        if (key != '\0') {
            break; // Se encontrou a tecla, sai do loop
        }
    }

    // Implementa o debounce simples: só permite a mudança de tecla após 200 ms
    if (key != last_key) {
        last_key = key;
        if (key != '\0') {
            return key;
        }
    }

    return '\0'; // Nenhuma tecla pressionada ou debounce ativo
}

// Chama a função associada à tecla
void call_function(char key) {
    switch (key) {
        case '1': func_1(); break;
        case '2': func_2(); break;
        case '3': func_3(); break;
        case 'A': func_A(); break;
        case '4': func_4(); break;
        case '5': func_5(); break;
        case '6': func_6(); break;
        case 'B': func_B(); break;
        case '7': func_7(); break;
        case '8': func_8(); break;
        case '9': func_9(); break;
        case 'C': func_C(); break;
        case '*': func_star(); break;
        case '0': func_0(); break;
        case '#': func_hash(); break;
        case 'D': func_D(); break;
        default: break; // Nenhuma tecla válida
    }
}

int main() {
    stdio_init_all(); // Inicializa comunicação serial
    keypad_init();    // Inicializa o teclado matricial

    while (true) {
        char key = keypad_get_key(); // Verifica se há uma tecla pressionada

        if (key != '\0') {          // Se uma tecla foi pressionada
            printf("Tecla pressionada: %c\n", key); // Exibe no monitor serial
            call_function(key);     // Chama a função associada
            sleep_ms(200);          // Debounce simples
        }
    }
    return 0;
}

// Implementação das funções para cada tecla
void func_1(void) { printf("Função 1 chamada!\n"); }
void func_2(void) { printf("Função 2 chamada!\n"); }
void func_3(void) { printf("Função 3 chamada!\n"); }
void func_A(void) { printf("Função A chamada!\n"); }
void func_4(void) { printf("Função 4 chamada!\n"); }
void func_5(void) { printf("Função 5 chamada!\n"); }
void func_6(void) { printf("Função 6 chamada!\n"); }
void func_B(void) { printf("Função B chamada!\n"); }
void func_7(void) { printf("Função 7 chamada!\n"); }
void func_8(void) { printf("Função 8 chamada!\n"); }
void func_9(void) { printf("Função 9 chamada!\n"); }
void func_C(void) { printf("Função C chamada!\n"); }
void func_star(void) { printf("Função * chamada!\n"); }
void func_0(void) { printf("Função 0 chamada!\n"); }
void func_hash(void) { printf("Função # chamada!\n"); }
void func_D(void) { printf("Função D chamada!\n"); }
