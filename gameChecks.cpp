#include <string>
#include <sys/stat.h>

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

