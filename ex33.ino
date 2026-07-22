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
  }

  if (command == "RED") {

    allOff();
    digitalWrite(redPin, HIGH);

  }
  else if (command == "GREEN") {

    allOff();

    for (int i = 0; i < 2; i++) {
      digitalWrite(greenPin, HIGH);
      delay(50);
      digitalWrite(greenPin, LOW);
      delay(50);
    }

    delay(2000);

  }
  else if (command == "YELLOW" || command == "BLUE") { 

    allOff();

    for (int i = 0; i < 3; i++) {
      digitalWrite(bluePin, HIGH);
      delay(50);
      digitalWrite(bluePin, LOW);
      delay(50);
    }

    delay(1000);

  }
  else if (command == "NONE" || command == "OFF") { 

    allOff();
    command = "";

  }
}

void allOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}