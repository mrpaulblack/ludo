#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


/**
* \brief class that saves player specific stufflike the player start and end
*
* This class is used for every player og the game; It basically saves the amount of
* figures the player have in their start and also figures in the player's end.
*
* @author Paul Braeuning
*/
class Player {


     private:
        int defaultFigureAvail;                 // amount of figures in Game
        int figureAvail;                        // figures the player has on start position
        std::vector<bool> endCoor;              // figures in end true when figure on position; false when not


    public:
        /**
        * \brief Contructor for Player class; sets up player start and end
        *
        * This contructor sets the amount of figure the player has in their start
        * and the size of the players end.
        *
        * @param int figure: amount of figures player has
        * @pre int figure needs to be 0 or bigger
        * @author Paul Braeuning
        */
        Player(int);


        /**
        * \brief returns true if the players start is full
        *
        * This function returns true in case the player start is full with all figures
        * or false if the player start is not full.
        *
        * @return true if player start is full; false if not
        * @author Paul Braeuning
        */
        bool getStartFull() const;


        /**
        * \brief returns the number of figures the player has in their start
        *
        * This function returns the amount of figures the player has in
        * their start.
        *
        * @return int number of figures in player start; 0 when none
        * @author Paul Braeuning
        */
        int getStart() const;


        /**
        * \brief returns the amount of figures the player has
        *
        * This function returns the amount of figures the player has, regardless
        * of where they are. (The amount of figures stays the same for the entire game).
        *
        * @return amount of fiures as int
        * @author Paul Braeuning
        */
        int getFigure() const;


        /**
        * \brief adds or subtracts a figure from player start
        *
        * This function adds or removes one figure from the players start.
        *
        * @param int numFigures the amount of figures the player wants to add or remove
        * @pre int numFigures needs to be -1 or 1
        * @author Paul Braeuning
        */
        void setStart(int);


        /**
        * \brief returns true if there is a figure at position and false if not
        *
        * This function returns the figure at a specific position in the player's end.
        *
        * @param size_t position position in the player's end
        * @return bool true if there is a figure there and false if not
        * @pre needs to be a valid index of endCoor vector (so from 0 to amount fo figures -1)
        * @author Paul Braeuning
        */
        bool getEnd(size_t) const;


        /**
        * \brief returns the amount of figures the player has in their end
        *
        * This function retuns the amount of figures tha player has in their end;
        * 0 if none and otherwise the int amount.
        *
        * @return int amount of figures in player's end; 0 if none
        * @author Paul Braeuning
        */
        int getFigureEnd() const;


        /**
        * \brief moves figure inside player end from one field to another
        *
        * This function accepts the a postion and sets it to true of the move is true
        * and sets it to false if move is false.
        *
        * @param size_t position inside the player's end
        * @param bool move; when true -> set position inside player's end to true; when false -> set to false
        * @pre position must be a valid index of endCooor vector and move must be oposite of bool at that position inside the player's end
        * @author Paul Braeuning
        */
        void setEnd(size_t , bool);


        /**
        * \brief returns true if player end is full and false if not
        *
        * This function basically chekcs if the player has won, since it
        * only returns true if player end is full and otherwise it always returns false.
        *
        * @return bool true if player end is full and false if not
        * @author Paul Braeuning
        */
        bool getFullEnd() const;


        /**
        * \brief prints player end into stdout/terminal
        *
        * This print function just prints out the player's end into the terminal.
        *
        * @author Paul Braeuning
        */
        void printEnd() const;
};
