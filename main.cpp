#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

//function prototypes
void splashScreen();
void mainMenu(int gameFile);
int selectGame();
void showStatistics(int gameFile);
void getGameBoard(string n1, string n2, string n3, string n4, string n5, string n6, string n7, string n8, string n9);
int endGame(string n1, string n2, string n3, string n4, string n5, string n6, string n7, string n8, string n9, bool tieGame);
void gameOnePlayer(int gameFile);
void gameTwoPlayer();
void endGameSingleForPlayer(int gameFile);
void endGameSingleForAi(int gameFile);
void endGameSingleTie(int gameFile);
void updateStats(int gameFile, int x, int y, int z);
void endGameMultiplayerForPlayerOne();
void endGameMultiplayerForPlayerTwo();
void endGameMultiplayerTie();


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
		cout << "\n\n";
		cout << "  *******************************************\n";
	  	cout << "  *******************************************\n";
	  	cout << "  **                                       **\n";
	  	cout << "  **              TIC-TAC-TOE              **\n";
	  	cout << "  **                                       **\n";
		cout << "  *******************************************\n";
	  	cout << "  *******************************************\n\n";
	}

	//main menu
	void mainMenu(int gameFile)
	{
		int selection = 0;

		while(selection != 5)
		{
			cout << endl;
			cout << "---- Main Menu ----\n";
			cout << " 1 - Single Player\n";
			cout << " 2 - Two Player\n";
			cout << " 3 - Statistics\n";
			cout << " 4 - Change User\n";
			cout << " 5 - Quit\n";
			cout << "-------------------\n";
			cout << endl;
			cout << "> ";
			cin >> selection;

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

	//select game
	int selectGame()
	{
		//declare varliables
		int selection;
		string gameOneInitials;
		string gameTwoInitials;
		string gameThreeInitials;
		string gameFourInitials;
		bool gameOneEmpty = false;
		bool gameTwoEmpty = false;
		bool gameThreeEmpty = false;
		bool gameFourEmpty = false;

		while(true)
		{

			//open files and associate objects
			ifstream saveOne("save1.txt");
			ifstream saveTwo("save2.txt");
			ifstream saveThree("save3.txt");
			ifstream saveFour("save4.txt");

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
			cout << "+-------------+ +-------------+\n";
			cout << "|             | |             |\n";
			cout << "| GAME 1: " << gameOneInitials << " | | GAME 2: " << gameTwoInitials << " |\n";
			cout << "|             | |             |\n";
			cout << "+-------------+ +-------------+\n";
			cout << endl;
			cout << "+-------------+ +-------------+\n";
			cout << "|             | |             |\n";
			cout << "| GAME 3: " << gameThreeInitials << " | | GAME 4: " << gameFourInitials << " |\n";
			cout << "|             | |             |\n";
			cout << "+-------------+ +-------------+\n";
			cout << endl;

			//close files
			saveOne.close();
			saveTwo.close();
			saveThree.close();
			saveFour.close();

			//select game and return value
			cout << "[1-4]	Select Game" << endl;
			cout << "[5]	Reset All Games" << endl;
			cin >> selection;

			if(selection == 1)
			{
				if(gameOneEmpty == true)
				{
					string newInitials;
					cout << "Enter your initials: ";
					cin >> newInitials;
					ofstream newGame("save1.txt");
					newGame << newInitials << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
					newGame.close();
				}
				return 1;
			}
			if(selection == 2)
			{
				if(gameTwoEmpty == true)
				{
					string newInitials;
					cout << "Enter your initials: ";
					cin >> newInitials;
					ofstream newGame("save2.txt");
					newGame << newInitials << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
					newGame.close();
				}
				return 2;
			}
			if(selection == 3)
			{
				if(gameThreeEmpty == true)
				{
					string newInitials;
					cout << "Enter your initials: ";
					cin >> newInitials;
					ofstream newGame("save3.txt");
					newGame << newInitials << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
					newGame.close();
				}
				return 3;
			}
			if(selection == 4)
			{
				if(gameFourEmpty == true)
				{
					string newInitials;
					cout << "Enter your initials: ";
					cin >> newInitials;
					ofstream newGame("save4.txt");
					newGame << newInitials << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
					newGame.close();
				}
				return 4;
			}
			if(selection == 5)
			{
				while(true)
				{
					int confirm;
					cout << "Are you sure you want to delete all saved games?" << endl;
					cout << "1 - YES" << endl;
					cout << "2 - NO" << endl;
					cin >> confirm;
					if(confirm == 1)
					{
						//wipe all saves
						ofstream wipeFile1("save1.txt");
						ofstream wipeFile2("save2.txt");
						ofstream wipeFile3("save3.txt");
						ofstream wipeFile4("save4.txt");
						wipeFile1 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
						wipeFile2 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
						wipeFile3 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
						wipeFile4 << "---" << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;
						wipeFile1.close();
						wipeFile2.close();
						wipeFile3.close();
						wipeFile4.close();
						cout << "All games deleted" << endl << endl;
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
		string playerInitials;
		int playerGamesPlayed;
		int playerGamesWon;
		int playerGamesLost;

		//open game file
		if(gameFile == 1)
		{
			ifstream statsFile("save1.txt");
			statsFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
			statsFile.close();
		}
		if(gameFile == 2)
		{
			ifstream statsFile("save2.txt");
			statsFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
			statsFile.close();
		}
		if(gameFile == 3)
		{
			ifstream statsFile("save3.txt");
			statsFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
			statsFile.close();
		}
		if(gameFile == 4)
		{
			ifstream statsFile("save4.txt");
			statsFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
			statsFile.close();
		}

		//display stats
		cout << endl;
		cout << "**** Player Statistics ****\n";
		cout << endl;
		cout << "Player  Games   Won     Lost\n";
		cout << "----------------------------\n";
		cout << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << endl << endl;
	}

	//display game board
	void getGameBoard(string n1, string n2, string n3, string n4, string n5, string n6, string n7, string n8, string n9)
	{

		//clear screen
		cout << "\n\n\n\n\n\n\n\n\n\n";

		//display game board
		cout << "  -----------------------\n\n";
		cout << "    +-----+-----+-----+\n";
		cout << "    |     |     |     |\n";
		cout << "    |  " << n1 << "  |  " << n2 << "  |  " << n3 << "  |\n";
		cout << "    |     |     |     |\n";
		cout << "    +-----+-----+-----+\n";
		cout << "    |     |     |     |\n";
		cout << "    |  " << n4 << "  |  " << n5 << "  |  " << n6 << "  |\n";
		cout << "    |     |     |     |\n";
		cout << "    +-----+-----+-----+\n";
		cout << "    |     |     |     |\n";
		cout << "    |  " << n7 << "  |  " << n8 << "  |  " << n9 << "  |\n";
		cout << "    |     |     |     |\n";
		cout << "    +-----+-----+-----+\n";
		cout << "\n";
		cout << "  -----------------------\n\n";
	}

	//end game checker
	int endGame(string n1, string n2, string n3, string n4, string n5, string n6, string n7, string n8, string n9, bool tieGame)
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
			cout << "\n";
			cout << "***************************\n";
			cout << "*                         *\n";
			cout << "*    HUMAN PLAYER WINS!   *\n";
			cout << "*                         *\n";
			cout << "***************************\n\n";
		}

		//end game single (ai)
		void endGameSingleForAi(int gameFile)
		{
			updateStats(gameFile, 1, 0, 1);
			cout << "\n";
			cout << "***************************\n";
			cout << "*                         *\n";
			cout << "*  COMPUTER PLAYER WINS!  *\n";
			cout << "*                         *\n";
			cout << "***************************\n\n";
		}

		//end game single (tie)
		void endGameSingleTie(int gameFile)
		{
			updateStats(gameFile, 1, 0, 0);
			cout << "\n";
			cout << "***************************\n";
			cout << "*                         *\n";
			cout << "*        TIE GAME!        *\n";
			cout << "*                         *\n";
			cout << "***************************\n\n";
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
		string playerInitials;
		int playerGamesPlayed;
		int playerGamesWon;
		int playerGamesLost;

		//update correct game file
		if(gameFile == 1)
		{
			ifstream getFile("save1.txt");
			getFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
			playerGamesPlayed += x;
			playerGamesWon += y;
			playerGamesLost += z;
			getFile.close();

			ofstream updateFile("save1.txt");
			updateFile << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << endl;
			updateFile.close();
		}

		if(gameFile == 2)
		{
			ifstream getFile("save2.txt");
			getFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
			playerGamesPlayed += x;
			playerGamesWon += y;
			playerGamesLost += z;
			getFile.close();

			ofstream updateFile("save2.txt");
			updateFile << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << endl;
			updateFile.close();
		}

		if(gameFile == 3)
		{
			ifstream getFile("save3.txt");
			getFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
			playerGamesPlayed += x;
			playerGamesWon += y;
			playerGamesLost += z;
			getFile.close();

			ofstream updateFile("save3.txt");
			updateFile << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << endl;
			updateFile.close();
		}

		if(gameFile == 4)
		{
			ifstream getFile("save4.txt");
			getFile >> playerInitials >> playerGamesPlayed >> playerGamesWon >> playerGamesLost;
			playerGamesPlayed += x;
			playerGamesWon += y;
			playerGamesLost += z;
			getFile.close();

			ofstream updateFile("save4.txt");
			updateFile << playerInitials << "\t" << playerGamesPlayed << "\t" << playerGamesWon << "\t" << playerGamesLost << endl;
			updateFile.close();
		}
	}

	//game (single player with ai)
	void gameOnePlayer(int gameFile)
	{
		//declare varliables
		string n1 = "1";
		string n2 = "2";
		string n3 = "3";
		string n4 = "4";
		string n5 = "5";
		string n6 = "6";
		string n7 = "7";
		string n8 = "8";
		string n9 = "9";
		int playerOneMoves = 0;
		int computerMoves = 0;
		int move;
		bool tieGame = false;

		//main loop
		while(endGame(n1, n2, n3, n4, n5, n6, n7, n8, n9, tieGame) == 0)
		{
			//show game board
			getGameBoard(n1, n2, n3, n4, n5, n6, n7, n8, n9);
			cout << "  *** PLAYER ONE ***\n";
			cout << "  Enter your move using 1 - 9: ";

			//player 1 move loop
			while(true)
			{
				cin >> move;
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
