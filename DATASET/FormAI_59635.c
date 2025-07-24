//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to Typing Speed Test!\n\n");

    char words[10][35] = {"hello", "world", "computer", "science", "program", "language", "coding", "keyboard", "monitor", "mouse"};
    srand(time(NULL));
    int randomNum, i;
    char userWord[35];
    double accuracy, timeTaken, wordsPerMin;

    printf("You will be given 10 random words to type as fast as you can.\n");
    printf("Type the word and press enter to move on to the next one.\n");
    printf("Let's start!\n\n");

    time_t start = time(NULL);

    for(i = 0; i < 10; i++)
    {
        randomNum = rand() % 10;
        printf("Type word %d: %s\n", i+1, words[randomNum]);
        scanf("%s", userWord);
        printf("\n");

        if(strcmp(userWord, words[randomNum]) != 0)
        {
            printf("Incorrect spelling for word %d!\n\n", i+1);
        }
    }

    time_t end = time(NULL);
    timeTaken = difftime(end, start);
    printf("Time taken to complete: %.2f seconds\n", timeTaken);
    accuracy = (10.0 / i) * 100.0;
    printf("Accuracy: %.2f%%\n", accuracy);
    wordsPerMin = (60.0 / timeTaken) * 10;
    printf("Words per minute typing speed: %.2f\n", wordsPerMin);

    return 0;
}