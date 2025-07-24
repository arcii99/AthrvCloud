//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char typed_char, expected_char;
    int typed_count = 0, error_count = 0, correct_count = 0;
    float typing_time = 0.0, typing_speed = 0.0;
    time_t start_time, end_time;

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Paranoid Typing Speed Test!\n");
    printf("Please type the characters as they appear.\n");
    printf("Press ENTER after each character.\n");
    printf("Ready?\n");

    getchar(); // Pause and wait for user to press ENTER

    start_time = time(NULL); // Get the current time in seconds

    for (int i = 0; i < 50; i++) { // Test 50 random characters
        expected_char = (char)(rand() % 26 + 'a'); // Generate a random lowercase letter

        printf("%c ", expected_char);

        typed_char = getchar(); // Get the user's typed character

        if (typed_char == '\n') { // If the user only pressed ENTER, ignore the iteration
            i--;
            continue;
        }

        typed_count++; // Increment the typed count for valid input

        if (typed_char == expected_char) { // If the input is correct
            correct_count++;
        } else { // If the input is incorrect
            error_count++;
        }
    }

    end_time = time(NULL); // Get the current time in seconds

    typing_time = (float)(end_time - start_time); // Calculate the typing time in seconds
    typing_speed = (float)(correct_count / typing_time * 60); // Calculate the typing speed in characters per minute

    printf("\n\nCongratulations, you have completed the Paranoid Typing Speed Test!\n");
    printf("You typed %d characters in %.1f seconds.\n", typed_count, typing_time);
    printf("%d of the characters were correct, and %d were incorrect.\n\n", correct_count, error_count);

    printf("Your typing speed is %.1f characters per minute.\n", typing_speed);

    if (typing_speed > 100) { // If the typing speed is above 100, congratulate the user
        printf("Wow, you're a lightning-fast typist! Great job!\n");
    } else { // If the typing speed is 100 or below, urge the user to improve
        printf("Your typing speed is a bit slow. Keep practicing to improve!\n");
    }

    return 0;
}