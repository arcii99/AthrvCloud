//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int check_spam(char *input);

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("Enter your message: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        if (check_spam(input)) {
            printf("This message contains spam.\n");
        } else {
            printf("This message is clean.\n");
        }
    }

    return 0;
}

int check_spam(char *input) {
    char *spam_words[] = {"buy", "sale", "enlarge", "viagra", "earn", "money", "online"};
    int num_spam_words = 7;
    int i;

    // Convert input to lowercase for case-insensitive matching
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Check if input contains any spam words
    for (i = 0; i < num_spam_words; i++) {
        char *match = strstr(input, spam_words[i]);
        if (match != NULL) {
            return 1;
        }
    }

    return 0;
}