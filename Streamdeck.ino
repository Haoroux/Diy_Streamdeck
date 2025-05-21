#include <Keyboard.h>

const int numBtns = 14;
const int btnsPinsList[numBtns] = {1,0,2,3,4,5,6,7,8,9,10,16,14,15};
bool prevStates[numBtns];

// Raccourcis pour chaque bouton
struct KeyMapping {
  bool ctrl;
  bool shift;
  bool win;
  bool alt;
  uint8_t fn;
  String command;
};

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

void setup() {
  for (int i = 0; i < numBtns; i++) {
    pinMode(btnsPinsList[i], INPUT_PULLUP);
    prevStates[i] = true;
  }
  Keyboard.begin();
}

void loop() {
  bool anyKeyPressed = false;

  for (int i = 0; i < numBtns; i++) {
    bool curState = digitalRead(btnsPinsList[i]);

    if (curState == LOW && prevStates[i] == HIGH) {
      sendKey(keyMapping[i], true); // press
    }

    if (curState == HIGH && prevStates[i] == LOW) {
      sendKey(keyMapping[i], false); // release
    }

    prevStates[i] = curState;

    if (curState == LOW) {
      anyKeyPressed = true;
    }
  }

  if (!anyKeyPressed) {
    Keyboard.releaseAll();
  }
}

void sendKey(KeyMapping mapping, bool press) {
  if (press) {
    if (mapping.ctrl) Keyboard.press(KEY_LEFT_CTRL);
    if (mapping.alt) Keyboard.press(KEY_LEFT_ALT);
    if (mapping.win) Keyboard.press(KEY_LEFT_GUI);
    if (mapping.shift) Keyboard.press(KEY_LEFT_SHIFT);
    if (mapping.fn != 0) Keyboard.press(mapping.fn);
    if (mapping.command != "") {
      for (int i = 0; i < mapping.command.length(); i++) {
        Keyboard.press(mapping.command[i]);
      }
    }
  } else {
    Keyboard.releaseAll(); // Relâche tout quand on détecte un relâchement
  }
}
