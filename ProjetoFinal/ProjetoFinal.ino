#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BotaoPU.h>

LiquidCrystal_I2C lcd(0x27,20,4);

BotaoPU b1, b2, b3, b4;

const int botAddEnergia = 2;
const int botRmvEnergia = 3;
const int botAddRitual = 4;
const int botRmvRitual = 5;

int energiaCont = 10;
int ritualCont = 9;

const int lFusivel = 16;
const int lRitual = 13;

byte energia[] = {
  B11110,
  B01110,
  B00111,
  B00111,
  B00110,
  B01100,
  B01000,
  B10000,
};

byte magia[] = {
  B00000,
  B00110,
  B01101,
  B01100,
  B01110,
  B01110,
  B01110,
  B11111,
};

byte fusivel[] = {
  B01110,
  B01110,
  B00100,
  B00100,
  B00100,
  B00100,
  B01110,
  B01110
};

byte ritual[] = {
  B00100,
  B01110,
  B00100,
  B00000,
  B01110,
  B00100,
  B01110,
  B01110
};

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Fusiveis :");
  lcd.setCursor(0, 1);
  lcd.print("Rituais :");
  
  lcd.createChar(0, energia);
  lcd.createChar(1, magia);
  lcd.createChar(2, fusivel);
  lcd.createChar(3, ritual);

  lcd.setCursor(8, 0);
  lcd.write(2);
  lcd.setCursor(7, 1);
  lcd.write(3);
  
  b1.setupBot(2);
  b2.setupBot(3);
  b3.setupBot(4);
  b4.setupBot(5);
}

void loop() {
  exibeEnergia();
  exibeRitual();
}

void exibeEnergia() {
  if(b1.ButtonUp() && energiaCont < lFusivel)
  {
    lcd.setCursor(energiaCont, 0);
    lcd.write(0);
    energiaCont++;
  }

  if(b2.ButtonUp() == HIGH && energiaCont > 9)
  {
    lcd.setCursor(energiaCont, 0);
    lcd.print(" ");
    if(energiaCont >= 11) {
      energiaCont--;
    }
  }
}

void exibeRitual() {
  if(b3.ButtonUp() && ritualCont < lRitual)
  {
    lcd.setCursor(ritualCont, 1);
    lcd.write(1);
    ritualCont++;
  }
  
  if(b4.ButtonUp() == HIGH && ritualCont > 8)
  {
    lcd.setCursor(ritualCont, 1);
    lcd.print(" ");
    if(ritualCont >=10) {
      ritualCont--;
    }
  }
}