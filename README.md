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