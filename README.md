# INSTRUÇÕES PARA USO
Instruções de Uso para o Circuito com Raspberry Pi Pico W e Teclado Matricial
Este circuito permite controlar LEDs e um buzzer utilizando um teclado matricial de 4x4. As funções associadas a cada tecla estão descritas abaixo. 

1. Operações com o Teclado
O teclado possui diferentes funcionalidades para controlar LEDs e o buzzer. Pressione as teclas correspondentes para executar a ação desejada:
Teclas para ligar os LEDs Individualmente
- Tecla “1”: Liga o LED verde.
- Tecla “2”: Liga o LED azul.
- Tecla “3”: Liga o LED vermelho.

Teclas para desligar os LEDs Individualmente
- Tecla “4”: Desliga o LED verde.
- Tecla “5”: Desliga o LED azul.
- Tecla “6”: Desliga o LED vermelho.

Teclas para Ligar Combinações de LEDs Temporariamente
- Tecla “8”: Liga todos os LEDs (vermelho, azul e verde) por 3 segundos.
- Tecla “7”: Liga apenas os LEDs azul e verde por 3 segundos.
- Tecla “9”: Liga apenas os LEDs vermelho e azul por 3 segundos.

Teclas para acionar o Buzzer
- Teclas “*”, “0”, “#”, “A”, “B”, “C”, “D”: Acionam o buzzer por 1 segundo. Durante este tempo, será emitido um som.



# DESCRIÇÃO DAS FUNÇÕES E CONEXÕES 
# Função 'inicializa_teclado'

Esta função inicializa os pinos do teclado matricial. Ela configura as linhas como saídas, mantendo-as em nível alto, e as colunas como entradas, utilizando resistores pull-up. Esse processo é necessário para que o teclado matricial funcione corretamente com o Raspberry Pi Pico, permitindo a leitura das teclas pressionadas.

# Função 'ler_tecla'

A função ler_tecla() realiza a leitura do teclado matricial. Ela percorre as linhas e colunas do teclado para detectar qual tecla foi pressionada. Quando uma tecla é pressionada, a função retorna o caractere correspondente à tecla pressionada.


# Função 'inicializa_LEDs'

Esta função inicializa os LEDs conectados ao Raspberry Pi Pico, configurando os pinos de controle dos LEDs (vermelho, azul e verde) como saídas. Inicialmente, os LEDs serão desligados.


# Função 'liga_todos_LEDs'

A função liga_todos_LEDs() acende todos os LEDs (vermelho, azul e verde) por 3 segundos e, em seguida, os desliga. Essa função é chamada na 'main' quando a tecla '8' do teclado é pressionada.


# Lista de Pinos e Componentes

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