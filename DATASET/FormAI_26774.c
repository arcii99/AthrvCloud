//FormAI DATASET v1.0 Category: Spam Detection System ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10

char* spam_words[MAX_SPAM_WORDS] = {"money", "free", "limited time", "click here", "act now", "buy", "purchase", "offer", "sale", "discount"};
int spam_word_count[MAX_SPAM_WORDS] = {0};

void detect_spam(char* message) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] += 32; // convert uppercase to lowercase
        } else if (message[i] == '\r' || message[i] == '\n') {
            message[i] = '\0'; // remove newline characters
        }
    }
    char* word = strtok(message, " ");
    while (word != NULL) {
        for (j = 0; j < MAX_SPAM_WORDS; j++) {
            if (strstr(word, spam_words[j]) != NULL) {
                spam_word_count[j]++;
                printf("Warning: Possible Spam Word Detected! (%s)\n", spam_words[j]);
            }
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    printf("Welcome to the Spam Detection System.\n");
    char message[1024];
    printf("Please input a message:\n");
    fgets(message, 1024, stdin);
    detect_spam(message);
    printf("Spam Word Count:\n");
    int i;
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        printf("%s: %d\n", spam_words[i], spam_word_count[i]);
    }
    return 0;
}