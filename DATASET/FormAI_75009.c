//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 100     // maximum length of a message
#define MAX_SPAM_WORDS 10   // maximum number of words in a spam message
#define MAX_SPAM_COUNT 5    // maximum number of times a phrase can appear in a message before it's flagged as spam

// global array of known spam phrases
char spam_phrases[MAX_SPAM_WORDS][20] = {"make money fast", "buy now", "limited time offer", "win a prize", "call now"};
int spam_counts[MAX_SPAM_WORDS] = {0};  // global array to keep counts of how many times each phrase appears

// function to check if a word is in the list of known spam phrases
int is_spam_word(char* word) {
    int i;
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strcmp(word, spam_phrases[i]) == 0)
            return 1;   // word is in the list of spam phrases
    }
    return 0;   // word is not in the list of spam phrases
}

// function to check if a message is spam
int is_spam(char* message) {
    char* word;
    int count;
    int i;
    int num_words = 0;

    // tokenize the message into words
    word = strtok(message, " ");
    while (word != NULL) {
        // check if the word is in the list of spam phrases
        if (is_spam_word(word))
            spam_counts[i]++;

        num_words++;
        if (num_words > MAX_MSG_LEN)
            break;  // too many words, assume message is spam

        word = strtok(NULL, " ");
    }

    // check if any spam phrases appeared too many times
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        count = spam_counts[i];
        if (count > MAX_SPAM_COUNT)
            return 1;   // message is spam
    }

    return 0;   // message is not spam
}

int main() {
    char message[MAX_MSG_LEN];

    // read messages from standard input and check if they're spam
    while (fgets(message, MAX_MSG_LEN, stdin) != NULL) {
        if (is_spam(message))
            printf("SPAM ALERT: %s", message);
        else
            printf("Message received: %s", message);
    }

    return 0;
}