//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Welcome message
    printf("Welcome to my thankful text processing program!\n");

    // Ask the user for input
    printf("\nPlease enter some text you want to be grateful for:\n");

    // Get input from the user
    char input[1000];
    fgets(input, 1000, stdin);

    // Remove new line character from input
    input[strcspn(input, "\r\n")] = 0;

    // Declare variables
    int i, j;
    char temp;

    // Loop through the input string and sort the characters in alphabetical order
    for (i = 0; i < strlen(input); i++)
    {
        for (j = i + 1; j < strlen(input); j++)
        {
            if (input[i] > input[j])
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    // Print the sorted string
    printf("\nHere is your text in alphabetical order, with gratitude!\n%s\n", input);

    // Create a new string with reversed order of characters
    char reverse[1000];
    int length = strlen(input);

    for (i = 0; i < length; i++)
    {
        reverse[i] = input[length - i - 1];
    }

    // Add a message of gratitude to the reversed string
    strcat(reverse, "! Thank you for being in my life.");

    // Print the reversed and grateful string
    printf("\nAnd here is your text in reverse order, with gratitude!\n%s\n", reverse);

    // Say a final message and exit the program
    printf("\nThank you for using my thankful text processing program! Have a wonderful day!\n");
    return 0;
}