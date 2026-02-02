void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("=== UART2 Loopback Test ===");

  String testMsg = "UART_TEST";

  // Send test message
  Serial.println("Sending test message...");
  Serial2.println(testMsg);

  delay(200); // wait for loopback

  if (Serial2.available()) {
    String rx = Serial2.readStringUntil('\n');
    rx.trim();

    Serial.print("Received: ");
    Serial.println(rx);

    if (rx == testMsg) {
      Serial.println("UART LOOPBACK: PASS");
    } else {
      Serial.println("UART LOOPBACK: FAIL");
    }
  } else {
    Serial.println("UART LOOPBACK: FAIL");
  }
}

void loop() {
  // Nothing here — one-shot automated test
}