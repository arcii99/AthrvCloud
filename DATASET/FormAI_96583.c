//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char enter;
    int correct_count = 0;
    int wrong_count = 0;
    float time_taken = 0;
    char test_string[100] = "The quick brown fox jumps over the lazy dog.";

    printf("\nWelcome to the C Typing Speed Test!\n\n");
    printf("Type the following sentence as fast as possible:\n\n");
    printf("%s\n", test_string);

    // Get user input and keep track of time taken
    time_t start_time = time(NULL);
    for(int i = 0; i < 100; i++) {
        scanf("%c", &enter);
        if (enter == test_string[i])
            correct_count++;
        else
            wrong_count++;

        // Check if sentence has ended or user has taken too long
        if (enter == '\n' || time(NULL) - start_time > 10)
            break;
    }
    time_taken = (float)(time(NULL) - start_time);

    // Calculate typing speed and accuracy
    float net_speed = (float)correct_count / time_taken * 60;
    float accuracy = ((float)correct_count / (correct_count + wrong_count)) * 100;

    printf("\n\nYou typed %d characters correctly out of %d in %.2f seconds.\n", correct_count, correct_count + wrong_count, time_taken);
    printf("Your typing speed is %.2f characters per minute.\n", net_speed);
    printf("Your accuracy is %.2f%%.\n", accuracy);

    return 0;
}