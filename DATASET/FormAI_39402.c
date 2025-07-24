//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
    char msg[100]; // To store user input message
    int count = 0; // To keep track of spam words count

    printf("Enter your message:\n");
    fgets(msg, 100, stdin); // Get user input message

    // Check for spam words
    if (strstr(msg, "free") || strstr(msg, "win") || strstr(msg, "money")) {
        count++;
    }

    // Check for excessive punctuation
    int length = strlen(msg);
    int punctuationCount = 0;
    for (int i = 0; i < length; i++) {
        if (msg[i] == '.' || msg[i] == ',' || msg[i] == '?' || msg[i] == '!') {
            punctuationCount++;
        }
    }
    if (punctuationCount > 5) {
        count++;
    }

    // Check for repeated letters
    int repeatCount = 0;
    for (int i = 0; i < length; i++) {
        if (msg[i] == msg[i+1] && msg[i] != ' ') {
            repeatCount++;
        }
    }
    if (repeatCount > 3) {
        count++;
    }

    // Check for all caps message
    int capsCount = 0;
    for (int i = 0; i < length; i++) {
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            capsCount++;
        }
    }
    if (capsCount == length - 1) {
        count++;
    }

    // Determine if message is spam or not
    if (count >= 2) {
        printf("Your message is considered spam.\n");
    } else {
        printf("Your message is not spam.\n");
    }

    return 0;
}