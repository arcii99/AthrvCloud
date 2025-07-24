//FormAI DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define THRESHOLD 0.8

int main() {
    char message[MAX_SIZE];
    printf("Enter the message: ");
    fgets(message, MAX_SIZE, stdin);
    
    // Removing the new line character from the message
    message[strcspn(message, "\n")] = 0;

    // Counting the occurrences of each character in the message
    int charCount[26] = {0};
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            charCount[message[i] - 'a']++;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            charCount[message[i] - 'A']++;
        }
    }

    // Counting the total number of characters in the message
    int totalChars = 0;
    for (int i = 0; i < 26; i++) {
        totalChars += charCount[i];
    }

    // Calculating the percentage of each character in the message
    double percentage[26] = {0.0};
    for (int i = 0; i < 26; i++) {
        percentage[i] = (double)charCount[i] / totalChars;
    }

    // Checking if the message is spam or not
    double spamScore = 0.0;
    for (int i = 0; i < length; i++) {
        if (message[i] == ' ') {
            continue;
        }
        
        // Calculating the spam score of the character
        if (percentage[message[i] - 'a'] > THRESHOLD) {
            spamScore += percentage[message[i] - 'a'];
        }
    }

    // Printing the spam score and the result
    printf("Spam score: %lf\n", spamScore);
    if (spamScore >= THRESHOLD) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}