#include "Tools.h"

/* get integer input from user */
int getUserInt(char *prompt)
{
    int userInput;
    do
    {
        printf(prompt);
        scanf("%d",&userInput);
    } while (userInput < 0);
    return userInput;
}

/* get double input from user */
double getUserDouble(char *prompt)
{
    double userInput;
    do
    {
        printf(prompt);
        scanf("%lf",&userInput);
    } while (userInput < 0);
    return userInput;
}

int getBoundedInt(char *prompt, int lowBound, int highBound)
{
    int userInput;
    while(1)
    {
        userInput = getUserDouble(prompt);
        if (lowBound <= userInput && userInput <= highBound)
            break;
        printf("Please enter a value in the range [%d..%d] ",lowBound,highBound);
    }
    return userInput;
}

/* compare and return the user input in assigned range*/
double getBoundedDouble(char *prompt, double lowBound, double highBound)
{
    double userInput;
    while(1)
    {
        userInput = getUserDouble(prompt);
        if (lowBound <= userInput && userInput <= highBound)
            break;
        printf("Please enter a value in the range [%d..%d] \n",lowBound,highBound);
    }
    return userInput;
}

/* get YES or NO answer based on 1 and 0 */
int getBool(char *prompt)
{
    char userInput;
    while (1)
    {
        printf(prompt);
        scanf("%c", &userInput);
        // switch (userInput)
        // {
        //     case 'y': case 'Y':	return 0;
        //     case 'n': case 'N':	return 1;
        // }
        if(userInput == 'Y' || userInput == 'y')        return 0;
        else if(userInput == 'N' || userInput =='n')    return 1;
        else    printf("Please enter Y or N...\n");
    }
}