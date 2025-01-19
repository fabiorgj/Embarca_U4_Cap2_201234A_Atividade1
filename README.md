Embarcatech - U4 - Microcontroladores

Atividade 1 - Aula sícrona de 14/01/2025

Grupo 1, Subgrupo 8

Integrantes:

Fábio Rocha Gomes Jardim

Igor de Eça Almeida

Kauan Lopes de Jesus

Larissa Batista dos Santos

Luis Guilherme Coelho Saturnino

Paolla Giselle Ribeiro


## DESCRIÇÃO

Este programa foi desenvolvido para a Raspberry Pi Pico e utiliza um teclado matricial 4x4 para controlar LEDs RGB e um buzzer através de uma RaspBerry Pi Pico W. Cada tecla do teclado aciona uma função específica, como ligar/desligar LEDs ou ativar o buzzer.

O programa é composto por funções para inicializar e operar os LEDs, o buzzer, e o teclado, além de um loop principal que monitora a entrada do teclado e executa as funções correspondentes.


## FUNCIONALIDADES

- Acionamento e desacionamento de LEDs (verde, azul e vermelho).
- Ativação de combinações específicas dos LEDs.
- Ativação do buzzer.
- Leitura de teclas do teclado matricial 4x4.


## INSTRUÇÕES PARA USO

Hardware Necessário:

- Raspberry Pi Pico.
- Teclado matricial 4x4 conectado aos pinos GP1–GP8.
- Três LEDs (vermelho, azul e verde) conectados aos pinos GP18, GP19 e GP20, com resistores apropriados.
- Buzzer conectado ao pino GP28.

Como Usar:

- Conecte os componentes conforme especificado no diagrama ao final.
- Compile e carregue o código no Raspberry Pi Pico utilizando o SDK do Pico (CMake).
- Pressione as teclas no teclado para controlar os LEDs e o buzzer:
- Teclas '1', '2', '3': Ligam os LEDs verde, azul e vermelho, respectivamente.
- Teclas '4', '5', '6': Desligam os LEDs verde, azul e vermelho, respectivamente.
- Tecla '7': Liga os LEDs azul e verde por 3 segundos.
- Tecla '8': Liga todos os LEDs por 3 segundos.
- Tecla '9': Liga os LEDs vermelho e azul por 3 segundos.
- Teclas 'A', 'B', 'C', '*', '0', '#', 'D': Acionam o buzzer.


## EXPLICAÇÃO DAS FUNÇÕES
- inicializa_teclado(): Configura os pinos GPIO para operar como entradas ou saídas do teclado matricial.
- inicializa_LEDs(): Configura os pinos dos LEDs como saídas e garante que estão inicialmente apagados.
- init_buzzer(uint pin): Configura o PWM no pino do buzzer para gerar um sinal de 2 kHz.
- ler_tecla(): Detecta e retorna a tecla pressionada. Se nenhuma tecla for pressionada, retorna \0.
- func_1() a func_6(): Ligam ou desligam os LEDs RGB individualmente.
- func_7() e func_9(): Ativam combinações específicas de LEDs por 3 segundos.
- func_8(): Liga todos os LEDs por 3 segundos.
- aciona_buzzer(): Ativa o buzzer com um duty cycle de 50% por 1 segundo.


## LISTA DE COMPONENTES E CONEXÕES

GP1: Conectado ao C4 do Keypad.

GP2: Conectado ao C3 do Keypad.

GP3: Conectado ao C2 do Keypad.

GP4: Conectado ao C1 do Keypad.

GP5: Conectado ao R4 do Keypad.

GP6: Conectado ao R3 do Keypad.

GP7: Conectado ao R2 do Keypad.

GP8: Conectado ao R1 do Keypad.

GP18: Conectado ao LED vermelho.

GP19: Conectado ao LED azul.

GP20: Conectado ao LED verde.

GP28: Conectado ao terminal positivo (pino 2) do buzzer.

GND.4: Compartilhado como o terra para os cátodos dos LEDs.

GND.8: Conectado ao terminal negativo (pino 1) do buzzer.

## DIAGRAMA COM COMPONENTES

![Conexões do Circuito](https://github.com/fabiorgj/Embarca_U4_Cap2_201234A_Atividade1/blob/main/Diagrama_componentes.png)
