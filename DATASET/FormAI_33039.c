//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1000
#define MAX_SPAM_WORDS 100
#define SPAM_THRESHOLD 5

char spam_words[MAX_SPAM_WORDS][MAX_MESSAGE_SIZE];
int n_spam_words = 0;

// Add spam keywords to list
void add_spam_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(spam_words[n_spam_words], MAX_MESSAGE_SIZE, fp) != NULL) {
        spam_words[n_spam_words][strlen(spam_words[n_spam_words]) - 1] = '\0'; // Replace newLine Character
        n_spam_words++;
    }
    fclose(fp);
}

// Check if word is spam
int is_spam(char *word) {
    for (int i = 0; i < n_spam_words; i++) {
        if (strstr(word, spam_words[i])) {
            return 1;
        }
    }
    return 0;
}

// Check if message is spam
int is_spam_message(char *message) {
    char *word = strtok(message, " ");
    int spam_count = 0;
    while (word != NULL) {
        if (is_spam(word)) {
            spam_count++;
        }
        if (spam_count >= SPAM_THRESHOLD) {
            return 1;
        }
        word = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    add_spam_words("spam_words.txt");
    char message[MAX_MESSAGE_SIZE];
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    if (is_spam_message(message)) {
        printf("This is a spam message.\n");
    } else {
        printf("This is not a spam message.\n");
    }
    return 0;
}