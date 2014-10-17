#ifndef GAMEDISPLAYS_H_INCLUDED
#define GAMEDISPLAYS_H_INCLUDED

#include <iostream>

void clearScreen();
void splashScreen();
void mainMenu(int gameFile);
int selectGame();
void showStatistics(int gameFile);
void getGameBoard(std::string n1, std::string n2, std::string n3, std::string n4, std::string n5, std::string n6, std::string n7, std::string n8, std::string n9);
void endGameSingleForPlayer(int gameFile);
void endGameSingleForAi(int gameFile);
void endGameSingleTie(int gameFile);
void endGameMultiplayerForPlayerOne();
void endGameMultiplayerForPlayerTwo();
void endGameMultiplayerTie();

#endif // GAMEDISPLAYS_H_INCLUDED
