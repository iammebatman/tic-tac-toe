#include "gameOperations.h"

//clear screen
void clearScreen()
{
    std::cout << std::string(100, '\n');
}

//splash screen
void splashScreen()
{
    std::cout << "\n\n";
    std::cout << "  *******************************************\n";
    std::cout << "  *******************************************\n";
    std::cout << "  **                                       **\n";
    std::cout << "  **              TIC-TAC-TOE              **\n";
    std::cout << "  **                                       **\n";
    std::cout << "  *******************************************\n";
    std::cout << "  *******************************************\n\n";
}

//select game
int selectGame()
{
    clearScreen();
    //declare variables
    int selection;
    std::string gameOneInitials;
    std::string gameTwoInitials;
    std::string gameThreeInitials;
    std::string gameFourInitials;
    bool gameOneEmpty = false;
    bool gameTwoEmpty = false;
    bool gameThreeEmpty = false;
    bool gameFourEmpty = false;

    while(true)
    {

        // check if save game files exist and create them if returned false
        if(!fileExists("save1.txt"))
        {
            std::ofstream wipeFile1("save1.txt");
            wipeFile1 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
            wipeFile1.close();
        }
        if(!fileExists("save2.txt"))
        {
            std::ofstream wipeFile2("save2.txt");
            wipeFile2 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
            wipeFile2.close();
        }
        if(!fileExists("save3.txt"))
        {
            std::ofstream wipeFile3("save3.txt");
            wipeFile3 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
            wipeFile3.close();
        }
        if(!fileExists("save4.txt"))
        {
            std::ofstream wipeFile4("save4.txt");
            wipeFile4 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
            wipeFile4.close();
        }

        //open files and associate objects
        std::ifstream saveOne("save1.txt");
        std::ifstream saveTwo("save2.txt");
        std::ifstream saveThree("save3.txt");
        std::ifstream saveFour("save4.txt");

        //get game file initials
        saveOne >> gameOneInitials;
        saveTwo >> gameTwoInitials;
        saveThree >> gameThreeInitials;
        saveFour >> gameFourInitials;

        //determine empty files
        if(gameOneInitials == "---")
        {
            gameOneEmpty = true;
        }
        if(gameTwoInitials == "---")
        {
            gameTwoEmpty = true;
        }
        if(gameThreeInitials == "---")
        {
            gameThreeEmpty = true;
        }
        if(gameFourInitials == "---")
        {
            gameFourEmpty = true;
        }

        //display game files
        std::cout << "+-------------+ +-------------+\n";
        std::cout << "|             | |             |\n";
        std::cout << "| GAME 1: " << gameOneInitials << " | | GAME 2: " << gameTwoInitials << " |\n";
        std::cout << "|             | |             |\n";
        std::cout << "+-------------+ +-------------+\n";
        std::cout << std::endl;
        std::cout << "+-------------+ +-------------+\n";
        std::cout << "|             | |             |\n";
        std::cout << "| GAME 3: " << gameThreeInitials << " | | GAME 4: " << gameFourInitials << " |\n";
        std::cout << "|             | |             |\n";
        std::cout << "+-------------+ +-------------+\n";
        std::cout << std::endl;

        //close files
        saveOne.close();
        saveTwo.close();
        saveThree.close();
        saveFour.close();

        //select game and return value
        std::cout << "[1-4]	Select Game" << std::endl;
        std::cout << "[5]	Reset All Games" << std::endl;
        std::cin >> selection;

        if(selection == 1)
        {
            if(gameOneEmpty == true)
            {
                std::string newInitials;
                std::cout << "Enter your initials (exactly three letters): ";
                while(newInitials.length() != 3)
                {
                    std::cin >> newInitials;
                }
                std::ofstream newGame("save1.txt");
                newGame << newInitials << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
                newGame.close();
            }
            return 1;
        }
        if(selection == 2)
        {
            if(gameTwoEmpty == true)
            {
                std::string newInitials;
                std::cout << "Enter your initials (exactly three letters): ";
                while(newInitials.length() != 3)
                {
                    std::cin >> newInitials;
                }
                std::ofstream newGame("save2.txt");
                newGame << newInitials << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
                newGame.close();
            }
            return 2;
        }
        if(selection == 3)
        {
            if(gameThreeEmpty == true)
            {
                std::string newInitials;
                std::cout << "Enter your initials (exactly three letters): ";
                while(newInitials.length() != 3)
                {
                    std::cin >> newInitials;
                }
                std::ofstream newGame("save3.txt");
                newGame << newInitials << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
                newGame.close();
            }
            return 3;
        }
        if(selection == 4)
        {
            if(gameFourEmpty == true)
            {
                std::string newInitials;
                std::cout << "Enter your initials (exactly three letters): ";
                while(newInitials.length() != 3)
                {
                    std::cin >> newInitials;
                }
                std::ofstream newGame("save4.txt");
                newGame << newInitials << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
                newGame.close();
            }
            return 4;
        }
        if(selection == 5)
        {
            while(true)
            {
                std::string confirm;
                std::cout << "Are you sure you want to delete all saved games?" << std::endl;
                std::cout << "(type 'delete' and press enter to confirm): ";
                std::cin >> confirm;
                if(confirm == "delete")
                {
                    //wipe all saves
                    std::ofstream wipeFile1("save1.txt");
                    std::ofstream wipeFile2("save2.txt");
                    std::ofstream wipeFile3("save3.txt");
                    std::ofstream wipeFile4("save4.txt");
                    wipeFile1 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
                    wipeFile2 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
                    wipeFile3 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
                    wipeFile4 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << std::endl;
                    wipeFile1.close();
                    wipeFile2.close();
                    wipeFile3.close();
                    wipeFile4.close();
                    std::cout << "All games deleted" << std::endl << std::endl;
                }
                break;
            }
        }
    }
}

