#include "Automata.h"
#include <iostream>

int main() {
    Automata automaton;
    
    std::cout << "=== Hot Drinks Automaton Demo ===" << std::endl;
    std::cout << "Initial state: " << automaton.getState() << std::endl;
    
    std::cout << "\n--- Turning on the automaton ---" << std::endl;
    automaton.on();
    std::cout << "State: " << automaton.getState() << std::endl;
    
    std::cout << "\n--- Menu ---" << std::endl;
    std::cout << automaton.getMenu();
    
    std::cout << "\n--- Inserting coins ---" << std::endl;
    automaton.coin(20);
    std::cout << "Inserted 20 rub. Cash: " << automaton.getCash() << std::endl;
    automaton.coin(30);
    std::cout << "Inserted 30 rub. Cash: " << automaton.getCash() << std::endl;
    std::cout << "State: " << automaton.getState() << std::endl;
    
    std::cout << "\n--- Choosing Tea (index 1, price 30) ---" << std::endl;
    automaton.choice(1);
    std::cout << "State: " << automaton.getState() << std::endl;
    
    std::cout << "\n--- Checking balance ---" << std::endl;
    if (automaton.check()) {
        std::cout << "Sufficient funds!" << std::endl;
    } else {
        std::cout << "Insufficient funds!" << std::endl;
    }
    
    std::cout << "\n--- Cooking drink ---" << std::endl;
    automaton.cook();
    std::cout << "State: " << automaton.getState() << std::endl;
    std::cout << "Remaining cash: " << automaton.getCash() << std::endl;
    
    std::cout << "\n--- Finishing ---" << std::endl;
    automaton.finish();
    std::cout << "State: " << automaton.getState() << std::endl;
    
    std::cout << "\n--- Turning off ---" << std::endl;
    automaton.off();
    std::cout << "State: " << automaton.getState() << std::endl;
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    
    return 0;
}
