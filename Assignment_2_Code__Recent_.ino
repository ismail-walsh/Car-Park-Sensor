//Assesment 2 Car Park System

const int latchPin = 9;
const int clockPin = 10;
const int dataPin = 8;
const int buttonPin = 7;
const int buttonPin2 = 11;
const int green = 5;
const int red = 6;
const int blue = 3;

int buzzer =12;

float Colour = 0;

int dig1 = 2;
int dig2 = 4;

/*
  1 = decimal
  2 = bottom
  3 = bottom-right
  4 = middle
  5 = top-right
  6 = top-left
  7 = bottom-left
  8 = top
*/


typedef unsigned char uchar;

const uchar DECI = 0x01;
const uchar BOTT = 0x80;
const uchar BOTR = 0x20;
const uchar MIDD = 0x02;
const uchar TOPR = 0x10;
const uchar TOPL = 0x08;
const uchar BOTL = 0x40;
const uchar TOPP = 0x04;

const uchar DIGITS[10] = {
  TOPP | TOPL | TOPR | BOTT | BOTL | BOTR, // 0
  TOPR | BOTR, // 1
  TOPP | MIDD | BOTT | TOPR | BOTL, // 2
  TOPP | MIDD | BOTT | TOPR | BOTR, // 3
  TOPL | MIDD | TOPR | BOTR, // 4
  TOPP | MIDD | BOTT | TOPL | BOTR, // 5
  TOPP | MIDD | BOTT | TOPL | BOTR | BOTL, // 6
  TOPP | TOPR | BOTR, // 7
  TOPP | MIDD | BOTT | TOPL | BOTL | TOPR | BOTR, // 8
  TOPP | MIDD | BOTT | TOPL | TOPR | BOTR // 9
  
};

const uchar FULL[1] = {
  TOPP | TOPL | MIDD | BOTL  // F
  };



void setup(void)
{
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  
  pinMode(buzzer, OUTPUT);
  
  pinMode(latchPin,  OUTPUT);
  pinMode(clockPin,  OUTPUT);
  pinMode(dataPin,   OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  putByte(DIGITS[0]);
  
  pinMode(dig2, OUTPUT);
  pinMode(dig1, OUTPUT);
  Serial.begin(9600);
  
 
}

int buttonCheck(void)
{
  // Button will be HIGH when not pressed

  if (digitalRead(buttonPin))
  {
    return 0; 
  }
  else
  {
    // Wait for button release
    while (digitalRead(buttonPin) == LOW) /* nothing */ ;
    delay(1); // debounce
    return 1;       
  }
}


int buttonCheck2(void)
{
  // Button 2 will be HIGH when not pressed.

  if (digitalRead(buttonPin2))
  {
    return 0; 
  }
  else
  {
    // Wait for button release
    while (digitalRead(buttonPin2) == LOW) /* nothing */ ;
    delay(1); // debounce
    return 1;       
  }
}

void putByte(byte dig1)
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, dig1);
    digitalWrite(latchPin, HIGH); 
}

void playTone(int tone, int duration)
{
  int start = millis();
  while ((millis() - start) < duration)
  {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(tone);
  }
}

void loop(void)
{
  char buffer[100];
  static int disp2 = 0;
  static int disp1 = 0;
  
  if (buttonCheck())
  {
    disp1 = (disp1 + 1) % 10;
    playTone(1915, 50); // beep when counting
  
  if (disp1==0)
  {
    disp2 = (disp2 + 1) % 10;
    playTone(1915, 50);
  }    
  else 
  { 
    disp2 = disp2;
  }
 
   } 
    
  if (disp1 >= 8 & disp2 == 1) //RBG Orange when count is greater than 18
   {
    analogWrite(green, 50);
    analogWrite(red, 238);
    analogWrite(blue, 17);
   }
 
  if (disp2 == 0) //RGB Green when count is < 10
  {
    analogWrite(green, 255);
    analogWrite(red, 51);
    analogWrite(blue, 51);
  }   

  if (disp2 >= 2) //RGB Red when full
  {
      
    analogWrite(green, 6);
    analogWrite(red, 255);
    analogWrite(blue, 22);
    digitalWrite(dig2,LOW);
    digitalWrite(dig1, HIGH);
    putByte(FULL[disp2]); // display F when full
    delay(12);
    digitalWrite(dig2, HIGH);
    digitalWrite(dig1, LOW);
    putByte(FULL[disp1]);
    delay(12);
    Serial.println("**NO SPACES AVAILABLE**"); // record no spaces available when carpark is 
    
  if (buttonCheck2())
  {
    disp1 = 9;
    disp2 = 1;
       
  }
   }
   
  else 
  {
    digitalWrite(dig2,LOW);
    digitalWrite(dig1, HIGH);
    putByte(DIGITS[disp2]);
    delay(12);
    digitalWrite(dig2, HIGH);
    digitalWrite(dig1, LOW);
    putByte(DIGITS[disp1]);
    delay(12);
  }

  if (buttonCheck2())
  {
    playTone(1915, 50);
    disp1 = (disp1 - 1) % 10; // count backwards
    
  if (disp1<0 & disp2 == 1)
  {
    playTone(1915, 50);
    disp2 = 0;
    delay(12);
    disp1 = 9;
    return;
  }
  if ((disp1<0))
  {
    playTone(956, 100); //malfuntion alarm as the system is recording a car leaving when the number is zero, therefore, there is an error. Alarm, goes off.
    Serial.println("**ERROR, RESET DEVICE**");
    disp2 = 0;
    disp1 = 0;
    return;
  }    
 
  else 
  { 
    disp2 = disp2;
    digitalWrite(dig2,LOW);
    digitalWrite(dig1, HIGH);
    putByte(DIGITS[disp2]);
    digitalWrite(dig2, HIGH);
    digitalWrite(dig1, LOW);
    putByte(DIGITS[disp1]);
    return;
  }

  }
  }


 
