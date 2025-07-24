//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];

    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter your message:\n");

    fgets(message, 1000, stdin);

    int len = strlen(message);
    int uppercase_count = 0;
    int exclamation_count = 0;
    int spam_words_count = 0;

    for (int i = 0; i < len; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            uppercase_count++;
        }
        if (message[i] == '!') {
            exclamation_count++;
        }
    }

    const char* spam_words[] = {"buy", "cheap", "deal", "click here", "limited time offer"};

    for (int i = 0; i < sizeof(spam_words)/sizeof(spam_words[0]); i++) {
        char* word = spam_words[i];
        char* word_location = strstr(message, word);
        if (word_location) {
            spam_words_count++;
        }
    }

    if (uppercase_count > 5 || exclamation_count > 3 || spam_words_count > 0) {
        printf("This message is spam!\n");
    } else {
        printf("This message is not spam. Carry on, friend!\n");
    }

    return 0;
}