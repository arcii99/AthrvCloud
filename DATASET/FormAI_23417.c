//FormAI DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, answer, marks = 0;
    
    // Randomize seed for generating random numbers
    srand(time(NULL));
    
    // Generate 5 random questions
    for(i = 0; i < 5; i++)
    {
        // Generate random numbers between 1 and 10
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;
        
        // Generate random operator (+ or -)
        char op;
        if(rand() % 2 == 0) op = '+';
        else op = '-';
        
        // Print question and get answer from user
        printf("Question %d: %d %c %d = ", i+1, num1, op, num2);
        scanf("%d", &answer);
        
        // Calculate correct answer and compare with user's answer
        int correct;
        if(op == '+') correct = num1 + num2;
        else correct = num1 - num2;
        
        if(answer == correct)
        {
            printf("Correct!\n");
            marks++;
        }
        else printf("Incorrect!\nCorrect answer is: %d\n", correct);
    }
    
    // Print final marks
    printf("\nYou scored %d out of 5 marks.\n", marks);
    
    return 0;
}