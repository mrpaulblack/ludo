#include "Board.hpp"



Board::Board(int player, int gap) {
    try{
        if (player > 0 && gap > 0) {
            boardGap = gap;
            board.resize(player * boardGap);
            for (size_t i = 0; i < board.size(); i++) {
                board[i] = -1;
            }
        }
        else { throw player; }
    }
    catch (int player) {
        std::cerr << "Board.Board: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Board::getPlayer(size_t position) const {
    try {
        if (position < board.size() && position >= 0) {
            return board[position];
        }
        else { throw position; }
    }
    catch(size_t position) {
        std::cerr << "Board.getPlayer: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Board::getBoardSize(size_t player) const {
    try {
        if (player == 0) {
            return board.size() -1;
        }
        else if (player*boardGap < board.size() && player >= 0) {
            return (player * boardGap) -1;
        }
        else { throw player;}
    }
    catch(size_t player) {
        std::cerr << "Board.getPlayerSize: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Board::getNewPosition(size_t player, int oldPosition, int dice) const {
    try {
        if (player*boardGap < board.size() && player >= 0) {
            if (player == 0) {
                if (oldPosition + dice > getBoardSize(0)) {
                    return -1;
                }
                else { return oldPosition + dice; }
            }
            else if (oldPosition < getBoardSize(player) && oldPosition + dice <= getBoardSize(player)) {
                return oldPosition + dice;
            }
            else if (oldPosition > getBoardSize(player)) {
                if (oldPosition + dice <= getBoardSize(0)) {
                    return oldPosition + dice;
                }
                else if (oldPosition + dice > getBoardSize(0) && dice -1 - (getBoardSize(0) - oldPosition) < getBoardSize(player)) {
                    return dice -1 - (board.size() -1 - oldPosition);
                }
                else { return -1; }
            }
            else { return -1; }
        }
        else { throw player;}
    }
    catch(size_t player) {
        std::cerr << "Board.getNewPosition: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Board::getOutOfBound(size_t player, int oldPosition, int dice) const {
    try {
        if (player*boardGap < board.size() && player >= 0) {
            return -1 * (getBoardSize(player) -oldPosition -dice);
        }
        else { throw player; }
    }
    catch(size_t player) {
        std::cerr << "Board.getOutOfBound: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Board::getStartPosition(size_t player, size_t dice) const {
    dice -= 1;
    try {
        if ((player * boardGap) + dice < board.size() && dice >= 0) {
            return board[(player * boardGap) + dice];
        }
        else if (dice >= 0 && getNewPosition(player, getStartPosition(player, 1), dice +1) != -1) {
            return board[getNewPosition(player, getStartPosition(player, 1), dice +1)];
        }
        else if (dice >= 0 && getNewPosition(player, getStartPosition(player, 1), dice +1) == -1) {
            return -2; //if out of bound; cannot return -1, because valid board value; so returns -2 as a dirty workaround instead
        }
        else { throw player; }
    }
    catch (size_t player) {
        std::cerr << "Board.getStartPostion: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Board::setStartPosition(size_t player, size_t dice) {
    int oldPlayer = -1;     //temp save old player
    dice -= 1;              //array starts at 0; dice at 1 -> dice -1 for board
    try {
        if ((player * boardGap) + dice < board.size() && dice >= 0) {
            oldPlayer =  board[(player * boardGap) + dice];
            board[(player * boardGap) + dice] = player;
            return oldPlayer;
        }
        else if (dice >= 0 && getNewPosition(player, getStartPosition(player, 1), dice +1) != -1) {
            oldPlayer = board[getNewPosition(player, getStartPosition(player, 1), dice +1)];
            board[getNewPosition(player, getStartPosition(player, 1), dice +1)] = player;
            return oldPlayer;
        }
        else { throw player; }
    }
    catch (size_t player) {
        std::cerr << "Board.setStartPosition: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Board::getPosition(int player, int figure) const {
    try{
        int counter = 0;
        for (size_t n = 0; n < board.size(); n++) {
            if (getPlayer(n) == player) {
                counter += 1;
                if (counter == figure) {
                    return n;
                }
            }
        }
        throw figure;
    }
    catch(int figure) {
        std::cerr << "Board.getPosition: Illegal Operation." << std::endl;
        exit(1);
    }
}



int Board::setPosition(size_t oldPosition, size_t newPosition, size_t player) {
    int oldPlayer = -1;      //temp save player that needs to go back to start
    try {
        if (newPosition < board.size() && newPosition >= 0 && oldPosition < board.size() && oldPosition >= 0 && board[newPosition] == -1) {
            board[oldPosition] = -1;
            board[newPosition] = player;
            return -1;
        }
        else if (newPosition < board.size() && newPosition >= 0 && oldPosition < board.size() && oldPosition >= 0 && board[newPosition] != -1) {
            oldPlayer = board[newPosition];
            board[oldPosition] = -1;
            board[newPosition] = player;
            return oldPlayer;
        }
        else { throw player; }
    }
    catch(size_t player) {
        std::cerr << "Board.setPosition: Illegal Operation." << std::endl;
        exit(1);
    }
}



void Board::deletePosition(size_t position) {
    try {
        if (position >= 0 && position < board.size()) {
            board[position] = -1;
        }
        else { throw position; }
    }
    catch(size_t position) {
        std::cerr << "Board.deletePosition: Illegal Operation." << std::endl;
        exit(1);
    }
}



void Board::printBoard() const {
    for (size_t i = 0; i < (board.size() / boardGap); i++) {
        std::cout << "P" << i +1 << " Start: ";
        for (size_t n = i * boardGap; n < i * boardGap + boardGap; n++) {
            if (board[n] == -1) {
                std::cout << std::setw(4) << ".";
            }
            else { std::cout << std::setw(4) << board[n] +1; }
        }
        std::cout << std::endl;
    }
}
