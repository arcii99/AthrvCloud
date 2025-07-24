//FormAI DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPAM_THRESHOLD 0.5 // Threshold to determine if a message is spam (percentage)
#define MAX_LINE_LENGTH 100 // Maximum length of a line of text
#define MAX_WORDS 50 // Maximum number of words in a message

int is_spam(char *message); // Function to determine if a message is spam

int main() {
    char message[MAX_LINE_LENGTH];

    printf("Enter message:\n");
    fgets(message, MAX_LINE_LENGTH, stdin);

    if (is_spam(message)) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}

int is_spam(char *message) {
    int i, j, word_count = 0, spam_count = 0;
    char *word, *word_ptr, *words[MAX_WORDS] = {NULL};
    float spam_probability, word_spam_prob;

    word = strtok(message, " "); // Get first word
    while (word != NULL && word_count < MAX_WORDS) {
        words[word_count++] = word; // Add word to array
        word = strtok(NULL, " "); // Get next word
    }

    for (i = 0; i < word_count; i++) {
        word_ptr = words[i];
        if (strlen(word_ptr) < 3) continue; // Ignore words less than 3 characters

        for (j = 0; j < strlen(word_ptr); j++) {
            if (word_ptr[j] < 'a' || word_ptr[j] > 'z') break; // Ignore non-alphabetic characters
        }
        if (j != strlen(word_ptr)) continue;

        // Calculate the spam probability of the word
        // Note: This is a very basic calculation, you could give more weight to certain words/characters
        word_spam_prob = ((float)rand()/(float)(RAND_MAX)) * 0.2; // Random probability between 0 and 0.2

        if (word_spam_prob > SPAM_THRESHOLD) {
            spam_count++;
        }
    }

    spam_probability = (float)spam_count / (float)word_count;
    if (spam_probability > SPAM_THRESHOLD) {
        return 1;
    }
    return 0;
}