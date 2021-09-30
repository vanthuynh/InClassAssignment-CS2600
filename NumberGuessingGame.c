/*
Number Guessing Game:
1. write main() that will operate as game menu
2. ask user for input from main function
    - add tool files to get input from user and check valid boundary
3. implement separate functions for option 1
    - read min & max number boundary from a saved file
    - generate a random number from the limits set by min and max
    - implement gameplay in a form of binary search
4. implement separate function for user to set max bound for the game
    - this function must be able to read/write on file the max value that user choose
    - make sure check for no negative value or go above the max value
5. option 3 is to quit the program but say thanks first
*/
#include "Tools.h"

void playGame();
// void changeMaxNumber();

int main()
{
	do
	{
        printf("*******************************\n");
        printf("Welcom to Number Guessing Game!\n");
        printf("Press 1 to play game.\n");
        printf("Press 2 to change the max number.\n");
        printf("Press 3 to quit.\n");
        printf("************************\n");
        int userInput = getBoundedInt("please choose 1 of the 3 options: ",1,3);
        switch(userInput)
        {
            case 1: playGame();        break;
            // case 2: changeMaxNumber(); break;
            case 3: break;
        }
	} while (getBool("Are you sure you want to quit? (Y/N): "));

	return 0;
}

void playGame()
{

}