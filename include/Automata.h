// Copyright 2026 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>

enum STATES {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {
 private:
  int cash;
  std::string* menu;
  int* prices;
  int menuSize;
  STATES state;
  int selectedDrink;

 public:
  Automata();
  ~Automata();

  void on();
  void off();
  void coin(int amount);
  std::string getMenu();
  std::string getState();
  bool choice(int drinkIndex);
  bool check();
  void cancel();
  void cook();
  void finish();

  // Дополнительные методы для тестирования
  STATES getCurrentState() const;
  int getCash() const;
  int getPrice(int index) const;
};

#endif  // INCLUDE_AUTOMATA_H_
