//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0;
    int num1, num2, answer, userAnswer;
    
    srand(time(0)); // initialize random number generator
    
    printf("Welcome to the Math Quiz!\n");
    printf("You will be given 10 addition problems to solve.\n");
    
    for(int i=1;i<=10;i++)
    {
        num1 = rand() % 100; // generate random numbers between 0 and 100
        num2 = rand() % 100;
        answer = num1 + num2; // calculate the correct answer
        
        printf("\nQuestion %d: What is %d + %d?\n", i, num1, num2);
        printf("Enter your answer: ");
        scanf("%d", &userAnswer);
        
        if(userAnswer == answer)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Sorry, the correct answer is %d.\n", answer);
        }
    }
    
    printf("\nYou scored %d out of 10.\n", score);
    printf("Thanks for playing!\n");
    
    return 0;
}