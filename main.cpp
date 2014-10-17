#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <sys/stat.h>

//function prototypes
void splashScreen();
void mainMenu(int gameFile);
int selectGame();
void showStatistics(int gameFile);
void getGameBoard(std::string n1, std::string n2, std::string n3, std::string n4, std::string n5, std::string n6, std::string n7, std::string n8, std::string n9);
int endGame(std::string n1, std::string n2, std::string n3, std::string n4, std::string n5, std::string n6, std::string n7, std::string n8, std::string n9, bool tieGame);
void gameOnePlayer(int gameFile);
void gameTwoPlayer();
void endGameSingleForPlayer(int gameFile);
void endGameSingleForAi(int gameFile);
void endGameSingleTie(int gameFile);
void updateStats(int gameFile, int x, int y, int z);
void endGameMultiplayerForPlayerOne();
void endGameMultiplayerForPlayerTwo();
void endGameMultiplayerTie();
bool fileExists(const std::string& filename);

	//main function
	int main()
	{
		splashScreen();
		int gameFile = selectGame();
		mainMenu(gameFile);
		return 0;
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


    // Function: fileExists
    /**
        Check if a file exists
    @param[in] filename - the name of the file to check

    @return    true if the file exists, else false

    */
    bool fileExists(const std::string& filename)
    {
        struct stat buf;
        if (stat(filename.c_str(), &buf) != -1)
        {
            return true;
        }
        return false;
    }

	//select game
	int selectGame()
	{
		//declare varliables
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

	//display game board
	void getGameBoard(std::string n1, std::string n2, std::string n3, std::string n4, std::string n5, std::string n6, std::string n7, std::string n8, std::string n9)
	{

		//clear screen
		std::cout << "\n\n\n\n\n\n\n\n\n\n";

		//display game board
		std::cout << "  -----------------------\n\n";
		std::cout << "    +-----+-----+-----+\n";
		std::cout << "    |     |     |     |\n";
		std::cout << "    |  " << n1 << "  |  " << n2 << "  |  " << n3 << "  |\n";
		std::cout << "    |     |     |     |\n";
		std::cout << "    +-----+-----+-----+\n";
		std::cout << "    |     |     |     |\n";
		std::cout << "    |  " << n4 << "  |  " << n5 << "  |  " << n6 << "  |\n";
		std::cout << "    |     |     |     |\n";
		std::cout << "    +-----+-----+-----+\n";
		std::cout << "    |     |     |     |\n";
		std::cout << "    |  " << n7 << "  |  " << n8 << "  |  " << n9 << "  |\n";
		std::cout << "    |     |     |     |\n";
		std::cout << "    +-----+-----+-----+\n";
		std::cout << "\n";
		std::cout << "  -----------------------\n\n";
	}

	//end game checker
	int endGame(std::string n1, std::string n2, std::string n3, std::string n4, std::string n5, std::string n6, std::string n7, std::string n8, std::string n9, bool tieGame)
	{
		//return values:
		//	1 = win for player 1
		//	2 = victory for player 2 / ai
		//	3 = tie

		//test for tie
		if(tieGame == true)
		{
			return 3;
		}

		//test for player 1
		if((n1 == "X") && (n2 == "X") && (n3 == "X"))
		{
			return 1;
		}
		if((n4 == "X") && (n5 == "X") && (n6 == "X"))
		{
			return 1;
		}
		if((n7 == "X") && (n8 == "X") && (n9 == "X"))
		{
			return 1;
		}
		if((n1 == "X") && (n4 == "X") && (n7 == "X"))
		{
			return 1;
		}
		if((n2 == "X") && (n5 == "X") && (n8 == "X"))
		{
			return 1;
		}
		if((n3 == "X") && (n6 == "X") && (n9 == "X"))
		{
			return 1;
		}
		if((n1 == "X") && (n5 == "X") && (n9 == "X"))
		{
			return 1;
		}
		if((n3 == "X") && (n5 == "X") && (n7 == "X"))
		{
			return 1;
		}

		//test for player 2 / ai
		if((n1 == "O") && (n2 == "O") && (n3 == "O"))
		{
			return 2;
		}
		if((n4 == "O") && (n5 == "O") && (n6 == "O"))
		{
			return 2;
		}
		if((n7 == "O") && (n8 == "O") && (n9 == "O"))
		{
			return 2;
		}
		if((n1 == "O") && (n4 == "O") && (n7 == "O"))
		{
			return 2;
		}
		if((n2 == "O") && (n5 == "O") && (n8 == "O"))
		{
			return 2;
		}
		if((n3 == "O") && (n6 == "O") && (n9 == "O"))
		{
			return 2;
		}
		if((n1 == "O") && (n5 == "O") && (n9 == "O"))
		{
			return 2;
		}
		if((n3 == "O") && (n5 == "O") && (n7 == "O"))
		{
			return 2;
		}

		//if no win conditions or tie then return zero
		return 0;
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

	//game (single player with ai)
	void gameOnePlayer(int gameFile)
	{
		//declare varliables
		std::string n1 = "1";
		std::string n2 = "2";
		std::string n3 = "3";
		std::string n4 = "4";
		std::string n5 = "5";
		std::string n6 = "6";
		std::string n7 = "7";
		std::string n8 = "8";
		std::string n9 = "9";
		int playerOneMoves = 0;
		int computerMoves = 0;
		int move;
		bool tieGame = false;

		//main loop
		while(endGame(n1, n2, n3, n4, n5, n6, n7, n8, n9, tieGame) == 0)
		{
			//show game board
			getGameBoard(n1, n2, n3, n4, n5, n6, n7, n8, n9);
			std::cout << "  *** PLAYER ONE ***\n";
			std::cout << "  Enter your move using 1 - 9: ";

			//player 1 move loop
			while(true)
			{
				std::cin >> move;
				if(move == 1 && n1 == "1")
				{
					n1 = "X";
					playerOneMoves += 1;
					break;
				}
				if(move == 2 && n2 == "2")
				{
					n2 = "X";
					playerOneMoves += 1;
					break;
				}
				if(move == 3 && n3 == "3")
				{
					n3 = "X";
					playerOneMoves += 1;
					break;
				}
				if(move == 4 && n4 == "4")
				{
					n4 = "X";
					playerOneMoves += 1;
					break;
				}
				if(move == 5 && n5 == "5")
				{
					n5 = "X";
					playerOneMoves += 1;
					break;
				}
				if(move == 6 && n6 == "6")
				{
					n6 = "X";
					playerOneMoves += 1;
					break;
				}
				if(move == 7 && n7 == "7")
				{
					n7 = "X";
					playerOneMoves += 1;
					break;
				}
				if(move == 8 && n8 == "8")
				{
					n8 = "X";
					playerOneMoves += 1;
					break;
				}
				if(move == 9 && n9 == "9")
				{
					n9 = "X";
					playerOneMoves += 1;
					break;
				}
			}

			//check if game is over
			//if yes then break main loop
			//else continue to ai turn
			while(endGame(n1, n2, n3, n4, n5, n6, n7, n8, n9, tieGame) == 0)
			{
				//display game board and wait
				getGameBoard(n1, n2, n3, n4, n5, n6, n7, n8, n9);
				Sleep(1000);

				//ai logic (defense)
				if((n1 == "X") && (n5 == "X") && (n9 == "9"))
				{
					n9 = "O";
					computerMoves += 1;
					break;
				}
				if((n1 == "1") && (n5 == "X") && (n9 == "X"))
				{
					n1 = "O";
					computerMoves += 1;
					break;
				}
				if((n1 == "X") && (n5 == "5") && (n9 == "X"))
				{
					n5 = "O";
					computerMoves += 1;
					break;
				}
				if((n3 == "X") && (n5 == "X") && (n7 == "7"))
				{
					n7 = "O";
					computerMoves += 1;
					break;
				}
				if((n3 == "3") && (n5 == "X") && (n7 == "X"))
				{
					n3 = "O";
					computerMoves += 1;
					break;
				}
				if((n3 == "X") && (n5 == "5") && (n7 == "X"))
				{
					n5 = "O";
					computerMoves += 1;
					break;
				}
				if((n1 == "X") && (n2 == "X") && (n3 == "3"))
				{
					n3 = "O";
					computerMoves += 1;
					break;
				}
				if((n1 == "1") && (n2 == "X") && (n3 == "X"))
				{
					n1 = "O";
					computerMoves += 1;
					break;
				}
				if((n1 == "X") && (n2 == "2") && (n3 == "X"))
				{
					n2 = "O";
					computerMoves += 1;
					break;
				}
				if((n4 == "X") && (n5 == "X") && (n6 == "6"))
				{
					n6 = "O";
					computerMoves += 1;
					break;
				}
				if((n4 == "4") && (n5 == "X") && (n6 == "X"))
				{
					n4 = "O";
					computerMoves += 1;
					break;
				}
				if((n4 == "X") && (n5 == "5") && (n6 == "X"))
				{
					n5 = "O";
					computerMoves += 1;
					break;
				}
				if((n7 == "X") && (n8 == "X") && (n9 == "9"))
				{
					n9 = "O";
					computerMoves += 1;
					break;
				}
				if((n7 == "7") && (n8 == "X") && (n9 == "X"))
				{
					n7 = "O";
					computerMoves += 1;
					break;
				}
				if((n7 == "X") && (n8 == "8") && (n9 == "X"))
				{
					n8 = "O";
					computerMoves += 1;
					break;
				}
                if((n1 == "X") && (n4 == "X") && (n7 == "7"))
				{
					n7 = "O";
					computerMoves += 1;
					break;
				}
				if((n1 == "1") && (n4 == "X") && (n7 == "X"))
				{
					n1 = "O";
					computerMoves += 1;
					break;
				}
				if((n1 == "X") && (n4 == "4") && (n7 == "X"))
				{
					n4 = "O";
					computerMoves += 1;
					break;
				}
				if((n2 == "X") && (n5 == "X") && (n8 == "8"))
				{
					n8 = "O";
					computerMoves += 1;
					break;
				}
				if((n2 == "2") && (n5 == "X") && (n8 == "X"))
				{
					n2 = "O";
					computerMoves += 1;
					break;
				}
				if((n2 == "X") && (n5 == "4") && (n8 == "X"))
				{
					n5 = "O";
					computerMoves += 1;
					break;
				}
				if((n3 == "X") && (n6 == "X") && (n9 == "9"))
				{
					n9 = "O";
					computerMoves += 1;
					break;
				}
				if((n3 == "3") && (n6 == "X") && (n6 == "X"))
				{
					n3 = "O";
					computerMoves += 1;
					break;
				}
				if((n3 == "X") && (n6 == "6") && (n9 == "X"))
				{
					n6 = "O";
					computerMoves += 1;
					break;
				}

				//ai logic (offense)
				if((n1 != "X") && (n5 != "X") && (n9 != "X"))
				{
					if(n5 != "O")
					{
						n5 = "O";
						computerMoves += 1;
						break;
					}
					if(n1 != "O")
					{
						n1 = "O";
						computerMoves += 1;
						break;
					}
					if(n9 != "O")
					{
						n9 = "O";
						computerMoves += 1;
						break;
					}
				}
				if((n3 != "X") && (n5 != "X") && (n7 != "X"))
				{
					if(n5 != "O")
					{
						n5 = "O";
						computerMoves += 1;
						break;
					}
					if(n3 != "O")
					{
						n3 = "O";
						computerMoves += 1;
						break;
					}
					if(n7 != "O")
					{
						n7 = "O";
						computerMoves += 1;
						break;
					}
				}
				if((n4 != "X") && (n5 != "X") && (n6 != "X"))
				{
					if(n5 != "O")
					{
						n5 = "O";
						computerMoves += 1;
						break;
					}
					if(n4 != "O")
					{
						n4 = "O";
						computerMoves += 1;
						break;
					}
					if(n6 != "O")
					{
						n6 = "O";
						computerMoves += 1;
						break;
					}
				}
				if((n2 != "X") && (n5 != "X") && (n8 != "X"))
				{
					if(n5 != "O")
					{
						n5 = "O";
						computerMoves += 1;
						break;
					}
					if(n2 != "O")
					{
						n2 = "O";
						computerMoves += 1;
						break;
					}
					if(n8 != "O")
					{
						n8 = "O";
						computerMoves += 1;
						break;
					}
				}
				if((n1 != "X") && (n2 != "X") && (n3 != "X"))
				{
					if(n1 != "O")
					{
						n1 = "O";
						computerMoves += 1;
						break;
					}
					if(n2 != "O")
					{
						n2 = "O";
						computerMoves += 1;
						break;
					}
					if(n3 != "O")
					{
						n3 = "O";
						computerMoves += 1;
						break;
					}
				}
				if((n1 != "X") && (n4 != "X") && (n7 != "X"))
				{
					if(n1 != "O")
					{
						n1 = "O";
						computerMoves += 1;
						break;
					}
					if(n4 != "O")
					{
						n4 = "O";
						computerMoves += 1;
						break;
					}
					if(n7 != "O")
					{
						n7 = "O";
						computerMoves += 1;
						break;
					}
				}
				if((n7 != "X") && (n8 != "X") && (n9 != "X"))
				{
					if(n7 != "O")
					{
						n7 = "O";
						computerMoves += 1;
						break;
					}
					if(n8 != "O")
					{
						n8 = "O";
						computerMoves += 1;
						break;
					}
					if(n9 != "O")
					{
						n9 = "O";
						computerMoves += 1;
						break;
					}
				}
				if((n3 != "X") && (n6 != "X") && (n9 != "X"))
				{
					if(n3 != "O")
					{
						n3 = "O";
						computerMoves += 1;
						break;
					}
					if(n6 != "O")
					{
						n6 = "O";
						computerMoves += 1;
						break;
					}
					if(n9 != "O")
					{
						n9 = "O";
						computerMoves += 1;
						break;
					}
				}

				//if no possible moves
				else
				{
					tieGame = true;
					break;
				}
			}
		}

		//display final game board
		getGameBoard(n1, n2, n3, n4, n5, n6, n7, n8, n9);

		//check how game finished and call corresponding ending
		int gameEnd = endGame(n1, n2, n3, n4, n5, n6, n7, n8, n9, tieGame);
		if(gameEnd == 1)
		{
			endGameSingleForPlayer(gameFile);
		}
		if(gameEnd == 2)
		{
			endGameSingleForAi(gameFile);
		}
		if(gameEnd == 3)
		{
			endGameSingleTie(gameFile);
		}
	}

	//game (multiplayer)
	void gameTwoPlayer()
	{

	}
