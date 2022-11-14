//The used librairies
#include <Keyboard.h>

//les pins des switchs
const int ctrlCButtonPin = 2;
const int ctrlVButtonPin = 3;

//états des switchs
int ctrlCButtonState = 0;
int ctrlVButtonState = 0;


void setup() 
{
  pinMode(ctrlCButtonPin, INPUT_PULLUP);
  pinMode(ctrlVButtonPin, INPUT_PULLUP);
}

void loop() 
{
  ctrlCButtonState = !digitalRead(ctrlCButtonPin);
  ctrlVButtonState = !digitalRead(ctrlVButtonPin);

//control V
if (ctrlVButtonState == 1)
  {
    ctrlVFunc();
  }

//control C
if (ctrlCButtonState == 1)
  {
    ctrlCFunc();
  }
}

void ctrlCFunc()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("c");
  Keyboard.releaseAll();
  delay(500);
  return(0);
}

void ctrlVFunc()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("v");
  Keyboard.releaseAll();
  delay(500);
  return(0);
}

//
