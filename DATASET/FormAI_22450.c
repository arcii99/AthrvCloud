//FormAI DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_SCORE 3

int spam_words_count = 0;
char spam_words[MAX_SPAM_WORDS][50];

void add_spam_word(char word[]) {
    strcpy(spam_words[spam_words_count], word);
    spam_words_count++;
}

int detect_spam(char message[]) {
    int score = 0;
    char *word = strtok(message, " ,.-");
    while (word != NULL) {
        for (int i=0; i<spam_words_count; i++) {
            if (strcmp(spam_words[i], word) == 0) {
                score++;
            }
        }
        word = strtok(NULL, " ,.-");
    }
    return score;
}

int main() {
    add_spam_word("free");
    add_spam_word("money");
    add_spam_word("win");
    add_spam_word("prize");

    char message[100];
    printf("Enter a message:\n");
    fgets(message, 100, stdin);

    int spam_score = detect_spam(message);
    if (spam_score >= MAX_SPAM_SCORE) {
        printf("This message contains spam!\n");
    } else {
        printf("This message is clean!\n");
    }

    return 0;
}