#include <iostream>
#include <string>

#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED

class Board
{
private:
    std::string A1, A2, A3, B1, B2, B3, C1, C2, C3;

public:
    //default constructor
    Board();

    //destructor
    ~Board();

    //accessor functions
    std::string getA1() const;
    std::string getA2() const;
    std::string getA3() const;
    std::string getB1() const;
    std::string getB2() const;
    std::string getB3() const;
    std::string getC1() const;
    std::string getC2() const;
    std::string getC3() const;

    //mutator functions
    void setA1(std::string);
    void setA2(std::string);
    void setA3(std::string);
    void setB1(std::string);
    void setB2(std::string);
    void setB3(std::string);
    void setC1(std::string);
    void setC2(std::string);
    void setC3(std::string);

    //function declarations
    void displayBoard() const;
        // displays the game board
    int gameOver(bool) const;
        // checks if the game is over
        // 0 = not over
        // 1 = victory for player 1
        // 2 = victory for player 2
        // 3 = tie game
        // @param bool - tieGame variable
    bool spaceIsClear(int) const;
        // checks to see if game space is clear
        // true = space is clear
        // false = space is occupied
        // @param int - space to check

    int calculateAiMove() const;
        // runs ai script to determine next move
        // @return - returns move
        //  1-9 = game spaces
        //  0 = tie game
};

#endif // GAMEBOARD_H_INCLUDED
