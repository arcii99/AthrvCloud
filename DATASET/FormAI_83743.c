//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 50
#define MAX_SPAM_MESSAGES 1000

char spam_words[MAX_SPAM_WORDS][20];
char messages[MAX_SPAM_MESSAGES][1000];

int num_spam_words;
int num_messages;

int search_for_spam_words(char* message) {
    char temp_message[1000], *token;
    int spam_count = 0;

    memset(temp_message, 0, sizeof(temp_message));
    strcpy(temp_message, message);

    // Split message into tokens
    token = strtok(temp_message, " ,.-");

    while (token != NULL) {
        // Compare token with each spam word
        for (int i = 0; i < num_spam_words; i++) {
            if (strcmp(spam_words[i], token) == 0) {
                spam_count++;
                break;
            }
        }
        token = strtok(NULL, " ,.-");
    }

    return spam_count;
}

void check_messages_for_spam() {
    for (int i = 0; i < num_messages; i++) {
        if (search_for_spam_words(messages[i]) > 2) { // If more than two spam words are found
            printf("Message \n'%s'\n is identified as spam. Please review.\n", messages[i]);
        }
    }
}

int main() {
    printf("Welcome to the Spam Detection System.\n");

    // Populate spam words
    strcpy(spam_words[0], "free");
    strcpy(spam_words[1], "money");
    strcpy(spam_words[2], "win");
    strcpy(spam_words[3], "inheritance");

    num_spam_words = 4;

    // Populate messages
    strcpy(messages[0], "Congratulations! You have won a free cruise to the Caribbean.");
    strcpy(messages[1], "URGENT! Your account has been compromised. Please click the link to verify your account.");
    strcpy(messages[2], "Get rich quick with this investment opportunity!");
    strcpy(messages[3], "You have inherited $1,000,000 from a rich relative. Claim your money now!");

    num_messages = 4;

    check_messages_for_spam();

    return 0;
}