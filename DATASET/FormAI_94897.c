//FormAI DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 1000
#define SPAM_THRESHOLD 0.7 // Threshold to classify a message as spam

// Return the number of occurrences of substring in string
int count_substring(char string[], char substring[]) {
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (strstr(string + i, substring) == string + i) {
            count++;
        }
    }
    return count;
}

// Remove all special characters and convert string to lowercase
void preprocess_string(char string[]) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') { // Convert uppercase letters to lowercase
            string[i] += 32;
        } else if (string[i] < 'a' || string[i] > 'z') { // Remove non-alphabetic characters
            for (int j = i; j < strlen(string); j++) {
                string[j] = string[j + 1];
            }
            i--; // Check the same index again
        }
    }
}

// Calculate the spam score of a message
double calculate_spam_score(char string[], char spam_words[][MAX_STRING_LENGTH], int num_spam_words) {
    double score = 0.0;
    preprocess_string(string);
    for (int i = 0; i < num_spam_words; i++) {
        score += count_substring(string, spam_words[i]);
    }
    return score / strlen(string);
}

int main() {
    char message[MAX_STRING_LENGTH];
    char spam_words[][MAX_STRING_LENGTH] = {
        "make money", "buy now", "limited time offer", "free gift", "amazing deal"
    };
    int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);

    printf("Enter a message: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character

    double spam_score = calculate_spam_score(message, spam_words, num_spam_words);
    if (spam_score > SPAM_THRESHOLD) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is not likely spam.\n");
    }

    return 0;
}