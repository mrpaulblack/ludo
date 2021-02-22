#include "Player.hpp"



Player::Player(int figure) {
    try {
        if (figure > 0) {
            defaultFigureAvail = figure;
            figureAvail = figure;
            endCoor.resize(figure);
        }
    }
    catch(int figure) {
        std::cerr << "Player.Player: Illegal Operation." << std::endl;
        exit(1);
    }
}



bool Player::getStartFull() {
    if (figureAvail == defaultFigureAvail) {
        return true;
    }
    else { return false; }
}



int Player::getStart() {
    return figureAvail;
}



int Player::getFigure() {
    return defaultFigureAvail;
}



void Player::setStart(int numFigure) {
    try {
        if ((numFigure == 1 || numFigure == -1) && (figureAvail + numFigure >= 0 && figureAvail + numFigure <= defaultFigureAvail)) {
            figureAvail += numFigure;
        }
        else { throw numFigure; }
    }
    catch(int numFigure) {
        std::cerr << "Player.setStart: Illegal Operation." << std::endl;
        exit(1);
    }
}



bool Player::getEnd(size_t position) {
    try {
        if (position < endCoor.size() && position >= 0) {
            return endCoor[position];
        }
        else { throw position; }
    }
    catch(size_t position) {
        std::cerr << "Player.getEnd: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Player::getFigureEnd() {
    int counter = 0;
    for (size_t i = 0; i < endCoor.size(); i++) {
        if (endCoor[i]) {
            counter += 1;
        }
    }
    return counter;
}



void Player::setEnd(size_t position , bool move) {
    try {
        if (position < endCoor.size() && position >= 0 && !endCoor[position] && move) {
            endCoor[position] = true;
        }
        else if (position < endCoor.size() && position >= 0 && endCoor[position] && !move) {
            endCoor[position] = false;
        }
        else { throw position; }
    }
    catch(size_t position) {
        std::cerr << "Player.setEnd: Illegal Operation." << std::endl;
        exit(1);
    }
}



bool Player::getFullEnd() {
    bool checkFull = true;
    for (size_t i = 0; i < endCoor.size(); i++) {
        if (!endCoor[i]) {
            checkFull = false;
        }
    }
    if (checkFull) { return true; }
    else { return false; }
}



void Player::printEnd() {
    for (size_t i = 0; i < endCoor.size(); i++) {
        if (!endCoor[i]) {
            std::cout << std::setw(4) << ".";
        }
        else { std::cout << std::setw(4) << endCoor[i]; }
    }
}
