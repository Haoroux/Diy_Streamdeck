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
KeyMapping keyMapping[numBtns] = {
  {false,false,false,false,KEY_F3,""},
  {false,false,false,false,KEY_F3,"g"},
  {false,false,false,false,false,"2"}, 
  {false,false,false,false,false,"3"}, 
  {false,false,false,false,false,"4"}, 
  {false,false,false,false,false,"5"}, 
  {false,false,false,false,false,"6"}, 
  {false,false,false,false,false,"7"}, 
  {false,false,false,false,false,"8"}, 
  {false,false,false,false,false,"9"}, 
  {false,false,false,false,false,"10"},
  {false,false,false,false,false,"11"},
  {false,false,false,false,false,"12"},
  {false,false,false,false,false,"13"}
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
    Keyboard.press(KEY_LEFT_CTRL);
  }
  if (mapping.alt == true){
    Keyboard.press(KEY_LEFT_GUI);
  }
  if (mapping.win == true){
    Keyboard.press(KEY_LEFT_SHIFT);
  }
  if (mapping.shift == true){
    Keyboard.press(KEY_LEFT_SHIFT);
  }
  if (mapping.fn != 0) {  // Si une touche spéciale est définie (comme KEY_F3)
    Keyboard.press(mapping.fn);
  } 
  Keyboard.print(mapping.command);  // Imprime la commande (par ex. "1")
    // Imprime la commande (par ex. "1")
  Keyboard.releaseAll();
}
