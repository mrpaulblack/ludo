#include "Dice.hpp"



int Dice::getRoll() {
    currentDice = 0;
    std::default_random_engine  randomGen(randomDev());
    std::uniform_int_distribution<int> dice(1, 6);
    while (dice(randomGen) == 6) {
        currentDice += 6;
    }
    do {
        currentDice2 =  dice(randomGen);
    } while(currentDice2 == 6);
    currentDice += currentDice2;
    return currentDice;
}



int Dice::getRollStart() {
    std::default_random_engine  randomGen(randomDev());
    std::uniform_int_distribution<int> dice(1, 6);
    for (int i = 0; i <= 2; i++) {
        if (dice(randomGen) == 6) {
            do {
            currentDice =  dice(randomGen);
            } while(currentDice == 6);
            return currentDice;
        }
    }
    return -1;
}



int Dice::getInt(int max) {
    std::default_random_engine  randomGen(randomDev());
    std::uniform_int_distribution<int> dice(1, max);
    return dice(randomGen);
}
