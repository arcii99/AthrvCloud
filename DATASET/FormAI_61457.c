//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000

void delay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

int main()
{
    char text[MAX_LENGTH];
    int input_length, text_length, char_position = 0, correct_chars = 0, incorrect_chars = 0;
    double elapsed_time, typing_speed, accuracy_percentage;

    srand(time(0)); // seed the random number generator with the current time

    // generate a random string of text to type
    for (int i = 0; i < MAX_LENGTH - 1; i++)
    {
        text[i] = rand() % 26 + 97; // generate a lowercase letter
    }
    text[MAX_LENGTH - 1] = '\0'; // add null terminating character to the end of the string

    printf("Welcome to the typing speed test!\n\n");
    printf("Type the following text as fast as you can:\n\n");
    printf("%s\n\n", text);

    clock_t start_time = clock();

    // read user input character by character, until they press Enter
    while (1)
    {
        char input = getchar();

        if (input == '\n')
        {
            break;
        }

        if (char_position < MAX_LENGTH - 1)
        {
            if (input == text[char_position])
            {
                correct_chars++;
            }
            else
            {
                incorrect_chars++;
            }

            char_position++;
        }

        // clear input buffer
        while (getchar() != '\n');

        // print current progress
        printf("\r");
        for (int i = 0; i <= char_position; i++)
        {
            printf("%c", text[i]);
        }

        delay(50); // wait 50 milliseconds to simulate typing speed
    }

    elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    typing_speed = (double)char_position / elapsed_time;
    accuracy_percentage = (double)correct_chars / (correct_chars + incorrect_chars) * 100;

    printf("\n\nYou typed %d characters in %.2f seconds.\n", char_position, elapsed_time);
    printf("Your typing speed is %.2f characters per second.\n", typing_speed);
    printf("Your accuracy is %.2f%%.\n", accuracy_percentage);

    if (typing_speed > 50 && accuracy_percentage > 95)
    {
        printf("Great job! You are a super fast and accurate typist!\n");
    }
    else if (typing_speed > 30 && accuracy_percentage > 90)
    {
        printf("Good job! You are a fast and accurate typist!\n");
    }
    else
    {
        printf("Keep practicing! You can improve your typing speed and accuracy with practice.\n");
    }

    return 0;
}