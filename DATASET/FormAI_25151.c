//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, user_input;
    char operator;
    srand(time(0));
    num1 = rand() % 100; // get a random number between 0 and 100
    num2 = rand() % 100; // get another random number between 0 and 100
    printf("I will present you with a surprise math exercise! Get ready...\n");
    
    switch(rand() % 4) // get a random number between 0 and 3 to determine the operator of the math exercise
    {
        case 0: operator = '+'; result = num1 + num2; break;
        case 1: operator = '-'; result = num1 - num2; break;
        case 2: operator = '*'; result = num1 * num2; break;
        case 3: operator = '/'; result = num1 / num2; break;
    }

    printf("Okay, your exercise is: %d %c %d\n", num1, operator, num2);
    printf("What is your answer? ");
    scanf("%d", &user_input);
    
    printf("Calculating...\n");
    sleep(2); // wait for 2 seconds to make it more dramatic

    if(user_input == result) // check if the user's input is correct
    {
        printf("Congratulations! You got it right!\n");
    }
    else
    {
        printf("Sorry, the correct answer is %d. Better luck next time!\n", result);
    }
    return 0;
}