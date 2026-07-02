int ledPin = 2;
int speedDelay = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  Serial.println("===== LED Blink Control =====");
  Serial.println("1 = Blink every 2 seconds");
  Serial.println("2 = Blink every 1 second");
  Serial.println("3 = Blink every 0.5 second");
  Serial.println("0 = Stop");
}

void loop() {

  if (Serial.available() > 0) {

    String value = Serial.readStringUntil('\n');
    value.trim();

    int num = value.toInt();

    if (num == 1) {
      speedDelay = 2000;
      Serial.println("Blink every 2 seconds");
    }
    else if (num == 2) {
      speedDelay = 1000;
      Serial.println("Blink every 1 second");
    }
    else if (num == 3) {
      speedDelay = 500;
      Serial.println("Blink every 0.5 second");
    }
    else if (num == 0) {
      speedDelay = 0;
      digitalWrite(ledPin, LOW);
      Serial.println("Stop");
    }
    else {
      Serial.println("Invalid command! Enter 0, 1, 2, or 3.");
    }
  }

  if (speedDelay > 0) {
    digitalWrite(ledPin, HIGH);
    delay(speedDelay);

    digitalWrite(ledPin, LOW);
    delay(speedDelay);
  }
}