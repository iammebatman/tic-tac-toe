#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

#include "game.h"

#ifndef GAMEOPERATIONS_H_INCLUDED
#define GAMEOPERATIONS_H_INCLUDED

void clearScreen();
void splashScreen();
int selectGame();
void showStatistics(int);
void mainMenu(int);
bool fileExists(const std::string&);
void updateStats(int, int, int, int);
void endGameSingleForPlayer(int);
void endGameSingleForAi(int);
void endGameSingleTie(int);
void endGameMultiplayerForPlayerOne();
void endGameMultiplayerForPlayerTwo();
void endGameMultiplayerTie();

#endif // GAMEOPERATIONS_H_INCLUDED
