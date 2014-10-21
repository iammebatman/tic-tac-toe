#include "gameBoard.h"
#include "gameOperations.h"
#include "game.h"

//main function
int main()
{
    splashScreen();
    int gameFile = selectGame();
    mainMenu(gameFile);
    return 0;
}

