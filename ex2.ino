#define LED_PIN 2

String command = "";
int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {

  // รับคำสั่งจาก Python
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');
    command.trim();

    if (command.equalsIgnoreCase("RED")) {
      mode = 1;
    }
    else if (command.equalsIgnoreCase("GREEN")) {
      mode = 2;
    }
    else if (command.equalsIgnoreCase("BLUE")) {
      mode = 3;
    }
    else if (command.equalsIgnoreCase("OFF")) {
      mode = 0;
      digitalWrite(LED_PIN, LOW);
    }
  }

  if (mode == 1) {
    
    digitalWrite(LED_PIN, HIGH);
  }

  else if (mode == 2) {
    
    for (int i = 0; i < 2; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(200);
      digitalWrite(LED_PIN, LOW);
      delay(200);
    }
    delay(5000);
  }

  else if (mode == 3) {
    
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(200);
      digitalWrite(LED_PIN, LOW);
      delay(200);
    }
    delay(5000);
  }

  else {
    digitalWrite(LED_PIN, LOW);
  }
}