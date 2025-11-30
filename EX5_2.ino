// EX5_2  
// Bare-metal UART 115200 baud, 7E2

void uart_init() {

  UBRR0H = 0;  // Baud rate = 115200
  UBRR0L = 8;  // UBRR = (16MHz / (16 * 115200)) - 1 ≈ 8

  UCSR0B = (1 << TXEN0);   // TX Enable

  // UART Format: 7E2   ,   UCSZ01 = 1, UCSZ00 = 0 → 7-bit
  // UPM01 = 1, UPM00 = 0 → Even parity  ,  USBS0 = 1 → 2 stop bits
  UCSR0C = (1 << UPM01) | (1 << USBS0) | (1 << UCSZ01);
}

void uart_send(char data) {
  while (!(UCSR0A & (1 << UDRE0))); // Wait
  UDR0 = data;
}

void setup() {
  uart_init();
}

void loop() {
  const char msg[] = "Hello 7E2 Format!";
  for (int i = 0; msg[i] != 0; i++) {
    uart_send(msg[i]);
  }
  uart_send('\n');

  delay(1000);
}
