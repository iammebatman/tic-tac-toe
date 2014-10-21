#include <iostream>
#include <windows.h>

#include "game.h"
#include "gameBoard.h"
#include "gameOperations.h"

//game (single player with ai)
void gameOnePlayer(int gameFile)
{
    //declare variables
    int playerOneMoves = 0, computerMoves = 0;
    bool tieGame = false;

    //create game board object (using default constructor)
    Board game;

    //main loop
    while(!game.gameOver(tieGame))
    {
        //show game board
        clearScreen();
        game.displayBoard();
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
            if(game.spaceIsClear(move))
            {
                switch(move)
                {
                    case 1:
                        game.setA1("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 2:
                        game.setA2("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 3:
                        game.setA3("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 4:
                        game.setB1("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 5:
                        game.setB2("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 6:
                        game.setB3("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 7:
                        game.setC1("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 8:
                        game.setC2("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                    case 9:
                        game.setC2("X");
                        playerOneMoves += 1;
                        turnOver = 1;
                        break;
                }
            }
        }

        //check if game is over
        //if yes then break main loop
        //else continue to ai turn
        if(!game.gameOver(tieGame))
        {
            //display game board and wait
            clearScreen();
            game.displayBoard();
            std::cout << std::endl;
            Sleep(1000);

            //run ai script and return move
            int aiMove = game.calculateAiMove();

            //commit ai move to board
            switch(aiMove)
            {
                case 0:
                    tieGame = true;
                    computerMoves += 1;
                    break;
                case 1:
                    game.setA1("O");
                    computerMoves += 1;
                    break;
                case 2:
                    game.setA2("O");
                    computerMoves += 1;
                    break;
                case 3:
                    game.setA3("O");
                    computerMoves += 1;
                    break;
                case 4:
                    game.setB1("O");
                    computerMoves += 1;
                    break;
                case 5:
                    game.setB2("O");
                    computerMoves += 1;
                    break;
                case 6:
                    game.setB3("O");
                    computerMoves += 1;
                    break;
                case 7:
                    game.setC1("O");
                    computerMoves += 1;
                    break;
                case 8:
                    game.setC2("O");
                    computerMoves += 1;
                    break;
                case 9:
                    game.setC3("O");
                    computerMoves += 1;
                    break;
            }
        }
    }

    //display final game board
    clearScreen();
    game.displayBoard();

    //check how game finished and call corresponding ending
    int gameEnd = game.gameOver(tieGame);
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
