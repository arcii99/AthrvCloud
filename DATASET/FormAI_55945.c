//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 100 // Maximum length of a message
#define SPAM_THRESHOLD 0.3 // Threshold for determining if a message is spam

int count_occurrences(const char *str, const char *sub_str);

int main() {
    char message[MAX_MSG_LENGTH];
    printf("Enter a message:\n");
    fgets(message, MAX_MSG_LENGTH, stdin); // Read message from user

    int num_words = 0;
    char *word = strtok(message, " "); // Tokenize message by whitespace
    while (word != NULL) {
        num_words++;

        // Check for spam words
        if (strcmp(word, "buy") == 0 || strcmp(word, "sale") == 0 ||
            strcmp(word, "discount") == 0 || strcmp(word, "click") == 0 ||
            strcmp(word, "offer") == 0 || strcmp(word, "free") == 0) {
            printf("Spam detected!\n");
            return 0;
        }

        word = strtok(NULL, " ");
    }

    // Check for spam phrases
    int num_occurrences = count_occurrences(message, "call now");
    if ((double)num_occurrences / num_words >= SPAM_THRESHOLD) {
        printf("Spam detected!\n");
    } else {
        printf("Not spam.\n");
    }

    return 0;
}

// Count the number of occurrences of a substring in a string
int count_occurrences(const char *str, const char *sub_str) {
    int count = 0;
    const char *pos = str;

    while ((pos = strstr(pos, sub_str)) != NULL) {
        count++;
        pos++;
    }

    return count;
}