//player statistics
void showStatistics(int gameFile)
{
    clearScreen();
    //declare variables
    std::string playerInitials;
    int playerGamesPlayed;
    int playerGamesWon;
    int playerGamesLost;

    //open game file
    if(gameFile == 1)
    {
        std::ifstream statsFile("save1.txt");
        statsFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
        statsFile.close();
    }
    if(gameFile == 2)
    {
        std::ifstream statsFile("save2.txt");
        statsFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
        statsFile.close();
    }
    if(gameFile == 3)
    {
        std::ifstream statsFile("save3.txt");
        statsFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
        statsFile.close();
    }
    if(gameFile == 4)
    {
        std::ifstream statsFile("save4.txt");
        statsFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
        statsFile.close();
    }

    //display stats
    std::cout << std::endl;
    std::cout << "**** Player Statistics ****\n";
    std::cout << std::endl;
    std::cout << "Player  Games   Won     Lost\n";
    std::cout << "----------------------------\n";
    std::cout << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << std::endl << std::endl;
}

//main menu
void mainMenu(int gameFile)
{
    int selection = 0;

    while(selection != 5)
    {
        std::cout << std::endl;
        std::cout << "---- Main Menu ----\n";
        std::cout << " 1 - Single Player\n";
        std::cout << " 2 - Two Player\n";
        std::cout << " 3 - Statistics\n";
        std::cout << " 4 - Change User\n";
        std::cout << " 5 - Quit\n";
        std::cout << "-------------------\n";
        std::cout << std::endl;
        std::cout << "> ";
        std::cin >> selection;

        if(selection == 1)
        {
            gameOnePlayer(gameFile);
        }
        if(selection == 2)
        {
            gameTwoPlayer();
        }
        if(selection == 3)
        {
            showStatistics(gameFile);
        }
        if(selection == 4)
        {
            gameFile = selectGame();
        }
        if(selection == 5)
        {
            break;
        }
    }
}

//check if save file exists
bool fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}

//update statistics
void updateStats(int gameFile, int x, int y, int z)
{
    //declare variables
    std::string playerInitials;
    int playerGamesPlayed;
    int playerGamesWon;
    int playerGamesLost;

    //update correct game file
    if(gameFile == 1)
    {
        std::ifstream getFile("save1.txt");
        getFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
        playerGamesPlayed += x;
        playerGamesWon += y;
        playerGamesLost += z;
        getFile.close();

        std::ofstream updateFile("save1.txt");
        updateFile << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << std::endl;
        updateFile.close();
    }

    if(gameFile == 2)
    {
        std::ifstream getFile("save2.txt");
        getFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
        playerGamesPlayed += x;
        playerGamesWon += y;
        playerGamesLost += z;
        getFile.close();

        std::ofstream updateFile("save2.txt");
        updateFile << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << std::endl;
        updateFile.close();
    }

    if(gameFile == 3)
    {
        std::ifstream getFile("save3.txt");
        getFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
        playerGamesPlayed += x;
        playerGamesWon += y;
        playerGamesLost += z;
        getFile.close();

        std::ofstream updateFile("save3.txt");
        updateFile << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << std::endl;
        updateFile.close();
    }

    if(gameFile == 4)
    {
        std::ifstream getFile("save4.txt");
        getFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
        playerGamesPlayed += x;
        playerGamesWon += y;
        playerGamesLost += z;
        getFile.close();

        std::ofstream updateFile("save4.txt");
        updateFile << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << std::endl;
        updateFile.close();
    }
}


//end game single (player)
void endGameSingleForPlayer(int gameFile)
{
    updateStats(gameFile, 1, 1, 0);
    std::cout << "\n";
    std::cout << "***************************\n";
    std::cout << "*                         *\n";
    std::cout << "*    HUMAN PLAYER WINS!   *\n";
    std::cout << "*                         *\n";
    std::cout << "***************************\n\n";
}

//end game single (ai)
void endGameSingleForAi(int gameFile)
{
    updateStats(gameFile, 1, 0, 1);
    std::cout << "\n";
    std::cout << "***************************\n";
    std::cout << "*                         *\n";
    std::cout << "*  COMPUTER PLAYER WINS!  *\n";
    std::cout << "*                         *\n";
    std::cout << "***************************\n\n";
}

//end game single (tie)
void endGameSingleTie(int gameFile)
{
    updateStats(gameFile, 1, 0, 0);
    std::cout << "\n";
    std::cout << "***************************\n";
    std::cout << "*                         *\n";
    std::cout << "*        TIE GAME!        *\n";
    std::cout << "*                         *\n";
    std::cout << "***************************\n\n";
}

//end game multiplayer (player 1)
void endGameMultiplayerForPlayerOne()
{

}

//end game mutiplayer (player 2)
void endGameMultiplayerForPlayerTwo()
{

}

//end game multiplayer (tie)
void endGameMultiplayerTie()
{

}

