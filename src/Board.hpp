#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


/**
* \brief class that saves the figures on the board
*
* This class is saving the acrual board and the figures of the player's
* on that board.
*
* @author Paul Braeuning
*/
class Board {


    private:
        std::vector <int> board;                //int board vector (gets size from contructor based on gap and player num)
        int boardGap;                           //sets gap between players on board; default 10 (so p0: 0, p1: 10, p2: 20....)


    public:
        /**
        * \brief contructor sets up the board
        *
        * This function sets up the size of the board based on the
        * amount of players and the boardsize per player.
        *
        * @param int player the amount of player (real player and bots)
        * @param int gap the gap between each player's start (the actual board size is basically the gap * player)
        * @pre player and gap must both be > 0
        * @author Paul Braeuning
        */
        Board(int player, int gap);


        /**
        * \brief returns the player at a board position
        *
        * This function just returns the value of the main board vector
        * at an specific index.
        *
        * @param size_t position the postion on the board
        * @return the value of the board vector at the position
        * @pre position must be bigger then 0 and smaller then board size
        * @author Paul Braeuning
        */
        int getPlayer(size_t position) const;


        /**
        * \brief returns the last field on the board for a player
        *
        * This function returns the last field on the board for a player;
        * so for example the last position on the board for player 1 is 9 and so on.
        *
        * @param size_t player the player
        * @return returns the last position of the board for that player
        * @pre player must be valid and bigger 0
        * @author Paul Braeuning
        */
        int getBoardSize(size_t player) const;


        /**
        * \brief returns the new position of a figure
        *
        * This function returns the new position of a figure on the board
        * of the figure is not going to be on the board it returns -1.
        *
        * @param size_t player the current player
        * @param int oldPosition the current position of the figure
        * @param int dice 
        * @return new position on board or -1 if new position is out of bounds
        * @pre valid player; oldPosition needs to be on the board; dice needs to be >= 0
        * @author Paul Braeuning
        */
        int getNewPosition(size_t player, int oldPosition, int dice) const;


        /**
        * \brief returns the amount by how much a figure is out of bounds
        *
        * This function returns how much a figure is going to be outside
        * of the board.
        *
        * @param size_t player current player
        * @param int oldPosition current position of that figure
        * @param int dice the current dice of the round and player
        * @return value by how much the figure id going to be out of bounds
        * @pre valid player; oldPosition needs to be on the board; dice needs to be >= 0
        * @author Paul Braeuning
        */
        int getOutOfBound(size_t player, int oldPosition, int dice) const;


        /**
        * \brief returns the player at the start position
        *
        * This function returns the value of the board at the position
        * where the plaeyr is putting in their figure.
        *
        * @param size_t player the current player
        * @param size_t dice the current dice of the round / player
        * @return the value of the board at the start position of the player / figure
        * @pre player needs to be valid and dice must be >= 0
        * @author Paul Braeuning
        */
        int getStartPosition(size_t player, size_t dice) const;


        /**
        * \brief sets a the player's figure on that start position
        *
        * This function sets the figure of a player on the board;
        * So thats the player's startpoint + their dice.
        *
        * @param size_t player the current player
        * @param int figure the current player's figure
        * @return returns the value of the board at start position for that figure
        * @pre player needs to be valid and figure needs to be bigger then 0
        * @author Paul Braeuning
        */
        int setStartPosition(size_t player, size_t dice);


        /**
        * \brief returns the position of a specific figure of a player on the board
        *
        * This function returns the board index at which a specific figure
        * of an player is.
        *
        * @param int player the current player
        * @param int figure the figure of that player
        * @return the position of that figure on the board
        * @pre must be a valid player and the figure of tha player must exist on the board
        * @author Paul Braeuning
        */
        int getPosition(int player, int figure) const;


        /**
        * \brief moves figure of player from one location to another
        *
        * This function moves the figure of the player from one location to
        * another one and returns the value of the board at the new position.
        *
        * @param size_t oldPosition the current position of that figure
        * @param size_t newPosition the new Postion of the figure on the board
        * @param size_t player the current player
        * @return the value of the board at the new position
        * @pre old and new position must be on the board and the player must be valid
        * @author Paul Braeuning
        */
        int setPosition(size_t oldPosition, size_t newPosition, size_t player);


        /**
        * \brief deletes figure from board
        *
        * This function just sets the value of the board at the
        * index position to -1 (deletes any figure on that index).
        *
        * @param size_t position position inside the board
        * @pre position must be on the board
        * @author Paul Braeuning
        */
        void deletePosition(size_t position);

        // print current board to console
        /**
        * \brief this function just prints the board into stdout
        *
        * This function prints the board into the player's terminal;
        * it prettyfies the board by replacing -1 with a .
        *
        * @author Paul Braeuning
        */
        void printBoard() const;
};
