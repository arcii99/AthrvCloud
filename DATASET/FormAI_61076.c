//FormAI DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_CHARS 20

// Spam words to detect
char spam_words[MAX_SPAM_WORDS][MAX_SPAM_CHARS] = {
    "buy",
    "free",
    "money",
    "sale",
    "discount",
    "offer",
    "click",
    "cash",
    "income",
    "earn"
};

int is_spam(char *text) {
    int i, j;
    char word[MAX_SPAM_CHARS] = "";

    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            // Check if current word matches any spam words
            for (j = 0; j < MAX_SPAM_WORDS; j++) {
                if (strcmp(word, spam_words[j]) == 0) {
                    return 1;
                }
            }

            // Clear current word
            memset(word, 0, sizeof(word));
        } else {
            // Append character to current word
            if (strlen(word) < MAX_SPAM_CHARS - 1) {
                strncat(word, &text[i], 1);
            }
        }
    }

    return 0;
}

int main() {
    char input[1000];

    printf("Enter text:\n");
    fgets(input, sizeof(input), stdin);

    if (is_spam(input)) {
        printf("This is spam.\n");
    } else {
        printf("This is not spam.\n");
    }

    return 0;
}