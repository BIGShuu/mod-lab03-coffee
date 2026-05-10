#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>

enum STATES {
    OFF,      // Выключено
    WAIT,     // Ожидание
    ACCEPT,   // Приём денег
    CHECK,    // Проверка наличности
    COOK      // Приготовление
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

#endif // AUTOMATA_H
