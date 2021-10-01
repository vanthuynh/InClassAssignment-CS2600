#include "Tools.h"

/* 
const variable definition section
*/
// 0-1 million is already an extreme guessing game
// there's no need to use INT_MAX from <limits.h>
const int MAX_BOUND = 1000000;

/* clean the input buffer */
void clean_stdin()
{    
  while ( getchar() != '\n' );
}

/* get integer input from user */
int getUserInt(char *prompt)
{
    int userInput;
    while(1)
    {
        printf("%s",prompt);
        scanf("%d",&userInput);
        if(userInput >= 0)  return userInput;
        printf("*Note: No negative number please...\n");
        clean_stdin();
    }
}

/* get double input from user */
double getUserDouble(char *prompt)
{
    double userInput;
    while(1)
    {
        printf(prompt);
        scanf("%lf",&userInput);
        if(userInput >= 0)  return userInput;
        printf("*Note: No negative number please...\n");
        clean_stdin();
    }
}

int getBoundedInt(char *prompt, int lowBound, int highBound)
{
    int userInput;
    while(1)
    {
        userInput = getUserInt(prompt);
        if (lowBound <= userInput && userInput <= highBound)
            break;
        printf("Please enter a value in the range [%d..%d]\n",lowBound,highBound);
        clean_stdin();
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
        printf("Please enter a value in the range [%d..%d]\n",lowBound,highBound);
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