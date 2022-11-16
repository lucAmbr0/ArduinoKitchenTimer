// Arduino Kitchen Timer
// https://github.com/lucAmbr0/
// Created by @luca.ambroo_ [instagram]
// 11/14/2022

// Libraries
#include <LiquidCrystal.h> // including the library for the LCD display
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Variables
#define RED 5
#define BLUE 6
#define CONFIRM 2
#define PLUS 3
#define MINUS 4
#define BUZZER 13

int Hrs;
int Min;
int Sec;
int timeleft;
int a; // variables a,b,c are for later
int b;
int c;

void setup() {
  Serial.begin(9600); // Starting the serial monitor
  pinMode(CONFIRM, INPUT_PULLUP); // declaring the pinModes
  pinMode(PLUS, INPUT_PULLUP);
  pinMode(MINUS, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  lcd.begin(16, 2);
  Serial.println("");
  Serial.println("--- Kitchen Timer ---"); // program title
  Serial.println("code by @luca.ambroo_"); // credits, please don't remove
  Serial.println("_____________________");
  lcd.print("Kitchen Timer"); // program title
  lcd.setCursor(0, 1);
  delay(500);
  lcd.print("by luca.ambroo_");  // credits, please don't remove
  delay(750);
  lcd.clear();
}

void loop() {
  lcd.clear();
SETTINGS:
  Serial.println("SETTINGS");
  lcd.clear();
  lcd.print("Hrs  Min  Sec");
  lcd.setCursor(0, 1);
  lcd.print("00   00   00");
  lcd.blink(); // blink to show the user which measure is being edited
HOURS: // here are the commands to set the hours for the timer
  lcd.setCursor(2, 1);
  if (digitalRead(PLUS) == LOW) {
    if (Hrs >= 23)
      goto HOURS; // maximum hours is 23
    Hrs++;
    Serial.print("+1h | ");
    Serial.print(Hrs); // updating serial monitor with time remaining
    Serial.print("h ");
    Serial.print(Min);
    Serial.print("m ");
    Serial.print(Sec);
    Serial.println("s ");
    if (Hrs >= 10) { // if hours are 10 or more, adjust the margin from left
      lcd.setCursor(0, 1);
      lcd.print(Hrs);
    } else {
      lcd.setCursor(0,1);
      lcd.print("0");
      lcd.setCursor(1, 1);
      lcd.print(Hrs);
    }
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(75); // a short feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
  } else if (digitalRead(MINUS) == LOW) {
    if (Hrs > 0) {
      Hrs--; }
    Serial.print("-1h | ");
    Serial.print(Hrs); // updating serial monitor with time remaining
    Serial.print("h ");
    Serial.print(Min);
    Serial.print("m ");
    Serial.print(Sec);
    Serial.println("s ");
    if (Hrs >= 10) {
      lcd.setCursor(0, 1);
      lcd.print(Hrs);
    } else if (Hrs < 0) {
      Hrs = 0; // this part is to prevent the lcd to display numbers smaller than 0
    } else if (Hrs < 10) {
      lcd.setCursor(0,1);
      lcd.print("0");
      lcd.setCursor(1, 1);
      lcd.print(Hrs);
    }
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(75); // a short feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
  } else if (digitalRead(CONFIRM) == LOW) {
    Serial.println("HRS CONFIRMED");
    lcd.setCursor(7,1);
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(150); // a long feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
    goto MINUTES; } // going to set the minutes for the timer
  goto HOURS;
MINUTES: // here are the commands to set the minutes for the timer
    lcd.setCursor(7, 1);
  if (digitalRead(PLUS) == LOW) {
    if (Min >= 59)
      goto MINUTES; // maximum miuntes is 59
    Min++;
    Serial.print("+1m | ");
    Serial.print(Hrs); // updating serial monitor with time remaining
    Serial.print("h ");
    Serial.print(Min);
    Serial.print("m ");
    Serial.print(Sec);
    Serial.println("s ");
    if (Min >= 10) { // if minutes are 10 or more, adjust the margin from left
      lcd.setCursor(5, 1);
      lcd.print(Min);
    } else {
      lcd.setCursor(5,1);
      lcd.print("0");
      lcd.setCursor(6, 1);
      lcd.print(Min);
    }
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(75); // a short feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
  } else if (digitalRead(MINUS) == LOW) {
    if (Min > 0) {
      Min--; }
    Serial.print("-1m | ");
    Serial.print(Hrs); // updating serial monitor with time remaining
    Serial.print("h ");
    Serial.print(Min);
    Serial.print("m ");
    Serial.print(Sec);
    Serial.println("s ");
    if (Min >= 10) {
      lcd.setCursor(5, 1);
      lcd.print(Min);
    } else if (Min < 0) {
      Min = 0; // this part is to prevent the lcd to display numbers smaller than 0
    } else if (Min < 10) {
      lcd.setCursor(5,1);
      lcd.print("0");
      lcd.setCursor(6, 1);
      lcd.print(Min);
    }
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(75); // a short feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
  } else if (digitalRead(CONFIRM) == LOW) {
    Serial.println("MIN CONFIRMED");
    lcd.setCursor(7,1);
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(150); // a long feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
    goto SECONDS; }
  goto MINUTES;
SECONDS: // here are the commands to set the seconds for the timer
  lcd.setCursor(12, 1);
  if (digitalRead(PLUS) == LOW) {
    if (Sec >= 59)
      goto SECONDS; // maximum seconds is 59
    Sec++;
    Serial.print("+1s | ");
    Serial.print(Hrs); // updating serial monitor with time remaining
    Serial.print("h ");
    Serial.print(Min);
    Serial.print("m ");
    Serial.print(Sec);
    Serial.println("s ");
    if (Sec >= 10) { // if seconds are 10 or more, adjust the margin from left
      lcd.setCursor(10, 1);
      lcd.print(Sec);
    } else {
      lcd.setCursor(10,1);
      lcd.print("0");
      lcd.setCursor(11, 1);
      lcd.print(Sec);
    }
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(75); // a short feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
  } else if (digitalRead(MINUS) == LOW) {
    if (Sec > 0) {
      Sec--; }
    Serial.print("-1s | ");
    Serial.print(Hrs); // updating serial monitor with time remaining
    Serial.print("h ");
    Serial.print(Min);
    Serial.print("m ");
    Serial.print(Sec);
    Serial.println("s ");
    if (Sec >= 10) {
      lcd.setCursor(10, 1);
      lcd.print(Sec);
    } else if (Sec < 0) {
      Sec = 0; // this part is to prevent the lcd to display numbers smaller than 0
    } else if (Sec < 10) {
      lcd.setCursor(10,1);
      lcd.print("0");
      lcd.setCursor(11, 1);
      lcd.print(Sec);
    }
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(75); // a short feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
  } else if (digitalRead(CONFIRM) == LOW) {
    Serial.println("SEC CONFIRMED");
    lcd.setCursor(12,1);
    delay(100);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(150); // a long feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    digitalWrite(RED, LOW);
    goto TIMER; } // going to display the time chose by the user
  goto SECONDS;

TIMER:
  Serial.println("TIMER IS STARTING");
  lcd.noBlink();
  digitalWrite(RED, LOW);
  digitalWrite(BUZZER, HIGH);
  delay(500); // a long feedback to the user with the red led and buzzer
  digitalWrite(BUZZER, LOW);
  digitalWrite(BLUE, HIGH);
  lcd.clear();
  delay(200);
  lcd.print("REMAINING TIME:");
  Serial.println("TIMER STARTED");
  Sec++;
  goto REMAINING;

REMAINING:
  delay(1000);
  if (Sec > 0) { // here's the whole algorithm to convert hrs-min-sec
    a = 0; } // this string is useless
  else { // if seconds are 0 than take 1 from minutes and make seconds 60
    if (Min > 0) {
      a = 0; } // this string is useless
    else { // if minutes are 0 than take 1 from hours and make minutes 60
      if (Hrs > 0) {
        a = 0; } // this string is useless
      else { goto END; } // if even hours are 0, than the countdown has finished.
    Hrs--;
    Min = 60;
    }
    Min--;
    Sec = 60;
  }
  Sec--;
  lcd.setCursor(0, 1);
  if (Hrs >= 10) { // adjusting margins if numbers are >=10
    lcd.setCursor(0,1); }
  else {
    lcd.setCursor(0,1);
    lcd.print("0");
    lcd.setCursor(1,1); }
  lcd.print(Hrs);
  lcd.print("h");
  if (Min >= 10) { // adjusting margins if numbers are >=10
    lcd.setCursor(5,1); }
  else {
    lcd.setCursor(5, 1);
    lcd.print("0");
    lcd.setCursor(6,1); }
  lcd.print(Min);
  lcd.print("m");
  if (Sec >= 10) { // adjusting margins if numbers are >=10
    lcd.setCursor(10,1);
  }
  else {
    lcd.setCursor(10, 1);
    lcd.print("0");
    lcd.setCursor(11, 1);
  }
  lcd.print(Sec);
  lcd.print("s");

  if (digitalRead(CONFIRM) == LOW) { // cancelling the timer if you push confirm while the countdown is working
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(250); // feedback to the user with the red led and buzzer
    digitalWrite(BUZZER, LOW);
    Hrs = 0; // making every measure = 0 to reset the timer
    Min = 0;
    Sec = 0;
    lcd.clear();
    Serial.println("Cancelled.");
    delay(1250);
    digitalWrite(RED, LOW);
    goto SETTINGS; // goes back the timer settings
  }
  Serial.print(Hrs); // updating serial monitor with time remaining
  Serial.print("h ");
  Serial.print(Min);
  Serial.print("m ");
  Serial.print(Sec);
  Serial.println("s ");
  goto REMAINING; // updates the lcd display with time remaining
END:
  lcd.clear();
  lcd.print("TIME FINISHED "); // time has finished!
  Serial.println("TIME FINISHED");
  lcd.setCursor(0,1);
  lcd.print("FOOD IS READY!");
  digitalWrite(BLUE, LOW);
  b = 0; // repeating the buzzer and led warning until user pushes CONFIRM to reset
  while (b == 0) {
    digitalWrite(RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(250);
    digitalWrite(RED, LOW);
    digitalWrite(BUZZER, LOW);
    delay(150);
    if (digitalRead(CONFIRM) == LOW) {
      b = 1; // stops the buzzer and led warning
    }
  }
  lcd.clear();
  lcd.print("Restarting...");
  Serial.println("Restarting...");
  lcd.setCursor(0,1);
  c = 0;
  while (c < 16) { // displays a short loading before restarting the timer
    lcd.print(">");
    c++;
    delay(150);
  }
  lcd.clear();
  delay(250);
}

//
//              _..._
//            .'     '.      _
//           /    .-""-\   _/ \
//         .-|   /:.   |  |   |
//         |  \  |:.   /.-'-./
//         | .-'-;:__.'    =/
//         .'=  *=|     _.='
//        /   _.  |    ;
//       ;-.-'|    \   |     @luca.ambroo__
//      /   | \    _\  _\
//      \__/'._;.  ==' ==\
//              \    \   |
//              /    /   /
//             /-._/-._/
//             \   `\  \
//              `-._/._/
//
