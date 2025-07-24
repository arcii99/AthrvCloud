//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define THRESHOLD 0.5 // The probability threshold for spam detection

int main() {
    // Initialize variables
    char message[50];
    int spam_words = 0;
    int ham_words = 0;

    // Get user input
    printf("Enter your message:\n");
    fgets(message, 50, stdin);

    // Split message into words
    char* word = strtok(message, " ");
    
    // Loop through the words and count spam and ham words
    while (word != NULL) {
        char* spam_keywords[] = {"buy", "free", "sex", "win", "lottery"};
        int i;
        for (i = 0; i < 5; i++) {
            if (strstr(word, spam_keywords[i]) != NULL) {
                spam_words++;
                break;
            }
        }
        if (i == 5) {
            ham_words++;
        }
        word = strtok(NULL, " ");
    }

    // Calculate probability of spam
    double probability = (double) spam_words / (double) (spam_words + ham_words);

    // Determine if message is spam or ham
    if (probability > THRESHOLD) {
        printf("This message is spam.\n");
    } else {
        printf("This message is ham.\n");
    }

    return 0;
}