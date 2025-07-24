//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10
#define MAX_LENGTH 20

void displayWords(char words[][MAX_LENGTH], int count);
void shuffleWords(char words[][MAX_LENGTH], int count);

int main()
{
    char words[MAX_WORDS][MAX_LENGTH] = {"Hello", "World", "Programming", "is", "fun", "C", "Language", "Typing", "Speed", "Test"};

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be given a list of words to type. Press Enter after each word.\n");
    printf("Your typing speed will be calculated in words per minute (WPM).\n\n");

    printf("Press Enter to start the test...");
    getchar(); // Wait for user to press Enter

    shuffleWords(words, MAX_WORDS); // Randomly shuffle the words

    displayWords(words, MAX_WORDS); // Display the words for the user to type

    time_t start = time(NULL); // Get the start time

    char input[MAX_LENGTH];
    int i;
    for (i = 0; i < MAX_WORDS; i++)
    {
        fgets(input, MAX_LENGTH, stdin); // Get user input

        // Remove newline from end of user input
        if (input[strlen(input)-1] == '\n')
            input[strlen(input)-1] = 0;

        // Check if user input matches the current word
        if (strcmp(words[i], input) != 0)
        {
            printf("Incorrect. Please try again.\n");
            i--; // Decrement i to repeat the current word
        }
    }

    time_t end = time(NULL); // Get the end time
    double elapsed = difftime(end, start); // Calculate elapsed time

    int wpm = (int)((MAX_WORDS / elapsed) * 60.0); // Calculate words per minute

    printf("Congratulations! You typed all the words correctly in %.2f seconds.\n", elapsed);
    printf("Your typing speed is %d WPM.\n", wpm);

    return 0;
}

// Displays the given words to the user
void displayWords(char words[][MAX_LENGTH], int count)
{
    int i;
    for (i = 0; i < count; i++)
        printf("%s\n", words[i]);
}

// Randomly shuffles the given words
void shuffleWords(char words[][MAX_LENGTH], int count)
{
    int i;
    for (i = count-1; i >= 1; i--)
    {
        // Generate a random index between 0 and i
        int j = rand() % (i+1);

        // Swap the words at indices i and j
        char temp[MAX_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}