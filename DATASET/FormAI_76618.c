//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, answer;
    int count = 0; 
    char choice;

    srand(time(0)); // set rand seed to current time

    do
    {
        num1 = rand() % 20;             // generate random number 1
        num2 = rand() % 20;             // generate random number 2
        result = num1 + num2;           // add the numbers together to get result
        
        printf("\nWhat is %d + %d?\n", num1, num2);        // print out the question
        scanf("%d", &answer);           // get user input
        
        if (answer == result)           // check if user's answer is correct
        {
            printf("Good job! You got it right.\n");
            count++;                    // increment the count of correct answers
        }
        else
        {
            printf("Oops! The correct answer was %d\n", result);
        }
        
        printf("\nDo you want to continue? (y/n)\n");    // ask user if they want to continue
        scanf(" %c", &choice);

    } while (choice == 'y');

    printf("\nYou got %d correct answers. Thanks for playing!\n", count);

    return 0;
}