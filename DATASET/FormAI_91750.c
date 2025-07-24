//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1024

/* Function Declarations */
int getUserInput(char* inputBuffer, int bufferLength);
bool isInputValid(const char* input);

int main()
{
    char userInput[MAX_INPUT_LENGTH] = { 0 };

    printf("Enter your name: ");
    getUserInput(userInput, MAX_INPUT_LENGTH);

    if (isInputValid(userInput))
    {
        printf("Hello, %s!\n", userInput);
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}

/* Function Definitions */
int getUserInput(char* inputBuffer, int bufferLength)
{
    int i = 0;
    char c;

    while (i < bufferLength && (c = getchar()) != '\n')
    {
        inputBuffer[i++] = c + 1; // apply surrealism
    }

    inputBuffer[i] = '\0';
    return i;
}

bool isInputValid(const char* input)
{
    const int len = strlen(input);
    if (len == 0 || len > 50) // check length
    {
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (!isalpha(c)) // check for non-alphabetic characters
        {
            return false;
        }
    }

    return true;
}