//FormAI DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_OCCURRENCES 3

int count_word_occurrences(char *text, char *word) {
    int count = 0;
    char *pos = text;
    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos += strlen(word);
    }
    return count;
}

int check_spam(char *text, char **spam_words, int spam_words_count, int max_spam_occurrences) {
    int spam_count = 0;
    for (int i = 0; i < spam_words_count; i++) {
        int occurrences = count_word_occurrences(text, spam_words[i]);
        if (occurrences >= max_spam_occurrences) {
            printf("Spam word '%s' detected %d times.\n", spam_words[i], occurrences);
            spam_count++;
        }
    }
    return spam_count > 0;
}

int main() {
    char *text = "Get rich quick with this amazing offer! Guaranteed to make you millions.";
    char *spam_words[MAX_SPAM_WORDS] = {"rich", "quick", "amazing", "offer", "guaranteed", "millions"};
    int spam_words_count = 6;
    int max_spam_occurrences = MAX_SPAM_OCCURRENCES;
    if (check_spam(text, spam_words, spam_words_count, max_spam_occurrences)) {
        printf("Possible spam detected!");
    } else {
        printf("No spam detected.");
    }
    return 0;
}