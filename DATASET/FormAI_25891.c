//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Number of characters in the typing test
#define TEST_SIZE 250

int main()
{
    printf("\nWelcome to the Typing Test!\n");
    printf("You will be given a passage to type, and your accuracy and speed will be calculated.\n\n");

    // Generate the passage to type
    char passage[TEST_SIZE];
    srand(time(NULL));
    for (int i = 0; i < TEST_SIZE; i++)
    {
        passage[i] = (char)(rand() % 26 + 97); // Generate a random lowercase letter
    }

    // Display the passage to the user
    printf("Type the following passage:\n\n");
    printf("%s\n\n", passage);

    // Initialize variables for the test
    char user_input[TEST_SIZE];
    int mistakes = 0;
    int time_taken = 0;
    clock_t start_time, end_time, total_time;

    // Start the timer
    start_time = clock();

    // Get user input
    for (int i = 0; i < TEST_SIZE; i++)
    {
        user_input[i] = getchar();

        // Check for mistakes
        if (tolower(user_input[i]) != tolower(passage[i]))
        {
            mistakes++;
        }

        // End the timer if the user has finished typing
        if (i == TEST_SIZE - 1)
        {
            end_time = clock();
        }
    }

    // Calculate how long the test took
    total_time = end_time - start_time;
    time_taken = (int)(total_time / CLOCKS_PER_SEC);

    // Calculate accuracy and speed
    int correct_chars = TEST_SIZE - mistakes;
    float accuracy = ((float)correct_chars / (float)TEST_SIZE) * 100;
    float speed = ((float)correct_chars / (float)time_taken) * 60;

    // Display the results to the user
    printf("\n\nYou typed:\n\n%s\n\n", user_input);
    printf("Results:\n");
    printf("Time Taken: %d seconds\n", time_taken);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing Speed: %.2f characters per minute\n", speed);

    return 0;
}