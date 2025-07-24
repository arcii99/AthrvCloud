//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int pTable[118] = {0}; // Initialize all elements as 0
    int correctAnswers = 0;
    int incorrectAnswers = 0;
    int questionNumber = 1;

    printf("Welcome to the Periodic Table Quiz!\n\n");

    srand(time(NULL)); // Seed the random number generator

    while (questionNumber <= 10) // Ask 10 questions
    {
        int atomicNumber = rand() % 118 + 1; // Generate a random atomic number between 1 and 118
        int answer;

        printf("Question %d: What is the symbol for element %d?\n", questionNumber, atomicNumber);

        printf("Enter your answer: ");
        scanf("%d", &answer);

        if (answer == pTable[atomicNumber - 1])
        {
            printf("Correct!\n\n");
            correctAnswers++;
        }
        else
        {
            printf("Incorrect. The correct symbol for element %d is %d\n\n", atomicNumber, pTable[atomicNumber - 1]);
            incorrectAnswers++;
        }

        questionNumber++;
    }

    printf("Quiz completed!\n\n");

    printf("You answered %d questions correctly and %d questions incorrectly.\n", correctAnswers, incorrectAnswers);

    return 0;
}