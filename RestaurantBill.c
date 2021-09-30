/* RestaurantBill.c*/
/*
Restaurant Bill:
1. Ask user to input tax and tip percentage
2. Choose a random meal out of 4 and calculate 
    the tax and tip based on the meal's price
3. Display the meal cost, tax amount, tip amount, and total bill 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Function declaration */
float getUserFloat(char *prompt);
float getBoundedNum(char *prompt, float lowBound, float highBound);

/* Main */
int main()
{
    time_t t;
    float Salad = 9.95;
    float Soup = 4.55;
    float Sandwich = 13.25;
    float Pizza = 22.35;

    float menu[] = {Salad,Soup,Sandwich,Pizza};
    printf("############################\n");
    printf("Welcome to Hangry Restaurant\n");
    printf("Today's menu will be randomly chosen from this list:\n");
    printf("1. Salad \t- 9.95\n");
    printf("2. Soup \t- 4.55\n");
    printf("3. Sandwich \t- 13.25\n");
    printf("4. Pizza \t- 22.35\n");
    
    srand((unsigned) time(&t));
    float randomMeal = menu[rand() % 4];
    // printf("randomMeal is: %.2f", randomMeal);

    float taxInput = getBoundedNum("Enter prefer tax percentage: ", 0.0, 100.0);
    float tipInput = getBoundedNum("Enter prefer tip percentage: ", 0.0, 100.0);

    float taxAmount = randomMeal * (taxInput/100);
    float tipAmount = randomMeal * (tipInput/100);
    printf("######## Receipt ########\n");
    printf("The meal cost: %.2f\n", randomMeal);
    printf("Tax amount is: %.2f\n", taxAmount);
    printf("Tip amount is: %.2f\n", tipAmount);
    float totalBill = randomMeal + taxAmount + tipAmount;
    printf("Total bill is: %.2f\n", totalBill);
    return 0;
}

/* Function Implementation */
/* get double input from user */
float getUserFloat(char *prompt)
{
    float userInput;
    do
    {
        printf(prompt);
        scanf("%f",&userInput);
    } while (userInput < 0);
    return userInput;
}
float getBoundedNum(char *prompt, float lowBound, float highBound)
{
    float userInput;
    while(1) // any non-zero number used as condition is treated as TRUE
    {
        userInput = getUserFloat(prompt);
        if (lowBound <= userInput && userInput <= highBound)
            break;
        printf("Please enter a value in the range [%.2f..%.2f]\n",lowBound,highBound);
    }
    return userInput;
}