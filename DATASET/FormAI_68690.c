//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input buffer
#define MAX_BUFFER_SIZE 100000

int main()
{
    // Initialize our input buffer
    char inputBuffer[MAX_BUFFER_SIZE];

    // Read the input string from the command line
    printf("Enter the input string: ");
    fgets(inputBuffer, MAX_BUFFER_SIZE, stdin);

    // Remove the newline character from the input string
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

    // Initialize our dictionary with all ASCII characters
    char dictionary[255];
    for (int i = 0; i < 255; i++)
    {
        dictionary[i] = (char)i;
    }

    // Initialize our compressed output buffer
    char compressedBuffer[MAX_BUFFER_SIZE];

    // Set the initial compressed output to the first character of the input
    int compressedSize = 1;
    compressedBuffer[0] = inputBuffer[0];

    // Loop through the input string
    int inputIndex = 1;
    for (; inputIndex < strlen(inputBuffer); inputIndex++)
    {
        // Get the current character from the input string
        char currentChar = inputBuffer[inputIndex];

        // Find the longest match in the dictionary
        int matchLength = 1;
        char* match = strchr(dictionary, currentChar);
        while (match != NULL && strlen(match) > matchLength &&
            strncmp(inputBuffer + inputIndex, match, matchLength + 1) == 0)
        {
            matchLength++;
            match = strchr(dictionary, currentChar);
        }

        // If we found a match, add it to the compressed output
        if (match != NULL)
        {
            compressedBuffer[compressedSize++] = match - dictionary;
            inputIndex += matchLength - 1;

            // Add the new string to the dictionary
            char newString[matchLength + 1];
            strncpy(newString, inputBuffer + inputIndex - matchLength, matchLength + 1);
            newString[matchLength] = currentChar;
            newString[matchLength + 1] = '\0';
            strncpy(dictionary + strlen(dictionary), newString, strlen(newString));
        }
        // Otherwise, add the current character to the compressed output
        else
        {
            compressedBuffer[compressedSize++] = currentChar;
            strncpy(dictionary + strlen(dictionary), &currentChar, 1);
        }
    }

    // Print the compressed output
    printf("Compressed output (%d bytes): ", compressedSize);
    for (int i = 0; i < compressedSize; i++)
    {
        printf("%c", compressedBuffer[i]);
    }
    printf("\n");

    return 0;
}