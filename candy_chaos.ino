#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// initializarea lcd-ului cu adresa 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myServo;

// definirea pinilor
const int redButtonPin = A0;
const int redLEDPin = 5;

const int blueButtonPin = A1;
const int blueLEDPin = 3;
const int servoPin = 10;
const int buzzerPin = 8; 


void setup() {
  Serial.begin(9600);
  
  lcd.begin();
  lcd.backlight();
  
  // setarea celor 2 butoane ca input
  pinMode(redButtonPin, INPUT);
  pinMode(blueButtonPin, INPUT);
  
  // setarea ledurilor ca output
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  // setarea buzzerului ca output
  pinMode(buzzerPin, OUTPUT);
  

  myServo.attach(servoPin);
  myServo.write(90); 
  
  // printarea de bun venit pe ecran
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Candy Chaos");
  lcd.setCursor(0, 1);
  lcd.print("(=˃ᆺ˂=)");
  delay(2000);
  lcd.clear();
}

void loop() {
  int redButtonState = digitalRead(redButtonPin);
  int blueButtonState = digitalRead(blueButtonPin);

  lcd.setCursor(0, 0);
  lcd.print("Choose candy: ");
  
  if (redButtonState == HIGH) {
    digitalWrite(redLEDPin, HIGH);
    
    // se roteste servomotorul pentru a putea impinge bomboana
    myServo.write(180); // 90 + 120 degrees
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Loading red...");
    delay(2000);
    
    digitalWrite(redLEDPin, LOW);
    
    // mutam servomotorul in pozitia initiala
    myServo.write(90);
    delay(1000);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Take your red");
    lcd.setCursor(0, 1);
    lcd.print("candies! ^_^");

    // se porneste buzzerul pentru a semnala ca se poate lua bomboana
    digitalWrite(buzzerPin, HIGH); 
    delay(100); 
    digitalWrite(buzzerPin, LOW);
    
    delay(5000);
 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Choose candy");
  }
  
  if (blueButtonState == HIGH) {
    
      digitalWrite(blueLEDPin, HIGH);
      
      // se roteste servomotorul pentru a putea impinge bomboana
      myServo.write(-60); // 90 - 120 degrees
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Loading blue...");
      delay(2000);
      
      digitalWrite(blueLEDPin, LOW);
      
      // aducem servomotorul in pozitia initiala
      myServo.write(90);
      delay(1000); 
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Take your blue");
      lcd.setCursor(0, 1);
      lcd.print("candies! ^_^");

      // pornim buzzerul
      digitalWrite(buzzerPin, HIGH); 
      delay(100); 
      digitalWrite(buzzerPin, LOW);
      
      delay(5000);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Choose candy");
  }
}
