//FormAI DATASET v1.0 Category: Spam Detection System ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_MSG_SIZE 1000
#define MAX_WORD_SIZE 50
#define SPAM_THRESHOLD 3

const char *spam_words[] = {"money", "buy", "click", "sale", "win"};

int count_spam_words(char* message) {
    int count = 0;
    char* word = strtok(message, " ");
    while(word != NULL) {
        for(int i = 0; i < sizeof(spam_words)/sizeof(spam_words[0]); i++) {
            if(strcmp(word, spam_words[i]) == 0) {
                count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char message[MAX_MSG_SIZE];
    printf("Enter the message: ");
    fgets(message, MAX_MSG_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; // remove newline character from input
    int spam_count = count_spam_words(message);
    if(spam_count >= SPAM_THRESHOLD) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }
    return 0;
}