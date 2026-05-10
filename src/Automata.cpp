// Copyright 2026 UNN-IASR
#include "Automata.h"
#include <sstream>
#include <string>

Automata::Automata() {
  cash = 0;
  state = OFF;
  selectedDrink = -1;

  menuSize = 4;
  menu = new std::string[menuSize];
  prices = new int[menuSize];

  menu[0] = "Coffee";
  menu[1] = "Tea";
  menu[2] = "Hot Chocolate";
  menu[3] = "Cappuccino";

  prices[0] = 50;
  prices[1] = 30;
  prices[2] = 60;
  prices[3] = 70;
}

Automata::~Automata() {
  delete[] menu;
  delete[] prices;
}

void Automata::on() {
  if (state == OFF) {
    state = WAIT;
  }
}

void Automata::off() {
  if (state == WAIT) {
    state = OFF;
    cash = 0;
    selectedDrink = -1;
  }
}

void Automata::coin(int amount) {
  if (state == WAIT || state == ACCEPT) {
    cash += amount;
    state = ACCEPT;
  }
}

std::string Automata::getMenu() {
  std::stringstream ss;
  for (int i = 0; i < menuSize; i++) {
    ss << i + 1 << ". " << menu[i] << " - " << prices[i] << " rub\n";
  }
  return ss.str();
}

std::string Automata::getState() {
  switch (state) {
    case OFF: return "OFF";
    case WAIT: return "WAIT";
    case ACCEPT: return "ACCEPT";
    case CHECK: return "CHECK";
    case COOK: return "COOK";
    default: return "UNKNOWN";
  }
}

bool Automata::choice(int drinkIndex) {
  if (state == ACCEPT && drinkIndex >= 0 && drinkIndex < menuSize) {
    selectedDrink = drinkIndex;
    state = CHECK;
    return true;
  }
  return false;
}

bool Automata::check() {
  if (state == CHECK && selectedDrink >= 0) {
    if (cash >= prices[selectedDrink]) {
      return true;
    }
  }
  return false;
}

void Automata::cancel() {
  if (state == ACCEPT || state == CHECK || state == COOK) {
    cash = 0;
    selectedDrink = -1;
    state = WAIT;
  }
}

void Automata::cook() {
  if (state == CHECK && check()) {
    cash -= prices[selectedDrink];
    state = COOK;
  }
}

void Automata::finish() {
  if (state == COOK) {
    state = WAIT;
    selectedDrink = -1;
  }
}

STATES Automata::getCurrentState() const {
  return state;
}

int Automata::getCash() const {
  return cash;
}

int Automata::getPrice(int index) const {
  if (index >= 0 && index < menuSize) {
    return prices[index];
  }
  return -1;
}
