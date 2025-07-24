//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPAM_THRESHOLD 0.7 // threshold for spam detection

int count_word_occurrences(char *word, char *message) {
    int count = 0;
    char *search_pos = message;
    while ((search_pos = strstr(search_pos, word)) != NULL) {
        count++;
        search_pos += strlen(word);
    }
    return count;
}

double calculate_spam_ratio(char *message) {
    int num_words = 0;
    int num_spam_words = 0;
    char *words[4] = {"buy", "cheap", "discount", "free"};
    for (int i = 0; i < 4; i++) {
        int occurrences = count_word_occurrences(words[i], message);
        num_spam_words += occurrences;
        num_words += occurrences;
    }
    char *word = strtok(message, " ");
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }
    return ((double) num_spam_words / num_words);
}

int main() {
    char message[500];
    printf("Enter your message:\n");
    fgets(message, 500, stdin);
    double spam_ratio = calculate_spam_ratio(message);
    if (spam_ratio > SPAM_THRESHOLD) {
        printf("The message is likely spam.\n");
    } else {
        printf("The message is not likely spam.\n");
    }
    return 0;
}