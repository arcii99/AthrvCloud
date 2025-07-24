//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char text[1000] = "Let’s have some fun and test your typing speed! This is a happy typing speed test program! You need to type the following text as fast as you can. Are you ready to rock and roll? Let’s start!";

    printf("\t\t\tHappy Typing Speed Test\n\n");
    printf("Type the following text as fast as you can!\nPress enter key to start\n");

    getchar();

    printf("Here is your text:\n%s\n", text);

    time_t startTime, endTime;
    double elapsedTime;

    time(&startTime);

    char userInput[1000];
    fgets(userInput, 1000, stdin); // store user input

    time(&endTime);

    elapsedTime = difftime(endTime, startTime);

    int len1 = strlen(text) - 1; // ignore the new line character
    int len2 = strlen(userInput) - 1;

    if (text[len1] == '\n')
    {
        text[len1] = '\0';
    }

    if (userInput[len2] == '\n')
    {
        userInput[len2] = '\0';
    }
    
    int correctChars = 0;
    for (int i = 0; i < len1; i++)
    {
        if (text[i] == userInput[i])
        {
            correctChars++;
        }
    }

    printf("\n\nYour typing speed test results:\n");

    double accuracy = (double)correctChars / (double)len1 * 100.0;
    printf("Accuracy: %.2lf%%\n", accuracy);

    double speed = (double)len1 / (elapsedTime / 60.0);
    printf("Typing speed: %.2lf characters per minute\n", speed);

    return 0;
}