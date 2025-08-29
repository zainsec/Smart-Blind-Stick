const int buttonPin = 2;       // the number of the pushbutton pin
const int ledPin = 11;         // the number of the LED pin
const int buzzerPin = 12;      // the number of the buzzer pin
const int irProximityPin = 13; // the number of the IR proximity sensor pin
const int TRIGGER_PIN = 8;     // the number of the ultrasonic sensor trigger pin
const int ECHO_PIN = 9;        // the number of the ultrasonic sensor echo pin
const int vibrationMotorPin = 10; // the number of the vibration motor pin
const int lm35Pin = A0;         // Analog pin to which LM35 sensor is connected
int buttonState = LOW;         // variable for reading the pushbutton status
int lastButtonState = LOW;     // variable to store the previous state of the button
bool arduinoOn = false;        // flag to track if Arduino is on or off
bool melodyPlayed = false;     // flag to track if the welcome melody has been played

void setup() {
  pinMode(buttonPin, INPUT);         // initialize the pushbutton pin as an input
  pinMode(ledPin, OUTPUT);           // initialize the LED pin as an output
  pinMode(buzzerPin, OUTPUT);        // initialize the buzzer pin as an output
  pinMode(irProximityPin, INPUT);    // initialize the IR proximity sensor pin as an input
  pinMode(TRIGGER_PIN, OUTPUT);      // initialize the ultrasonic sensor trigger pin as an output
  pinMode(ECHO_PIN, INPUT);          // initialize the ultrasonic sensor echo pin as an input
  pinMode(vibrationMotorPin, OUTPUT);// initialize the vibration motor pin as an output
  digitalWrite(ledPin, LOW);          // turn off the LED initially
  digitalWrite(buzzerPin, LOW);       // turn off the buzzer initially
  digitalWrite(vibrationMotorPin, LOW);// turn off the vibration motor initially
}

void loop() { 
buttonState = digitalRead(buttonPin); // read the state of the pushbutton value

  if (buttonState != lastButtonState) { // HOLD THE BUTTON TO WORK
    if (buttonState == HIGH) {
      arduinoOn = !arduinoOn;  // Toggle the state of arduinoOn
      digitalWrite(ledPin, arduinoOn ? HIGH : LOW);  // Turn on/off the LED based on arduinoOn state
      if (arduinoOn) {
        // Welcome melody
        if (!melodyPlayed) {
          tone(buzzerPin, 330, 200); // E4
          delay(250);
          tone(buzzerPin, 392, 200); // G4
          delay(250);
          tone(buzzerPin, 440, 200); // A4
          delay(250);
          tone(buzzerPin, 330, 200); // E4
          delay(250);
          tone(buzzerPin, 392, 200); // G4
          delay(250);
          tone(buzzerPin, 440, 200); // A4
          delay(250);
          tone(buzzerPin, 494, 300); // B4
          delay(350);
          tone(buzzerPin, 523, 300); // C5
          delay(350);
          tone(buzzerPin, 587, 400); // D5
          delay(450);
          tone(buzzerPin, 659, 500); // E5
          delay(550);
          melodyPlayed = true; // Set the flag to indicate that the melody has been played
        }
      } else {
        noTone(buzzerPin); // Turn off the buzzer
        digitalWrite(vibrationMotorPin, LOW); // Turn off the vibration motor
      }
    }
    delay(50);  // Debounce delay
  }

  lastButtonState = buttonState;  // Save the current button state for comparison
  
bool objectDetected = digitalRead(irProximityPin);

  if (objectDetected) {
    noTone(buzzerPin);
    digitalWrite(vibrationMotorPin, LOW); // Turn off the vibration motor
  } else {
    longBeep();
    digitalWrite(vibrationMotorPin, HIGH); // Turn on the vibration motor
  }

  Serial.print("IR Proximity Sensor Status: ");
  Serial.println(objectDetected);

  long duration, distance;
  
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 40) {
    if (distance > 30) {
      beep(500);
    } else if (distance <= 30 && distance > 20) {
      beep(300);
    } else if (distance <= 20 && distance > 10) {
      beep(100);
    } else if (distance <= 10) {
      longBeep();
    }
    digitalWrite(vibrationMotorPin, HIGH); // Turn on the vibration motor
  }
  else {
    noTone(buzzerPin);
    digitalWrite(vibrationMotorPin, LOW); // Turn off the vibration motor
  }
  
  // Read LM35 Temperature Sensor
  int sensorValue = analogRead(lm35Pin);
  float temperatureC = ((sensorValue * 5.0 * 100.0) / 1024)- 49; // Convert analog value to temperature in Celsius

  // Temperature-based Logic
  if (temperatureC > 40) // Makes sound with buzzer and vibrates when it reaches 40 degree 
  {
    // Add actions based on temperature threshold, e.g., activate buzzer or vibration motor
    beep(200); // Example: activate buzzer for 200ms
    digitalWrite(vibrationMotorPin, HIGH); // Turn on the vibration motor
  }
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(500);
}

void beep(int duration) {
  tone(buzzerPin, 1000, duration);
  delay(duration);
  noTone(buzzerPin);
}

void longBeep() {
  tone(buzzerPin, 1000);
  delay(1000);
  noTone(buzzerPin);
}