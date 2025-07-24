//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    char sentence[] = "The quick brown fox jumps over the lazy dog";
    int i = 0; // Index of current character in sentence
    int correct = 0; // Number of correctly typed characters
    int mistakes = 0; // Number of mistakes made
    clock_t start, end; // Variables to keep track of time
    double time_taken; // Time taken to type the sentence

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast and accurately as possible:\n\n");
    printf("%s\n", sentence);

    printf("Press any key to start.\n");
    getchar();

    start = clock(); // Record start time

    while (sentence[i] != '\0') // Loop through each character in sentence
    {
        char c; // Variable to hold user input
        do
        {
            c = getchar(); // Get user input character
        } while (isspace(c)); // Ignore whitespace characters

        if (c == sentence[i]) // User typed correct character
        {
            correct++;
            i++;
        }
        else // User made a mistake
        {
            mistakes++;
        }
    }

    end = clock(); // Record end time
    time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Calculate time taken

    printf("\nCongratulations, you finished the sentence!\n");
    printf("You made %d mistakes.\n", mistakes);
    printf("Your typing speed is %.2f characters per second.\n", (double)correct / time_taken);

    return 0;
}