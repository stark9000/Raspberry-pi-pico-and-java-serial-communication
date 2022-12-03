int LED_1 = 2;
int LED_2 = 3;
int LED_3 = 4;
int LED_4 = 5;
int LED_5 = 6;
int LED_6 = 7;
int LED_7 = 8;
int LED_8 = 9;

int BUZZER = 10;
int RELAY = 11;

char RX_CHAR;
String RX_STRING = "";

unsigned long previousMillis = 0;
const long interval = 100;

int LED = 25;

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(LED_8, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAY, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    RX_CHAR = Serial.read();
    if (RX_CHAR == '\r' ||  RX_CHAR == '\n') {
      ProcessData(RX_STRING);
    }
    RX_STRING = RX_STRING + RX_CHAR;
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Serial.println("this is from Raspberri PI Pico.");
  }
}

void ProcessData(String Data) {
  RX_STRING.trim();
  if (RX_STRING == "led1on") {
    digitalWrite(LED_1, HIGH);
  } else if (RX_STRING == "led1off") {
    digitalWrite(LED_1, LOW);
  }

  else if (RX_STRING == "led2on") {
    digitalWrite(LED_2, HIGH);
  } else if (RX_STRING == "led2off") {
    digitalWrite(LED_2, LOW);
  }

  else if (RX_STRING == "led3on") {
    digitalWrite(LED_3, HIGH);
  } else if (RX_STRING == "led3off") {
    digitalWrite(LED_3, LOW);
  }

  else if (RX_STRING == "led4on") {
    digitalWrite(LED_4, HIGH);
  } else if (RX_STRING == "led4off") {
    digitalWrite(LED_4, LOW);
  }

  else if (RX_STRING == "led5on") {
    digitalWrite(LED_5, HIGH);
  } else if (RX_STRING == "led5off") {
    digitalWrite(LED_5, LOW);
  }

  else if (RX_STRING == "led6on") {
    digitalWrite(LED_6, HIGH);
  } else if (RX_STRING == "led6off") {
    digitalWrite(LED_6, LOW);
  }

  else if (RX_STRING == "led7on") {
    digitalWrite(LED_7, HIGH);
  } else if (RX_STRING == "led7off") {
    digitalWrite(LED_7, LOW);
  }

  else if (RX_STRING == "led8on") {
    digitalWrite(LED_8, HIGH);
  } else if (RX_STRING == "led8off") {
    digitalWrite(LED_8, LOW);
  }

  else if (RX_STRING == "buzzeron") {
    digitalWrite(BUZZER, HIGH);
  } else if (RX_STRING == "buzzeroff") {
    digitalWrite(BUZZER, LOW);
  }

  else if (RX_STRING == "relayon") {
    digitalWrite(RELAY, HIGH);
  } else if (RX_STRING == "relayoff") {
    digitalWrite(RELAY, LOW);
  }
  RX_STRING = "";
}
