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
    //calculate win
    if      (A1+A2+A3 == "1OO"){return 1;}
    else if (A1+A2+A3 == "O2O"){return 2;}
    else if (A1+A2+A3 == "OO3"){return 3;}
        //top row horizontal

    else if (B1+B2+B3 == "4OO"){return 4;}
    else if (B1+B2+B3 == "O5O"){return 5;}
    else if (B1+B2+B3 == "OO6"){return 6;}
        //middle row horizontal

    else if (C1+C2+C3 == "7OO"){return 7;}
    else if (C1+C2+C3 == "O8O"){return 8;}
    else if (C1+C2+C3 == "OO9"){return 9;}
        //bottom row horizontal

    else if (A1+B1+C1 == "1OO"){return 1;}
    else if (A1+B1+C1 == "O4O"){return 4;}
    else if (A1+B1+C1 == "OO7"){return 7;}
        //left row vertical

    else if (A2+B2+C2 == "2OO"){return 2;}
    else if (A2+B2+C2 == "O5O"){return 5;}
    else if (A2+B2+C2 == "OO8"){return 8;}
        //middle row vertical

    else if (A3+B3+C3 == "3OO"){return 3;}
    else if (A3+B3+C3 == "O6O"){return 6;}
    else if (A3+B3+C3 == "OO9"){return 9;}
        //right row vertical

    else if (A1+B2+C3 == "1OO"){return 1;}
    else if (A1+B2+C3 == "O5O"){return 5;}
    else if (A1+B2+C3 == "OO9"){return 9;}
        //diagonal 1

    else if (A3+B2+C1 == "3OO"){return 3;}
    else if (A3+B2+C1 == "O5O"){return 5;}
    else if (A3+B2+C1 == "OO7"){return 7;}
        //diagonal 2


    //calculate defense
    if      (A1+A2+A3 == "1XX"){return 1;}
    else if (A1+A2+A3 == "X2X"){return 2;}
    else if (A1+A2+A3 == "XX3"){return 3;}
        //top row horizontal

    else if (B1+B2+B3 == "4XX"){return 4;}
    else if (B1+B2+B3 == "X5X"){return 5;}
    else if (B1+B2+B3 == "XX6"){return 6;}
        //middle row horizontal

    else if (C1+C2+C3 == "7XX"){return 7;}
    else if (C1+C2+C3 == "X8X"){return 8;}
    else if (C1+C2+C3 == "XX9"){return 9;}
        //bottom row horizontal

    else if (A1+B1+C1 == "1XX"){return 1;}
    else if (A1+B1+C1 == "X4X"){return 4;}
    else if (A1+B1+C1 == "XX7"){return 7;}
        //left row vertical

    else if (A2+B2+C2 == "2XX"){return 2;}
    else if (A2+B2+C2 == "X5X"){return 5;}
    else if (A2+B2+C2 == "XX8"){return 8;}
        //middle row vertical

    else if (A3+B3+C3 == "3XX"){return 3;}
    else if (A3+B3+C3 == "X6X"){return 6;}
    else if (A3+B3+C3 == "XX9"){return 9;}
        //right row vertical

    else if (A1+B2+C3 == "1XX"){return 1;}
    else if (A1+B2+C3 == "X5X"){return 5;}
    else if (A1+B2+C3 == "XX9"){return 9;}
        //diagonal 1

    else if (A3+B2+C1 == "3XX"){return 3;}
    else if (A3+B2+C1 == "X5X"){return 5;}
    else if (A3+B2+C1 == "XX7"){return 7;}
        //diagonal 2


    //calculate offense
    else if ((B2 == "5") || (B2 == "O"))
    //if middle is open occupied by ai
    {
        if ((A1+C3 == "19") || (A1+C3 == "1O") || (A1+C3 == "O9"))
        //and diagonal 1 is possible
        {
            if (B2 == "5")
            //and middle is open
            {
                return 5;
            }
            else if (A1+C3 == "1O")
            //and only A1 is open
            {
                return 1;
            }
            else if (A1+C3== "O9")
            //and only C3 is open
            {
                return 9;
            }
            else
            //and both A1 and C3 are open
            {
                if (rand() % 2 + 1 == 1)
                //randomly return 1 or 9
                {
                    return 1;
                }
                else
                {
                    return 9;
                }
            }
        }

        else if ((A3+C1 == "37") || (A3+C1 == "3O") || (A3+C1 == "O7"))
        //and diagonal 2 is possible
        {
            if (B2 == "5")
            //and middle is open
            {
                return 5;
            }
            else if (A3+C1 == "3O")
            //and only A3 is open
            {
                return 3;
            }
            else if (A3+C1 == "O7")
            //and only C1 is open
            {
                return 7;
            }
            else
            //and both A3 and C1 are open
            {
                if (rand() % 2 + 1 == 1)
                //randomly return 3 or 7
                {
                    return 3;
                }
                else
                {
                    return 7;
                }
            }
        }
    }
        //diagonal moves


    else if ((A1+A2+A3 == "123") || (A1+A2+A3 == "O23") || (A1+A2+A3 == "1O3") || (A1+A2+A3 == "12O"))
    //if top row horizontal is possible
    {
        if (A1+A2+A3 == "123")
        //and all three spaces are open
        {
            int x = rand() % 3 + 1;
            //randomly return 1, 2 or 3
            if (x == 1)
            {
                return 1;
            }
            else if (x == 2)
            {
                return 2;
            }
            else if (x == 3)
            {
                return 3;
            }
        }
        else if (A1+A2+A3 == "O23")
        //and right two spaces are open
        {
            //randomly return 2 or 3
            if (rand() % 2 + 1 == 1)
            {
                return 2;
            }
            else
            {
                return 3;
            }
        }
        else if (A1+A2+A3 == "1O3")
        //and outside spaces are open
        {
            //randomly return 1 or 3
            if (rand() % 2 + 1 == 1)
            {
                return 1;
            }
            else
            {
                return 3;
            }
        }
        else if (A1+A2+A3 == "12O")
        //and left two spaces are open
        {
            //randomly return 1 or 2
            if (rand() % 2 + 1 == 1)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }

    }
        //top row horizontal moves

    else if ((B1+B2+B3 == "456") || (B1+B2+B3 == "O56") || (B1+B2+B3 == "4O6") || (B1+B2+B3 == "45O"))
    //if middle row horizontal is possible
    {
        if (B1+B2+B3 == "456")
        //and all three spaces are open
        {
            int x = rand() % 3 + 1;
            //randomly return 4, 5 or 6
            if (x == 1)
            {
                return 4;
            }
            else if (x == 2)
            {
                return 5;
            }
            else if (x == 3)
            {
                return 6;
            }
        }
        else if (B1+B2+B3 == "O56")
        //and right two spaces are open
        {
            //randomly return 5 or 6
            if (rand() % 2 + 1 == 1)
            {
                return 5;
            }
            else
            {
                return 6;
            }
        }
        else if (B1+B2+B3 == "4O6")
        //and outside spaces are open
        {
            //randomly return 4 or 6
            if (rand() % 2 + 1 == 1)
            {
                return 4;
            }
            else
            {
                return 6;
            }
        }
        else if (B1+B2+B3 == "45O")
        //and left two spaces are open
        {
            //randomly return 4 or 5
            if (rand() % 2 + 1 == 1)
            {
                return 4;
            }
            else
            {
                return 5;
            }
        }

    }
        //middle row horizontal moves

    else if ((C1+C2+C3 == "789") || (C1+C2+C3 == "O89") || (C1+C2+C3 == "7O9") || (C1+C2+C3 == "78O"))
    //if bottom row horizontal is possible
    {
        if (C1+C2+C3 == "789")
        //and all three spaces are open
        {
            int x = rand() % 3 + 1;
            //randomly return 7, 8 or 9
            if (x == 1)
            {
                return 7;
            }
            else if (x == 2)
            {
                return 8;
            }
            else if (x == 3)
            {
                return 9;
            }
        }
        else if (C1+C2+C3 == "O89")
        //and right two spaces are open
        {
            //randomly return 8 or 9
            if (rand() % 2 + 1 == 1)
            {
                return 8;
            }
            else
            {
                return 9;
            }
        }
        else if (C1+C2+C3 == "7O9")
        //and outside spaces are open
        {
            //randomly return 7 or 9
            if (rand() % 2 + 1 == 1)
            {
                return 7;
            }
            else
            {
                return 9;
            }
        }
        else if (C1+C2+C3 == "78O")
        //and left two spaces are open
        {
            //randomly return 7 or 8
            if (rand() % 2 + 1 == 1)
            {
                return 7;
            }
            else
            {
                return 8;
            }
        }

    }
        //bottom row horizontal moves

    else if ((A1+B1+C1 == "147") || (A1+B1+C1 == "O47") || (A1+B1+C1 == "1O7") || (A1+B1+C1 == "14O"))
    //if left row vertical is possible
    {
        if (A1+B1+C1 == "147")
        //and all three spaces are open
        {
            int x = rand() % 3 + 1;
            //randomly return 1, 4 or 7
            if (x == 1)
            {
                return 1;
            }
            else if (x == 2)
            {
                return 4;
            }
            else if (x == 3)
            {
                return 7;
            }
        }
        else if (A1+B1+C1 == "O47")
        //and bottom two spaces are open
        {
            //randomly return 4 or 7
            if (rand() % 2 + 1 == 1)
            {
                return 4;
            }
            else
            {
                return 7;
            }
        }
        else if (A1+B1+C1 == "1O7")
        //and outside spaces are open
        {
            //randomly return 1 or 7
            if (rand() % 2 + 1 == 1)
            {
                return 1;
            }
            else
            {
                return 7;
            }
        }
        else if (A1+B1+C1 == "14O")
        //and top two spaces are open
        {
            //randomly return 1 or 4
            if (rand() % 2 + 1 == 1)
            {
                return 1;
            }
            else
            {
                return 4;
            }
        }

    }
        //left row vertical moves

    else if ((A2+B2+C2 == "258") || (A2+B2+C2 == "O58") || (A2+B2+C2 == "2O8") || (A2+B2+C2 == "25O"))
    //if middle row vertical is possible
    {
        if (A2+B2+C2 == "258")
        //and all three spaces are open
        {
            int x = rand() % 3 + 1;
            //randomly return 2, 5 or 8
            if (x == 1)
            {
                return 2;
            }
            else if (x == 2)
            {
                return 5;
            }
            else if (x == 3)
            {
                return 8;
            }
        }
        else if (A2+B2+C2 == "O58")
        //and bottom two spaces are open
        {
            //randomly return 5 or 8
            if (rand() % 2 + 1 == 1)
            {
                return 5;
            }
            else
            {
                return 8;
            }
        }
        else if (A2+B2+C2 == "2O8")
        //and outside spaces are open
        {
            //randomly return 2 or 8
            if (rand() % 2 + 1 == 1)
            {
                return 2;
            }
            else
            {
                return 8;
            }
        }
        else if (A2+B2+C2 == "25O")
        //and top two spaces are open
        {
            //randomly return 2 or 5
            if (rand() % 2 + 1 == 1)
            {
                return 2;
            }
            else
            {
                return 5;
            }
        }

    }
        //middle row vertical moves

    else if ((A3+B3+C3 == "369") || (A3+B3+C3 == "O69") || (A3+B3+C3 == "3O9") || (A3+B3+C3 == "36O"))
    //if right row vertical is possible
    {
        if (A3+B3+C3 == "369")
        //and all three spaces are open
        {
            int x = rand() % 3 + 1;
            //randomly return 3, 6 or 9
            if (x == 1)
            {
                return 3;
            }
            else if (x == 2)
            {
                return 6;
            }
            else if (x == 3)
            {
                return 9;
            }
        }
        else if (A3+B3+C3 == "O69")
        //and bottom two spaces are open
        {
            //randomly return 6 or 9
            if (rand() % 2 + 1 == 1)
            {
                return 6;
            }
            else
            {
                return 9;
            }
        }
        else if (A3+B3+C3 == "3O9")
        //and outside spaces are open
        {
            //randomly return 3 or 9
            if (rand() % 2 + 1 == 1)
            {
                return 3;
            }
            else
            {
                return 9;
            }
        }
        else if (A3+B3+C3 == "36O")
        //and top two spaces are open
        {
            //randomly return 3 or 6
            if (rand() % 2 + 1 == 1)
            {
                return 3;
            }
            else
            {
                return 6;
            }
        }

    }
        //right row vertical moves

    //else return zero for tie game
    return 0;
}
