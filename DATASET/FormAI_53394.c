//FormAI DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_WORD_LENGTH 20
#define MAX_MESSAGE_LENGTH 200

// define spam words
char spamWords[MAX_SPAM_WORDS][MAX_WORD_LENGTH] = {
    "offer", "free", "money", "discount", "cashback",
    "guaranteed", "limited", "deal", "click", "act now"
};

// function to check if a word is present in the spam words list
int isSpamWord(char *word) {
    int i;
    for(i = 0; i < MAX_SPAM_WORDS; i++) {
        if(strcmp(word, spamWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int spamCount = 0;

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    int messageLength = strlen(message);

    // loop through each character in the message
    for(int i = 0; i < messageLength; i++) {
        // copy each character into the word array until a space or punctuation is encountered
        if(message[i] != ' ' && message[i] != '\n' && message[i] != '.' 
           && message[i] != ',' && message[i] != ':' && message[i] != ';' && message[i] != '!') {
            strncat(word, &message[i], 1);
        }
        else {
            // check if word is a spam word
            if(isSpamWord(word)) {
                spamCount++;
            }
            word[0] = '\0'; // reset the word array
        }
    }

    // check if last word is a spam word
    if(isSpamWord(word)) {
        spamCount++;
    }

    printf("Spam count: %d\n", spamCount);

    // determine if message is spam or not based on spam count
    if(spamCount > 0) {
        printf("This message is SPAM!\n");
    }
    else {
        printf("This message is NOT spam.\n");
    }

    return 0;
}