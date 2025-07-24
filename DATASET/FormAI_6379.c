//FormAI DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <string.h>
#define THRESHOLD 0.75 // Set the spam threshold

int main()
{
    char message[1000]; // Initialize the message variable
    int is_spam = 0; // Initialize the spam detection variable
    int message_length, num_caps, num_symbols, num_spaces, num_numbers = 0; // Initialize the counters

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin); // Take user input

    message_length = strlen(message) - 1; // Remove the newline character from the input

    for (int i = 0; i < message_length; i++) {
        if (message[i] == ' ') {
            num_spaces++; // Count the number of spaces in the message
        } else if ((message[i] >= 'A' && message[i] <= 'Z') || (message[i] >= 'a' && message[i] <= 'z')) {
            if (message[i] >= 'A' && message[i] <= 'Z') {
                num_caps++; // Count the number of capital letters in the message
            }
        } else if (message[i] >= '0' && message[i] <= '9') {
            num_numbers++; // Count the number of numbers in the message
        } else {
            num_symbols++; // Count the number of symbols in the message
        }
    }

    float spaces_ratio = (float)num_spaces / message_length;
    float caps_ratio = (float)num_caps / message_length;
    float symbols_ratio = (float)num_symbols / message_length;
    float numbers_ratio = (float)num_numbers / message_length;

    if (spaces_ratio > THRESHOLD || caps_ratio > THRESHOLD || symbols_ratio > THRESHOLD || numbers_ratio > THRESHOLD) { // Check if any of the ratios are above the spam threshold
        is_spam = 1; // Set spam detection variable to true
    }

    if (is_spam) {
        printf("Your message contains spam"); // Alert the user if the message contains spam
    } else {
        printf("Your message is not spam"); // Inform the user that the message is not spam
    }

    return 0;
}