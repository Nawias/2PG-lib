#include "2PG.h"
#include <Arduino.h>

LiquidCrystal_I2C* TwoPG::lcd = 0;
uint8_t TwoPG::buttonState[2] = {0,0};

uint8_t TwoPG::begin() {
  lcd = new LiquidCrystal_I2C(0x27, 16,2);
  lcd->begin(16,2);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
  return 0;
}

LiquidCrystal_I2C* TwoPG::getLcd() {
  return lcd;
}

uint8_t TwoPG::getButtonState(Player player){
  buttonState[PLAYER_1] = digitalRead(BTN1);
  buttonState[PLAYER_2] = digitalRead(BTN2);
  return buttonState[player];
}

void TwoPG::setLEDState(Player player, uint8_t state){
  analogWrite(player + LED1, state);
}

void TwoPG::setBuzzerTone(unsigned int freq, unsigned long duration = 0UL) {
  tone(BUZZ, freq, duration);
}

void TwoPG::silenceBuzzer() {
  noTone(BUZZ);
}