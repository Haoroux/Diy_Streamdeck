//libs
#include <Keyboard.h>

//var
//pins
const int numBtns = 14;
const int btnsPinsList[numBtns] = {1,0,2,3,4,5,6,7,8,9,10,16,14,15};
int prevStates[numBtns];

//shortcuts
struct KeyMapping {
  bool ctrl;
  bool shift;
  bool win;
  bool alt;
  uint8_t fn;
  String command;
};
//ctrl(true/false), shift(true/false),win(true/false),alt(true/false),fn(0/KEY_Fnumber),command(txt/"")
KeyMapping keyMapping[numBtns] = {
  {false,false,false,false,0,"0"},
  {false,false,false,false,0,"1"},
  {false,false,false,false,0,"2"}, 
  {false,false,false,false,0,"3"}, 
  {false,false,false,false,0,"4"}, 
  {false,false,false,false,0,"5"}, 
  {false,false,false,false,0,"6"}, 
  {false,false,false,false,0,"7"}, 
  {false,false,false,false,0,"8"}, 
  {false,false,false,false,0,"9"}, 
  {false,false,false,false,0,"10"},
  {false,false,false,false,0,"11"},
  {false,false,false,false,0,"12"},
  {false,false,false,false,0,"13"}
};

//functions
void setup() {
  for(int i=0;i<numBtns; i++){
    pinMode(btnsPinsList[i], INPUT_PULLUP);
    prevStates[i] = HIGH;
  }

}

void loop() {
  for(int i=0;i<numBtns; i++){
    int curStates = digitalRead(btnsPinsList[i]);
    // put your main code here, to run repeatedly:
    if (prevStates[i] == HIGH && curStates == LOW){
      shortCutsFunc(keyMapping[i]);
    }
    prevStates[i] = curStates;
  }

}

void shortCutsFunc(KeyMapping mapping){
  if (mapping.ctrl == true){
    Serial.println("control");
    Keyboard.press(KEY_LEFT_CTRL);
  }
  if (mapping.alt == true){
    Serial.println("alt");
    Keyboard.press(KEY_LEFT_ALT);
  }
  if (mapping.win == true){
    Serial.println("win");
    Keyboard.press(KEY_LEFT_GUI);
  }
  if (mapping.shift == true){
    Serial.println("shift");
    Keyboard.press(KEY_LEFT_SHIFT);
  }
  if (mapping.fn != 0) {  // Si une touche spéciale est définie (comme KEY_F3)
    Serial.println("funtion");
    Keyboard.press(mapping.fn);
  } 
  Keyboard.print(mapping.command);  // Imprime la commande (par ex. "1")
  Keyboard.releaseAll();
}
