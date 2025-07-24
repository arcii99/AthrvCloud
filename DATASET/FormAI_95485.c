//FormAI DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int spam_count = 0;
    const char *spam_words[] = {"buy", "free", "limited time", "act now", "special offer", "discount", "sale"};

    printf("Enter your message:\n");
    fgets(message, 1000, stdin);

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + 32;
        }
        if (message[i] == '\n') {
            message[i] = '\0';
        }
    }

    char *word = strtok(message, " ");

    while (word != NULL) {
        for (int i = 0; i < sizeof(spam_words) / sizeof(char *); i++) {
            if (strcmp(word, spam_words[i]) == 0) {
                spam_count++;
            }
        }
        word = strtok(NULL, " ");
    }

    if (spam_count >= 2) {
        printf("This message is classified as spam.\n");
    } else {
        printf("This message is not classified as spam.\n");
    }

    return 0;
}