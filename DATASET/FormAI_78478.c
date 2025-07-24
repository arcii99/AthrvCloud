//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of message
#define MAX_SPAM_WORDS 10 // maximum number of spam words that can be detected
#define MAX_SPAM_SCORE 3 // maximum spam score allowed before message is flagged as spam

// function to count the number of occurrences of a specific word in a given string
int countOccurrences(char *str, char *word) {
    int count = 0;
    char *ptr = str;

    while ((ptr = strstr(ptr, word))) {
        count++;
        ptr += strlen(word);
    }

    return count;
}

// function to check if a given word is present in the spam words array
int isSpamWord(char *word, char *spamWords[]) {
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char message[MAX_SIZE];
    char *spamWords[MAX_SPAM_WORDS] = {"buy", "discount", "free", "cash", "money", "earn", "income", "fortune", "lottery", "winner"};

    int spamScore = 0;

    printf("Enter your message: ");
    fgets(message, MAX_SIZE, stdin);

    // count occurrences of spam words in message
    char *word = strtok(message, " \n"); // tokenize message into words
    while (word != NULL) {
        if (isSpamWord(word, spamWords)) {
            spamScore += countOccurrences(message, word);
        }
        word = strtok(NULL, " \n");
    }

    // determine if message is spam or not
    if (spamScore >= MAX_SPAM_SCORE) {
        printf("This message may be spam! Please review before sending.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}