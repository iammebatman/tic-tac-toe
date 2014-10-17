#include <iostream>
#include <string>
#include <sys/stat.h>

//open space checker
bool checkSpace(std::string n1, std::string n2, std::string n3, std::string n4, std::string n5, std::string n6, std::string n7, std::string n8, std::string n9, int n)
{
    //declare variables
    int m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0, m6 = 0, m7 = 0, m8 = 0, m9 = 0;
    bool spaceClear = false;

    //convert game spaces into boolean values
    if(n1=="1"){m1=1;}
    if(n2=="2"){m2=1;}
    if(n3=="3"){m3=1;}
    if(n4=="4"){m4=1;}
    if(n5=="5"){m5=1;}
    if(n6=="6"){m6=1;}
    if(n7=="7"){m7=1;}
    if(n8=="8"){m8=1;}
    if(n9=="9"){m9=1;}

    //check if space is open and return true otherwise return false
    switch(n)
    {
        case 1:
            if(m1){spaceClear = true;}
            break;
        case 2:
            if(m2){spaceClear = true;}
            break;
        case 3:
            if(m3){spaceClear = true;}
            break;
        case 4:
            if(m4){spaceClear = true;}
            break;
        case 5:
            if(m5){spaceClear = true;}
            break;
        case 6:
            if(m6){spaceClear = true;}
            break;
        case 7:
            if(m7){spaceClear = true;}
            break;
        case 8:
            if(m8){spaceClear = true;}
            break;
        case 9:
            if(m9){spaceClear = true;}
            break;
    }
    return spaceClear;
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

