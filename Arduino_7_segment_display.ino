#include "math.h"

//4 digit 7 seg pins and what each stands for:
//12,9,8,6 -> Power
//1- E
//2- D
//4- C
//5- G
//7- B
//10- F
//11- A
//3 - decimal point

int pinA = 4; //7-SEG-PIN 11    A
int pinB = 5; //7-SEG-PIN 7     B
int pinC = 6; //7-SEG-PIN 4     C
int pinD = 7; //7-SEG-PIN 2     D
int pinE = 8; //7-SEG-PIN 1     E
int pinF = 9; //7-SEG-PIN 10    F
int pinG = 10; //7-SEG-PIN 5     G
int D1 = 11; //7-SEG-PIN 12      D1
int D2 = 12; //7-SEG-PIN 9      D2
int D3 = 13; //7-SEG-PIN 8      D3
int D4 = A0; //7-SEG-PIN 6      D4
int pinDecimal = A1;
//7-SEG-PIN 3     Decimal point

int distanceDisplay[] = {8, 8, 8, 4};             
int echoPin = 2; //attach pin D2 of Arduino to pin Echo of HC-SR04(Ultrasonic proximity sensor)
int trigPin = 3; //attach pin D3 of Arduino to pin Trig of HC-SR04


void setup() {
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(pinDecimal, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);  //Serial communication is starting with 9600 of baudrate speed
}


void loop() {
  sevenSegDisplay();
  checkDistance(); //COULD HAVE AN EFFECT ON 7 SEG DISPLAY COZ OF THE DELAYS
}

void sevenSegDisplay() {
  showFirstDigit();
  displayDigit(distanceDisplay[0], false);
  delay(1);  ///1 MS is standard time between displaying of digits(Multiplexing)

  showSecondDigit();
  displayDigit(distanceDisplay[1], true);
  delay(1);
//
  showThirdDigit();
  displayDigit(distanceDisplay[2], false);
  delay(1);

  showFourthDigit();
  displayDigit(distanceDisplay[3], false);
  delay(1);

}

void showFirstDigit() { //D1
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}
void showSecondDigit() { //D2
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}
void showThirdDigit() { //D3
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}
void showFourthDigit() { //D4
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
}
void displayDigit(int digit, bool isSecondDigit) {
  if (digit == 0) {showNumber0(isSecondDigit);}
  if (digit == 1) {showNumber1(isSecondDigit);}
  if (digit == 2) {showNumber2(isSecondDigit);}
  if (digit == 3) {showNumber3(isSecondDigit);}
  if (digit == 4) {showNumber4(isSecondDigit);}
  if (digit == 5) {showNumber5(isSecondDigit);}
  if (digit == 6) {showNumber6(isSecondDigit);}
  if (digit == 7) {showNumber7(isSecondDigit);}
  if (digit == 8) {showNumber8(isSecondDigit);}
  if (digit == 9) {showNumber9(isSecondDigit);}
}

void showNumber0(bool isSecondDigit) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber1(bool isSecondDigit) {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber2(bool isSecondDigit) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber3(bool isSecondDigit) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber4(bool isSecondDigit) {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber5(bool isSecondDigit) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber6(bool isSecondDigit) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber7(bool isSecondDigit) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber8(bool isSecondDigit) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void showNumber9(bool isSecondDigit) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  if (isSecondDigit) digitalWrite(pinDecimal, LOW);
  else digitalWrite(pinDecimal, HIGH);
}
void reset(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void checkDistance() {
  digitalWrite(trigPin, LOW); //Initially clears the trigPin condition
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  double duration = pulseIn(echoPin, HIGH); //Reads the Echo pin, and returns the time taken by the sound wave (in ms)
  double distance = (duration * 0.034) / 2.00; //Divide distance by 2 because of back and forth movement of waves,,0.034 is constant speed
  if (distance > 100.00) distance = 99.99;
  
  int a = distance * 100; //convert to int  //Example of a is 1234
  int first = a/1000;                //1
  int first_rem = a%1000;            //234
  int second = first_rem/100;        //2
  int second_rem = first_rem%100; //34
  int third = second_rem/10;         //3
  int third_rem = second_rem%10;  //4
  
  //change contents of array
  distanceDisplay[0] = first; 
  distanceDisplay[1] = second;
  distanceDisplay[2] = third;
  distanceDisplay[3] = third_rem;
}
