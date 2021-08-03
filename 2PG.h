#ifndef TWOPG_H
#define TWOPG_H

#include <LiquidCrystal_I2C.h>

#define LED1 5
#define LED2 6
#define BTN1 7
#define BTN2 8
#define BUZZ 9

enum Player : uint8_t { PLAYER_1 = 0, PLAYER_2 = 1 };

class TwoPG {
  private:
    static uint8_t buttonState[2];
    static LiquidCrystal_I2C* lcd;
    TwoPG(){}

  public:
    static uint8_t begin();
    static LiquidCrystal_I2C* getLcd();
    static uint8_t getButtonState(Player player);
    static void setLEDState(Player player, uint8_t state);
    static void setBuzzerTone(unsigned int freq, unsigned long duration = 0UL);
    static void silenceBuzzer();
};

#endif