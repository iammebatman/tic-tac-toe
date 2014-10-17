#include <fstream>

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
