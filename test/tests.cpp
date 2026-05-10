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

TEST(AutomataTest, InsertMultipleCoins) {
    Automata automaton;
    automaton.on();
    automaton.coin(10);
    automaton.coin(20);
    automaton.coin(30);
    EXPECT_EQ(automaton.getCash(), 60);
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
    EXPECT_EQ(automaton.getCash(), 20);
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

TEST(AutomataTest, CancelInAcceptState) {
    Automata automaton;
    automaton.on();
    automaton.coin(30);
    automaton.cancel();
    EXPECT_EQ(automaton.getCurrentState(), WAIT);
    EXPECT_EQ(automaton.getCash(), 0);
}

TEST(AutomataTest, CancelInCheckState) {
    Automata automaton;
    automaton.on();
    automaton.coin(50);
    automaton.choice(0);
    automaton.cancel();
    EXPECT_EQ(automaton.getCurrentState(), WAIT);
    EXPECT_EQ(automaton.getCash(), 0);
}

TEST(AutomataTest, CancelInCookState) {
    Automata automaton;
    automaton.on();
    automaton.coin(70);
    automaton.choice(3);
    automaton.cook();
    automaton.cancel();
    EXPECT_EQ(automaton.getCurrentState(), WAIT);
    EXPECT_EQ(automaton.getCash(), 0);
}

TEST(AutomataTest, CannotTurnOnWhenAlreadyOn) {
    Automata automaton;
    automaton.on();
    automaton.on();
    EXPECT_EQ(automaton.getCurrentState(), WAIT);
}

TEST(AutomataTest, CannotTurnOffWhenOff) {
    Automata automaton;
    automaton.off();
    EXPECT_EQ(automaton.getCurrentState(), OFF);
}

TEST(AutomataTest, CannotInsertCoinWhenOff) {
    Automata automaton;
    automaton.coin(50);
    EXPECT_EQ(automaton.getCurrentState(), OFF);
    EXPECT_EQ(automaton.getCash(), 0);
}

TEST(AutomataTest, CannotChooseDrinkWhenOff) {
    Automata automaton;
    bool result = automaton.choice(0);
    EXPECT_FALSE(result);
}

TEST(AutomataTest, CannotChooseInvalidDrink) {
    Automata automaton;
    automaton.on();
    automaton.coin(50);
    bool result = automaton.choice(10);
    EXPECT_FALSE(result);
}

TEST(AutomataTest, CompleteCoffeePurchase) {
    Automata automaton;
    automaton.on();
    EXPECT_EQ(automaton.getCurrentState(), WAIT);
    
    automaton.coin(50);
    EXPECT_EQ(automaton.getCurrentState(), ACCEPT);
    
    automaton.choice(0);
    EXPECT_EQ(automaton.getCurrentState(), CHECK);
    
    EXPECT_TRUE(automaton.check());
    
    automaton.cook();
    EXPECT_EQ(automaton.getCurrentState(), COOK);
    EXPECT_EQ(automaton.getCash(), 0);
    
    automaton.finish();
    EXPECT_EQ(automaton.getCurrentState(), WAIT);
}

TEST(AutomataTest, CompleteScenarioWithChange) {
    Automata automaton;
    automaton.on();
    automaton.coin(100);
    automaton.choice(3);
    automaton.cook();
    EXPECT_EQ(automaton.getCash(), 30);
    automaton.finish();
}

// Total: 20 tests
