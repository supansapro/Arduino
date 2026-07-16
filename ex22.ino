int redPin = 13;
int greenPin = 12;
int bluePin = 14;

String command = "";

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  allOff();
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "RED") {
      allOff();
      digitalWrite(redPin, HIGH);  
      Serial.println("Red ON");
    }

    else if (command == "GREEN") {
      allOff();
      blinkLED(greenPin, 2);      
      Serial.println("Green Blink 2");
    }

    else if (command == "BLUE") {
      allOff();
      blinkLED(bluePin, 3);         
      Serial.println("Blue Blink 3");
    }

    else if (command == "OFF") {
      allOff();
      Serial.println("All OFF");
    }

    else {
      Serial.println("Unknown Command");
    }
  }
}

void blinkLED(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
    delay(300);
  }
}

void allOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}