#include <iostream>
#include <windows.h>

#include "game.h"
#include "gameChecks.h"
#include "gameDisplays.h"

//game (single player with ai)
void gameOnePlayer(int gameFile)
{
    //declare variables
    std::string n1 = "1", n2 = "2", n3 = "3", n4 = "4", n5 = "5", n6 = "6", n7 = "7", n8 = "8", n9 = "9";
    int playerOneMoves = 0, computerMoves = 0;
    bool tieGame = false;

    //main loop
    while(endGame(n1, n2, n3, n4, n5, n6, n7, n8, n9, tieGame) == 0)
    {
        //show game board
        getGameBoard(n1, n2, n3, n4, n5, n6, n7, n8, n9);
        std::cout << "  *** PLAYER ONE ***\n  Enter your move using 1 - 9: ";

        //declare variables
        int turnOver = 0;

        //player 1 move loop
        while(!turnOver)
        {
            int move = 0;
            while(move!=1 && move!=2 && move!=3 && move!=4 && move!=5 && move!=6 && move!=7 && move!=8 && move!=9)
                {
                    std::cin >> move;
                }
            if(checkSpace(n1,n2,n3,n4,n5,n6,n7,n8,n9,move))
            {
                switch(move)
                {
                    case 1:
                        n1 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 2:
                        n2 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 3:
                        n3 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 4:
                        n4 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 5:
                        n5 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 6:
                        n6 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 7:
                        n7 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 8:
                        n8 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 9:
                        n9 = "X";
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                }
            }
        }

        //check if game is over
        //if yes then break main loop
        //else continue to ai turn
        while(endGame(n1, n2, n3, n4, n5, n6, n7, n8, n9, tieGame) == 0)
        {
            //display game board and wait
            getGameBoard(n1, n2, n3, n4, n5, n6, n7, n8, n9);
            std::cout << std::endl;
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
