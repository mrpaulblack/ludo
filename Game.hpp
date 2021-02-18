#pragma once
#include <iostream>
#include "Dice.cpp"


/**
* \brief class that saves all the variables and metrics of the current game
*
* This class saves all the variables for the current game; such as the current
* dice, the round of the game and the amount of real players as well as the 
* amount of cpu's.
*
* @author Paul Braeuning
*/
class Game {


    private:
        size_t cpu = 0;                 //number of cpus
        size_t realPlayer = 0;          //number of real players
        int gameRound = 1;              //saves rounds of current game
        int gameWonPlayer = -1;         //saves the plaeyr that won
        int currentDice = 1;            //saves current Dice
        int randomInt = 0;              //saves random int generated for bot rule selection
        Dice dice;                      //every game object gets a dice object for generating dice


    public:
        /**
        * \brief constructor sets the amount of real player and cpu's
        *
        * This function sets the amount of real player and cpu's.
        *
        * @param size_t conRealPlayer amount of real player
        * @param size_t conCPU amount of cpu's
        * @pre cpu and player must both be a unsigned int and cpu + player must be bigger then 0
        * @author Paul Braeuning
        */
        Game(size_t, size_t);


        /**
        * \brief returns the current number of rounds
        *
        * This function just returns the current number of rounds.
        *
        * @return the amount of rounds
        * @author Paul Braeuning
        */
        int getRound();


        /**
        * \brief adds one round to the total amount of rounds
        *
        * This function jsut adds one to the current amount of rounds.
        *
        * @author Paul Braeuning
        */
        void setRound();


        /**
        * \brief returns -1 if the game is not won yet or else the plaeyr that won the game.
        *
        * This function the plaeyr that won or else just -1.
        *
        * @return -1 or the paleyr that won
        * @author Paul Braeuning
        */
        int getWon();


        /**
        * \brief sets the player that won the game
        *
        * This function sets the plaeyr that won the game.
        *
        * @param int player is the player that won the game
        * @pre needs to be a valid player or cpu of the game
        * @author Paul Braeuning
        */
        void setWon(int);


        /**
        * \brief returns the current dice for the round
        *
        * This function just returns the current dice.
        *
        * @return current dice
        * @author Paul Braeuning
        */
        int getDice();


        /**
        * \brief generates a new dice for the round
        *
        * This function generates a new dice for the game start, if param is set to true
        * or else a normal dice.
        *
        * @param bool start if true -> new start dice; else if false -> new normal dice
        * @pre must be true or false / 1 or 0
        * @author Paul Braeuning
        */
        void setDice(bool);


        /**
        * \brief gets player input from 1 to max
        *
        * This function returns the input from the player and blocks
        * illigel numbers and characters.
        *
        * @param int max upper wall for input
        * @return selected number / sanitized input
        * @pre int max needs to be a int > 0
        * @author Paul Braeuning
        */
        int getInput(int);


        /**
        * \brief returns the randomly selected number
        *
        * This function returns the randomly selected number for the cpu's.
        *
        * @return the generated random int
        * @author Paul Braeuning
        */
        int getRandom();


        /**
        * \brief selects a random int from 1 to max
        *
        * This function calls the dice object and generates a number
        * between 1 and int max and saves it.
        *
        * @param int max upper wall for generator
        * @pre int max needs to be > 0
        * @author Paul Braeuning
        */
        void setRandom(int);


        /**
        * \brief just returns the number of real player
        *
        * This function just returns the number of real player.
        *
        * @return number of real plaeyr as int
        * @author Paul Braeuning
        */
        size_t getPlayer();


        /**
        * \brief just returns the number of cpu's
        *
        * This function just returns the number of cpu's.
        *
        * @return number of real plaeyr as int
        * @author Paul Braeuning
        */
        size_t getCPU();
};
