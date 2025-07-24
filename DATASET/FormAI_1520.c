//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256
#define SPAM_THRESHOLD 0.9

int main(void) {
    char input[MAX_INPUT_LENGTH];

    // Prompt user for input
    printf("Enter a string:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    int spam_count = 0;
    int total_count = 0;

    // Loop through each character in the input
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is a letter or number
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
            total_count++;

            // Check if the character is a common spam word
            if (strstr("buy now, free, discount, offer", &input[i])) {
                spam_count++;
            }
        }
    }

    // Calculate spam ratio
    double spam_ratio = (double)spam_count / (double)total_count;

    // Check if spam ratio exceeds threshold
    if (spam_ratio >= SPAM_THRESHOLD) {
        printf("This string is likely spam.\n");
    } else {
        printf("This string is not likely spam.\n");
    }

    return 0;
}