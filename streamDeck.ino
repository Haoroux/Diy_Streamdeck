//this code does not work

#include <Keyboard.h>

//The used librairies

//les pins des switchs
const int ctrlCButtonPin = 2;
const int ctrlVButtonPin = 3;
const int modButtonPin = 4;

//états des switchs
int ctrlCButtonState = 0;
int ctrlVButtonState = 0;
int modButtonState = 0;

//selected mod
int selectedMod = 0;
int baseMod = 0;
int firstMod = 1;
int secondMod = 2;

void setup() 
{
  pinMode(ctrlCButtonPin, INPUT_PULLUP);
  pinMode(ctrlVButtonPin, INPUT_PULLUP);
  pinMode(modButtonPin, INPUT_PULLUP);
}

void loop() 
{
  modButtonState = !digitalRead(modButtonPin);
  Serial.println(selectedMod);

  if (modButtonState == 1)
  {
    selectedModFunc();
  }
  
  if (selectedMod == 1)
  {
    mod1();
  }
}

int selectedModFunc()
{
  if (selectedMod == 0)
  {
    int selectedMod = firstMod;
    delay(500);
  }
  if (selectedMod == 1)
  {
    int selectedMod = baseMod;
    delay(500);
  }
}

void mod1()
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
