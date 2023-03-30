
#define LED_BUILTIN1  11

void setup() {
  Serial.begin(9600);   // inicia a comunicação serial com baudrate de 9600
}

void loop() {
  if (Serial.available() > 0) {   // verifica se há dados disponíveis no buffer de entrada
    String command = Serial.readString();   // lê a string do buffer de entrada
    processCommand(command);   // chama a função para processar o comando
  }
}

void processCommand(String command) {
  if (command == "led on") {   // verifica se o comando é "led on"
    digitalWrite(LED_BUILTIN1, HIGH);   // liga o LED interno
    Serial.println("LED ligado");
  } else if (command == "led off") {   // verifica se o comando é "led off"
    digitalWrite(LED_BUILTIN1, LOW);   // desliga o LED interno
    Serial.println("LED desligado");
  } else {
    Serial.println("Comando invalido");
  }
}