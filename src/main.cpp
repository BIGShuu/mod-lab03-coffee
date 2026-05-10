// Copyright 2026 UNN-IASR
#include "Automata.h"
#include <iostream>

int main() {
  Automata automaton;
  automaton.on();
  automaton.coin(50);
  automaton.choice(1);
  if (automaton.check()) {
    automaton.cook();
    automaton.finish();
  }
  automaton.off();
  return 0;
}
