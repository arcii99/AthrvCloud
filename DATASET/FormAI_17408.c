//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random seed
    
    int num1 = rand() % 100; //generate random number between 0 and 100
    int num2 = rand() % 100;
    
    printf("What is the value of %d + %d?\n", num1, num2);
    
    int answer;
    scanf("%d", &answer);
    
    int correct = num1 + num2;
    
    if(answer == correct)
    {
        printf("Correct! You're a math whiz!\n");
    }
    else
    {
        printf("Sorry, the correct answer is %d\n", correct);
    }
    
    return 0;
}