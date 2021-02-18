#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.cpp"
#include "Board.cpp"
#include "Game.cpp"



/**
* \brief one round of the game
*
* This function is basically running one round of the game;
* every round its called in the main function and sets up all the logic
* for going through every player for that round.
*
* @author Paul Braeuning
*/
void gameRound();



/**
* \brief most important function: printing out rules and applying them
*
* This function is the most important one; It basically prints out the valig rules
* for a player, when called with player and -1; After that its called with the player
* and the selected rule and executes the actual turn for the player.
*
* @param size_t i the current player
* @param int selectedRule; can be -1 for just printing and after that something > 0 for the selected rule
* @return number of possible rules that can be applied to the player for that turn
* @pre must be a valid player and selectedRule must be valid for that turn
* @author Paul Braeuning
*/
int gameRule(size_t, int);



/**
* \brief prints out most of the ui for that player and round
*
* This function prints out the player, generates the current dice and
* also prints out the current board and some pretty endl.
*
* @param size_t i the current player
* @pre size_t i must be a valid player
* @author Paul Braeuning
*/
void gamePrint(size_t);



/**
* \brief checks if the game is won and sets the player who won the game
*
* This function checks after every turn of every player, if they won the game
* and sets the player that won the game.
*
* @param size_t i current player
* @pre size_t i must be valid player
* @author Paul Braeuning
*/
void gameWon(size_t);
