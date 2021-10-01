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

/* Function declaration prototype */
void playGame(int max);
void changeMaxNumber(int *max);
void checkMaxReference(int *max);

/* Main */
int main()
{
    // maxValue can be changed by user during program's runtime
    int maxValue = DEFAULT_MAX;
    checkMaxReference(&maxValue);
	do
	{
        printf("*******************************\n");
        printf("Welcom to Number Guessing Game!\n");
        printf("Press 1 to play game.\n");
        printf("Press 2 to change the max number.\n");
        printf("Press 3 to quit.\n");
        printf("*******************************\n");
        int userInput = getBoundedInt("Please choose 1 of the 3 options: ",1,3);
        switch(userInput)
        {
            case 1: 
                playGame(maxValue); 
                continue;
            case 2: 
                changeMaxNumber(&maxValue); 
                continue;
            case 3: 
                printf("Thank you for playing, see you next time!\n");
                return 0;
        }
	} while (1);
}

/* Option 1 - Manage gameplay */
void playGame(int max)
{
    time_t t;
    int min = 1;

    // generate random number from min and max value
    srand((unsigned) time(&t));
    int randomNum = rand() % max;
    printf("Your guessing range is between (%d...%d) \n", min, max);
    char userInput[10];
    do
    {
        printf("Your guess: ");
        scanf("%s", userInput);
        clean_stdin();
        if(userInput[0] == 'q')    break;
        else
        {
            int userGuess = atoi(userInput);
            // printf("the input number was: %d\n", userGuess);
            if(userGuess == randomNum) {
                printf("\nCongratulation, You are the winner!!!\n");
                break;
            }
            else if(userGuess < min || userGuess > max) {
                printf("No negative number and within the bounds...\n");
                continue;
            }
            else if (userGuess < randomNum) printf("Oops, Too low!\n");
            // else here means userGuess > randomNum
            else                            printf("Argh, Too High!\n");
        }
    } while (1);
}

/* Option 2 - ask for user's prefer max value and save in a file */
void changeMaxNumber(int *max)
{
    int status,userInput;
    printf("Please choose a max value in the range [1...%d]\n", MAX_BOUND);
    status = scanf("%d", &userInput);
    while(status!=1) {
        clean_stdin();
        printf("*Invalid Input...\n*No (-)integer and within [1...%d]\n Enter again: ", MAX_BOUND);
        status = scanf("%d", &userInput);
    }
    *max = userInput;
}

/* scan and check for existing file that store max value */
void checkMaxReference(int *max)
{
    FILE *fp;
    fp = fopen("MaxValueSaved.txt", "r");
    int maxValue;
    if(fp) {
        fscanf(fp, "%d", &maxValue);
        fclose(fp);
    }
    *max = maxValue;
}