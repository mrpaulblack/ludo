#include "Game.hpp"



Game::Game(size_t conRealPlayer, size_t conCPU) {
    try {
        if (conCPU + conRealPlayer > 1) {
            cpu = conCPU;
            realPlayer = conRealPlayer;
        }
        else { throw conCPU; }
    }
    catch(size_t conCPU) {
        std::cerr << "Game.Game: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Game::getRound() {
    return gameRound;
}



void Game::setRound() {
    gameRound += 1;
}



int Game::getWon() {
    return gameWonPlayer;
}



void Game::setWon(int player) {
    try {
        if (player >= 0) {
            gameWonPlayer = player;
        }
        else { throw player; }
    }
    catch(int player) {
         std::cerr << "Game.setWon: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Game::getDice() {
    return currentDice;
}



void Game::setDice(bool start) {
    if (start) {
        currentDice = dice.getRollStart();
    }
    else {
        currentDice = dice.getRoll();
    }
}



int Game::getInput(int max) {
    bool inputOK;               // control while loop until true for the while loop inside getInput function
    std::string input;          // actual input by player
    char checkInput;            // individual character from string array
    do {
        inputOK = true;
        std::cout << "Please insert a int number between 1 and " << max << ":" << std::endl;
        std::getline(std::cin, input);
        if (input.size() > 10 || input.size() <= 0) {
            inputOK = false;
            std::cout << "Character limit reached. Please type in a maximum of 10 characters." << std::endl;
        }
        else {
            for (size_t i = 0; i < input.size(); i++) {
                checkInput = input.at(i);
                if ((checkInput < 48 || checkInput > 57) && inputOK) {
                        inputOK = false;
                        std::cout << "Illegal character. Please only type in a number." << std::endl;
                }
            }
        }
        if (inputOK) {
            if (stoi(input) < 1 || stoi(input) > max) {
                inputOK = false;
                std::cout << "Illegal number. Please only type in a number which is in range." << std::endl;
            }
        }
    } while (!inputOK);
    return stoi(input);
}



int Game::getRandom() {
    return randomInt;
 }



void Game::setRandom(int max) {
    try {
        if (max > 0) {
            randomInt = dice.getInt(max);
        }
        else { throw max; }
    }
    catch (int max) {
        std::cerr << "Game.setRandom: Illegal Operation." << std::endl;
        exit(1);
    }
}



size_t Game::getPlayer() {
    return realPlayer;
}



size_t Game::getCPU() {
    return cpu;
}
