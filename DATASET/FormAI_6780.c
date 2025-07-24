//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char message[MAX_LENGTH];
    int spam_count = 0;

    printf("Enter a message: ");
    fgets(message, MAX_LENGTH, stdin);

    char *keywords[] = {"buy", "discount", "free", "limited", "offer", "sale"};

    int num_of_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_of_keywords; i++) {
        int keyword_count = 0;
        char *word = strtok(message, " ,.-");

        while (word != NULL) {
            if (strcmp(word, keywords[i]) == 0) {
                keyword_count++;
                if (keyword_count > 2) {
                    spam_count++;
                }
            }
            word = strtok(NULL, " ,.-");
        }
    }

    if (spam_count > 0) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}