/*
 * Created by Vlad Volokitin (volokitty)
 * https://github.com/volokitty/
*/

const uint8_t leds[] = {6, 7, 8, 9, 10, 11, 12, 13};
const uint8_t buttons[] = {2, 3};

bool isFirstButtonPressed;
bool isSecondButtonPressed;

uint8_t presses = 0;

String binStr;

void setup() {
  for (uint8_t i = 0; i < 9; i++)
    pinMode(leds[i], OUTPUT);

  for (uint8_t i = 0; i < 2; i++)
    pinMode(buttons[i], INPUT);
}

void loop() {
  String binNumber = String(presses, BIN);

  if (binNumber.length() < 8) {
    String zeros = "";
    for (uint8_t i = 0; i < 8 - binNumber.length(); i++)
      zeros += '0';
      
    binStr = zeros + binNumber;
  } else binStr = binNumber;

  for (uint8_t i = 0; i < binStr.length(); i++) {
    if (binStr[i] == '0')
      digitalWrite(leds[i], LOW);
    else
      digitalWrite(leds[i], HIGH);
  }

  check();
}

void check() {
  isFirstButtonPressed = digitalRead(buttons[0]);
  isSecondButtonPressed = digitalRead(buttons[1]);

  if (isFirstButtonPressed) {
    delay(200);
    
    if (presses == 255)
      presses = 0;
    else
      presses++;
  }

  if (isSecondButtonPressed) {   
    delay(200);
    
    if (presses == 0)
      presses = 255;
    else
      presses--;
  }
}

String reverse(String str) {
  String newStr = "";
  for (int i = str.length() - 1; i >= 0 ; i--)
    newStr += str[i];

  return newStr;
}
