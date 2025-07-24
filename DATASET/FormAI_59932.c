//FormAI DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>

int main()
{
    // Display a cryptic message to decipher
    printf("Ebbg gb pyvpx n fgevat: \n");

    // Define the input string to compress
    char input[] = "How much wood would a woodchuck chuck if a woodchuck could chuck wood?";

    // Create variables for tracking frequency and compressed output
    char currentChar = input[0];
    int currentFreq = 1;
    char compressedOutput[1000] = "";

    // Loop through each character in the input string
    for (int i = 1; i < strlen(input); i++)
    {
        // If the character is the same as the previous one, increase frequency
        if (input[i] == currentChar)
        {
            currentFreq++;
        }
        else
        {
            // Otherwise, add the compressed version of the previous character to the output string
            sprintf(compressedOutput, "%s%c%d", compressedOutput, currentChar, currentFreq);
            currentChar = input[i];
            currentFreq = 1;
        }
    }

    // Add the final compressed character to the output string
    sprintf(compressedOutput, "%s%c%d", compressedOutput, currentChar, currentFreq);

    // Display the compressed output
    printf("%s\n", compressedOutput);

    // Return success
    return 0;
}