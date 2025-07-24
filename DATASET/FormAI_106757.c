//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate random strings
void generate_random_string(char *str, int len) {
    // Set of characters to be used for generating random string
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = strlen(charset);

    // Generate a random character from the set and add to string
    for (int i = 0; i < len; i++) {
        int rand_index = rand() % n;
        str[i] = charset[rand_index];
    }
    str[len] = '\0'; // Add null character to terminate the string
}

// Function to calculate typing speed in wpm (words per minute)
int calculate_typing_speed(int num_chars_typed, int total_time_taken) {
    const int wpm_conversion_factor = 5; // Assumes each word has 5 characters on average
    int num_words_typed = num_chars_typed / wpm_conversion_factor;
    int wpm = (num_words_typed / total_time_taken) * 60;
    return wpm;
}

int main() {
    const int num_trials = 5; // Number of trials to be conducted
    const int num_chars_to_type = 100; // Number of characters to be typed in each trial
    char input_str[num_chars_to_type + 1]; // Input string typed by user
    char random_str[num_chars_to_type + 1]; // Random string to be displayed to user
    int time_taken; // Time taken to type string in each trial
    int sum_time_taken = 0; // Sum of time taken for all trials
    int typing_speed; // Typing speed in wpm

    // Seed random number generator
    srand(time(NULL));

    // Conduct typing speed test for specified number of trials
    for (int i = 1; i <= num_trials; i++) {
        // Generate random string for user to type
        generate_random_string(random_str, num_chars_to_type);

        // Display random string to user
        printf("Trial %d:\nType the following string as quickly and accurately as possible:\n%s\n", i, random_str);

        // Get input string from user and measure time taken
        clock_t start_time = clock(); // Start timing
        fgets(input_str, num_chars_to_type + 1, stdin); // Read input string from user
        clock_t end_time = clock(); // End timing
        time_taken = (int) ((end_time - start_time) * 1000 / CLOCKS_PER_SEC); // Calculate time taken in milliseconds

        // Calculate typing speed and display results to user
        typing_speed = calculate_typing_speed(num_chars_to_type, time_taken);
        printf("Time taken: %d ms\nTyping speed: %d wpm\n\n", time_taken, typing_speed);

        // Add time taken to sum
        sum_time_taken += time_taken;
    }

    // Calculate average time taken and typing speed for all trials
    int avg_time_taken = sum_time_taken / num_trials;
    int avg_typing_speed = calculate_typing_speed(num_chars_to_type * num_trials, sum_time_taken);

    // Display final results to user
    printf("Typing speed test complete.\nAverage time taken: %d ms\nAverage typing speed: %d wpm\n", avg_time_taken, avg_typing_speed);

    return 0;
}