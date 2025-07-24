//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100 // Maximum length for input strings

typedef enum {FALSE, TRUE} BOOL; // Define boolean data type

const char* fortunes[] = { // Array of fortunes
    "A good day to travel.",
    "You will soon receive unexpected money.",
    "Your hard work will pay off in the near future.",
    "A secret admirer is watching you.",
    "Your creativity will lead to success.",
    "Your dreams will come true.",
    "Beware of those who try to bring you down.",
    "Your life will soon change in a positive way.",
    "Be patient, success is near.",
    "You will soon find love."
};

int main(void)
{
    srand(time(NULL)); // Set random seed based on system time

    char input[MAX_STR_LEN]; // Input string

    printf("Welcome to the Fortune Teller!\n");

    while (TRUE) // Continuous loop for user input
    {
        printf("Please enter your question or type 'quit' to exit: ");

        if (fgets(input, MAX_STR_LEN, stdin) == NULL) // Check for valid input
        {
            printf("Error reading input. Please try again.\n");
            continue;
        }

        if (strcmp(input, "quit\n") == 0 || strcmp(input, "QUIT\n") == 0) // Check for exit command
        {
            printf("Exiting...\n");
            break;
        }

        int r = rand() % 10; // Generate random number between 0 and 9

        printf("The Fortune Teller says: %s\n", fortunes[r]); // Print random fortune
    }

    return 0;
}