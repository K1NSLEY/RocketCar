// Define os pinos
const int pinoEntrada = 8;  // Pino que recebe o sinal do ESP32
const int pinoSaida = A0;   // Pino que envia o pulso positivo

void setup() {
  pinMode(pinoEntrada, INPUT); // Configura o pino 8 como entrada
  pinMode(pinoSaida, OUTPUT);  // Configura o pino A0 como saída
  digitalWrite(pinoSaida, LOW); // Inicializa o pino A0 em LOW
}

void loop() {
  // Lê a tensão no pino de entrada
  int valorEntrada = digitalRead(pinoEntrada);

  // Se o valor lido for HIGH, o Arduino interpretará como 3.3V
  if (valorEntrada == HIGH) {
    digitalWrite(pinoSaida, HIGH); // Envia o pulso positivo no A0
  }
  else{
    digitalWrite(pinoSaida,LOW);
  }
  delay(1); // Evita que o loop se execute muito rápido
}
