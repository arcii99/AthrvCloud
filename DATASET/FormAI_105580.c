//FormAI DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to detect spam
int detect_spam(char message[]) {
    int i, j, count = 0;

    // List of banned words/phrases
    char banned_words[][200] = {"buy now", "make money fast", "limited time offer", "click here"};

    // Checking each word in the message for banned words
    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            // Extracting the word
            char word[200];
            int k, l = 0;
            for (k = j; k < i; k++) {
                word[l++] = message[k];
            }
            word[l] = '\0';

            // Checking the word against banned words
            for (k = 0; k < 4; k++) {
                if (strstr(word, banned_words[k]) != NULL) {
                    count++;
                }
            }
            j = i + 1;
        }
    }
    return count;
}

int main() {
    char message[500];
    printf("Enter your message: ");
    fgets(message, 500, stdin);

    int spam_count = detect_spam(message);
    if (spam_count > 0) {
        printf("This message contains spam.\n");
    } else {
        printf("This message is spam-free.\n");
    }
    return 0;
}