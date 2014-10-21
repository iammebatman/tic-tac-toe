#include "gameBoard.h"

Board::Board()
{
    A1 = "1";
    A2 = "2";
    A3 = "3";
    B1 = "4";
    B2 = "5";
    B3 = "6";
    C1 = "7";
    C2 = "8";
    C3 = "9";
}

Board::~Board()
{

}

std::string Board::getA1() const
{
    return A1;
}

std::string Board::getA2() const
{
    return A2;
}

std::string Board::getA3() const
{
    return A3;
}

std::string Board::getB1() const
{
    return B1;
}

std::string Board::getB2() const
{
    return B2;
}

std::string Board::getB3() const
{
    return B3;
}

std::string Board::getC1() const
{
    return C1;
}

std::string Board::getC2() const
{
    return C2;
}

std::string Board::getC3() const
{
    return C3;
}

void Board::setA1(std::string n)
{
    A1 = n;
}

void Board::setA2(std::string n)
{
    A2 = n;
}

void Board::setA3(std::string n)
{
    A3 = n;
}

void Board::setB1(std::string n)
{
    B1 = n;
}

void Board::setB2(std::string n)
{
    B2 = n;
}

void Board::setB3(std::string n)
{
    B3 = n;
}

void Board::setC1(std::string n)
{
    C1 = n;
}

void Board::setC2(std::string n)
{
    C2 = n;
}

void Board::setC3(std::string n)
{
    C3 = n;
}

void Board::displayBoard() const
{
    //display game board
    std::cout << "  -----------------------\n\n";
    std::cout << "    +-----+-----+-----+\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  " << A1 << "  |  " << A2 << "  |  " << A3 << "  |\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    +-----+-----+-----+\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  " << B1 << "  |  " << B2 << "  |  " << B3 << "  |\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    +-----+-----+-----+\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  " << C1 << "  |  " << C2 << "  |  " << C3 << "  |\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    +-----+-----+-----+\n";
    std::cout << "\n";
    std::cout << "  -----------------------\n\n";
}

int Board::gameOver(bool tieGame) const
{
    //test for tie
    if(tieGame == true)
    {
        return 3;
    }

    //test for player 1
    else if (A1 + A2 + A3 == "XXX")
    {
        return 1;
    }
    else if (B1 + B2 + B3 == "XXX")
    {
        return 1;
    }
    else if (C1 + C2 + C3 == "XXX")
    {
        return 1;
    }
    else if (A1 + B1 + C1 == "XXX")
    {
        return 1;
    }
    else if (A2 + B2 + C2 == "XXX")
    {
        return 1;
    }
    else if (A3 + B3 + C3 == "XXX")
    {
        return 1;
    }
    else if (A1 + B2 + C3 == "XXX")
    {
        return 1;
    }
    else if (A3 + B2 + C1 == "XXX")
    {
        return 1;
    }

    //test for player 2 / ai
    else if (A1 + A2 + A3 == "OOO")
    {
        return 2;
    }
    else if (B1 + B2 + B3 == "OOO")
    {
        return 2;
    }
    else if (C1 + C2 + C3 == "OOO")
    {
        return 2;
    }
    else if (A1 + B1 + C1 == "OOO")
    {
        return 2;
    }
    else if (A2 + B2 + C2 == "OOO")
    {
        return 2;
    }
    else if (A3 + B3 + C3 == "OOO")
    {
        return 2;
    }
    else if (A1 + B2 + C3 == "OOO")
    {
        return 2;
    }
    else if (A3 + B2 + C1 == "OOO")
    {
        return 2;
    }

    //if no win conditions then return zero
    return 0;
}

bool Board::spaceIsClear(int n) const
{
     //declare variables
    bool spaceClear = false;

    //check if space is open and return true otherwise return false
    switch(n)
    {
        case 1:
            if(A1=="1"){spaceClear = true;}
            break;
        case 2:
            if(A2=="2"){spaceClear = true;}
            break;
        case 3:
            if(A3=="3"){spaceClear = true;}
            break;
        case 4:
            if(B1=="4"){spaceClear = true;}
            break;
        case 5:
            if(B2=="5"){spaceClear = true;}
            break;
        case 6:
            if(B3=="6"){spaceClear = true;}
            break;
        case 7:
            if(C1=="7"){spaceClear = true;}
            break;
        case 8:
            if(C2=="8"){spaceClear = true;}
            break;
        case 9:
            if(C3=="9"){spaceClear = true;}
            break;
    }
    return spaceClear;
}

int Board::calculateAiMove() const
{
    return 0;
}
