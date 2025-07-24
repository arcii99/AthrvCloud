//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a given string contains spam words or not
int check_spam(char *message)
{
    char *spam_words[] = {"buy", "free", "discount", "limited time offer"};  // array of spam words
    int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);  // number of spam words in the array

    // loop through all the spam words and check if they are present in the message
    for (int i = 0; i < num_spam_words; i++) {
        if (strstr(message, spam_words[i])) {  // if the spam word is found in the message
            return 1;  // return 1 to indicate spam
        }
    }

    return 0;  // return 0 to indicate not spam
}

int main()
{
    char message[1000];  // input message

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);  // read input from user

    // remove trailing newline character from the input
    if (message[strlen(message)-1] == '\n') {
        message[strlen(message)-1] = '\0';
    }

    // check if the message contains spam words or not
    int is_spam = check_spam(message);

    if (is_spam) {
        printf("The message is spam!\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}