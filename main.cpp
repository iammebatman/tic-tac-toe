#include "game.h"
#include "gameDisplays.h"
#include "gameChecks.h"
#include "gameOperations.h"

//main function
int main()
{
    splashScreen();
    int gameFile = selectGame();
    mainMenu(gameFile);
    return 0;
}

