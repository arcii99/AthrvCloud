//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

double calculateTypingSpeed(int num_chars, double duration);

int main() {
    char input_string[MAX_STRING_LENGTH];
    char target_string[MAX_STRING_LENGTH];

    int num_chars = 0;
    double duration = 0.0;
    double speed = 0.0;
    time_t start_time, end_time;
    srand(time(NULL));
    
    // Generate random string to use as target
    for (int i = 0; i < MAX_STRING_LENGTH-1; i++) {
        target_string[i] = (char)(rand() % 26 + 65);
    }
    target_string[MAX_STRING_LENGTH-1] = '\0';
    
    printf("Welcome to Typing Speed Test!\n");
    printf("\nYour task is to type the following text as quickly and accurately as possible:\n\n");
    printf("%s\n", target_string);
    printf("\nPress Enter to begin when you are ready.\n");
    getchar();
    
    // Get start time and read user input
    time(&start_time);
    printf("\nType the following text:\n\n");
    fgets(input_string, MAX_STRING_LENGTH, stdin);
    time(&end_time);
    
    // Calculate typing speed
    duration = difftime(end_time, start_time);
    num_chars = strlen(target_string) - 1; // Don't count null terminator
    speed = calculateTypingSpeed(num_chars, duration);
    
    // Print result
    printf("\nYou typed:\n");
    printf("%s", input_string);
    printf("\n");
    printf("Your typing speed is %.2f characters per second.\n", speed);
    
    return 0;
}

// Helper function to calculate typing speed in characters per second
double calculateTypingSpeed(int num_chars, double duration) {
    return (double)num_chars / duration;
}