#pragma once
#include <random>


/**
* \brief class for the randomizer, which acts as dice in the game
*
* This class is used as a dice in the game, which returns random int's
* for the player as a dice and for the cpu's as a random rule selecter.
*
* @author Paul Braeuning
* @see Game
*/
class Dice {


    private:
        std::random_device  randomDev;                  //random device
        std::default_random_engine randomGen;           //random engine
        std::uniform_int_distribution<int> dice;        //uniform int dice (so that the results are in an specific type/range)
        int currentDice = 0;                            //temp save current dice (in case of 6)
        int currentDice2 = 0;                           //temp save another dice (after player got a six; so that they wont get another one)


    public:
        /**
        * \brief returns the number the player got with a dice throw
        *
        * This function acts as a dice and returns the number the player got as an int
        * it also automatically adds up sixes, until the player gets something else and
        * returns that as a number.
        *
        * @return int from 1 to whatever the dice generates
        * @author Paul Braeuning
        */
        int getRoll();


        // get a random int from 1 to 6 3 times for the start (6 to get out)
        /**
        * \brief returns a dice from 1 to 5, if at least one siz after 3 tries
        *
        * This function acts as the dice for when the player start is full or
        * when player has all figures in end and start; throws the dice 3 times
        * and if the player gets a six the function returns an int from 1 to 5.
        *
        * @return int from 1 to 5; or -1 if player did not get a siz after 3 tries
        * @author Paul Braeuning
        */
        int getRollStart();


        /**
        * \brief returns a number from 1 to int max so that cpu can randomly select a Rule
        *
        * This function takes in an int max and returns a random number from 1 to int max.
        *
        * @param int max: is the uper wall for the randomizer
        * @return int from 1 to int max
        * @pre int max needs to be 1 or bigger
        * @author Paul Braeuning
        */
        int getInt(int);
};
