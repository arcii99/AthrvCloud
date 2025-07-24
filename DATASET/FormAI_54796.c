//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char text_to_type[] = "The quick brown fox jumps over the lazy dog."; // Sample text to type
    int num_chars = strlen(text_to_type);
    int i = 0, num_correct = 0, num_attempts = 0;
    double accuracy = 0.0, time_elapsed = 0.0;
    clock_t start_time, end_time;

    printf("*** TYPING SPEED TEST ***\n");
    printf("Type the following text and press ENTER:\n%s\n", text_to_type);
    start_time = clock(); // Start the timer

    while (i < num_chars) // Repeat until entire text is typed
    {
        char input_char = getchar(); // Read user input

        if (input_char == text_to_type[i])
        {
            num_correct++;
        }
        num_attempts++;
        i++;
    }

    end_time = clock(); // Stop the timer
    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // Calculate time taken in seconds
    accuracy = ((double) num_correct / (double) num_attempts) * 100.0; // Calculate accuracy in percentage

    printf("Congratulations! You have typed the text correctly!\n");
    printf("Time taken: %.2f seconds\n", time_elapsed);
    printf("Number of characters typed: %d\n", num_chars);
    printf("Number of correct characters typed: %d\n", num_correct);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}