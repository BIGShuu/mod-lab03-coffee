// Copyright 2026 UNN-IASR
#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, ConstructorInitialState) {
  Automata automaton;
  EXPECT_EQ(automaton.getCurrentState(), OFF);
  EXPECT_EQ(automaton.getCash(), 0);
}

TEST(AutomataTest, TurnOn) {
  Automata automaton;
  automaton.on();
  EXPECT_EQ(automaton.getCurrentState(), WAIT);
}

TEST(AutomataTest, TurnOff) {
  Automata automaton;
  automaton.on();
  automaton.off();
  EXPECT_EQ(automaton.getCurrentState(), OFF);
}

TEST(AutomataTest, InsertCoin) {
  Automata automaton;
  automaton.on();
  automaton.coin(10);
  EXPECT_EQ(automaton.getCurrentState(), ACCEPT);
  EXPECT_EQ(automaton.getCash(), 10);
}

TEST(AutomataTest, ChooseDrink) {
  Automata automaton;
  automaton.on();
  automaton.coin(50);
  bool result = automaton.choice(0);
  EXPECT_TRUE(result);
  EXPECT_EQ(automaton.getCurrentState(), CHECK);
}

TEST(AutomataTest, CheckSufficientFunds) {
  Automata automaton;
  automaton.on();
  automaton.coin(50);
  automaton.choice(1);
  EXPECT_TRUE(automaton.check());
}

TEST(AutomataTest, CheckInsufficientFunds) {
  Automata automaton;
  automaton.on();
  automaton.coin(10);
  automaton.choice(0);
  EXPECT_FALSE(automaton.check());
}

TEST(AutomataTest, CookDrink) {
  Automata automaton;
  automaton.on();
  automaton.coin(50);
  automaton.choice(1);
  automaton.cook();
  EXPECT_EQ(automaton.getCurrentState(), COOK);
}

TEST(AutomataTest, FinishPreparation) {
  Automata automaton;
  automaton.on();
  automaton.coin(50);
  automaton.choice(1);
  automaton.cook();
  automaton.finish();
  EXPECT_EQ(automaton.getCurrentState(), WAIT);
}

TEST(AutomataTest, CancelOperation) {
  Automata automaton;
  automaton.on();
  automaton.coin(30);
  automaton.cancel();
  EXPECT_EQ(automaton.getCurrentState(), WAIT);
  EXPECT_EQ(automaton.getCash(), 0);
}
