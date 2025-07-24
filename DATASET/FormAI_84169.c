//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 100 // Maximum length of the generated string

int main() {

    // Generate a random string of characters
    srand(time(NULL));
    char str[MAX_LEN];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < MAX_LEN; i++) {
        int index = rand() % (sizeof(charset) - 1);
        str[i] = charset[index];
    }
    str[MAX_LEN - 1] = '\0';

    // Display the generated string to the user
    printf("Type this string as fast as you can:\n\n%s\n\n", str);
    
    // Get the user's input and calculate typing speed
    char input[MAX_LEN];
    fgets(input, MAX_LEN, stdin);
    strtok(input, "\n"); // Remove trailing newline from input
    int errors = 0;
    int len = strlen(str);
    double start_time = (double)clock() / CLOCKS_PER_SEC; // Start timer
    for (int i = 0; i < len; i++) {
        if (i >= strlen(input)) { // Check if user has reached the end of their input
            errors += len - i; // Add remaining characters as errors
            break;
        }
        if (str[i] != input[i]) { // Check for mistyped characters
            errors++;
        }
    }
    double end_time = (double)clock() / CLOCKS_PER_SEC; // Stop timer
    double elapsed_time = end_time - start_time;
    int typing_speed = ((len - errors) / elapsed_time) * 60; // Calculate typing speed in words per minute

    // Display results to the user
    printf("You typed %d characters in %.2f seconds with %d errors.\n", len, elapsed_time, errors);
    printf("Your typing speed was %d words per minute.\n", typing_speed);

    return 0;
}