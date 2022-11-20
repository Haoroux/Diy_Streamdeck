//The used librairies

#include <Keyboard.h>

//les pins des switchs
const int ctrlCButtonPin = 2;
const int ctrlVButtonPin = 3;
const int modButtonPin = 4;

//états des switchs
int ctrlCButtonState = 0;
int ctrlVButtonState = 0;
int modButtonState = 0;

//selected mod
int modSelect = 0;

void setup() 
{
  pinMode(ctrlCButtonPin, INPUT_PULLUP);
  pinMode(ctrlVButtonPin, INPUT_PULLUP);
  pinMode(modButtonPin, INPUT_PULLUP);
}

void loop() 
{
  ctrlCButtonState = !digitalRead(ctrlCButtonPin);
  ctrlVButtonState = !digitalRead(ctrlVButtonPin); 
  modButtonState = !digitalRead(modButtonPin); 
  

  if (modButtonState == 1)
  {
    modSelect = modSelect + 1;
    delay(400);
    Serial.println(modSelect);
  }
  //for profile1
  if (modSelect == 0)
  {
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

  //for profile2
  if (modSelect == 1)
  {
    //control V
    if (ctrlVButtonState == 1)
    {
      windowsDfunc();
    }

    //control C
    if (ctrlCButtonState == 1)
    {
      ctrlZFunc();
    }
  
  }
  if (modSelect == 2)
  {
    modSelect = 0;
  }
}

//profile1
void ctrlCFunc()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("c");
  Keyboard.releaseAll();
  delay(400);
  return(0);
}

void ctrlVFunc()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("v");
  Keyboard.releaseAll();
  delay(400);
  return(0);
}

//profile 2
void windowsDfunc()
{
  Keyboard.press(KEY_RIGHT_GUI);
  Keyboard.print("d");
  Keyboard.releaseAll();
  delay(400);
  return(0);
}

void ctrlZFunc()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("z");
  Keyboard.releaseAll();
  delay(400);
  return(0);
}
