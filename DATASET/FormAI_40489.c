//FormAI DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 100
#define MAX_CHAT_LENGTH 1000

int spam_word_count = 0;
char spam_words[MAX_SPAM_WORDS][50];

void add_spam_word(char word[]) {
    if (spam_word_count < MAX_SPAM_WORDS) {
        strcpy(spam_words[spam_word_count], word);
        spam_word_count++;
        printf("'%s' has been added to the spam word list.\n", word);
    } else {
        printf("Cannot add '%s' to the spam word list. Maximum limit reached.\n", word);
    }
}

int check_spam(char chat[]) {
    char * token;
    char chat_copy[MAX_CHAT_LENGTH];
    int word_found = 0;

    // make a copy of the chat string
    strcpy(chat_copy, chat);

    // tokenize the chat string
    token = strtok(chat_copy, " ,.!?");
    while (token != NULL) {
        // iterate through the spam word list and check if any word matches
        for (int i = 0; i < spam_word_count; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                word_found = 1;
                break;
            }
        }
        if (word_found) {
            break;
        }
        token = strtok(NULL, " ,.!?");
    }

    return word_found;
}

int main() {
    // initialize some spam words
    add_spam_word("buy");
    add_spam_word("cheap");
    add_spam_word("free");
    add_spam_word("click");
    add_spam_word("money");

    // check some chats for spam
    char chat1[] = "Hey, how's it going?";
    char chat2[] = "Are you interested in buying some cheap stuff?";
    char chat3[] = "Congratulations! You've won a free prize.";
    char chat4[] = "Click here to find out more.";
    char chat5[] = "Can you lend me some money?";

    if (check_spam(chat1)) {
        printf("SPAM detected in chat1!\n");
    } else {
        printf("No spam detected in chat1.\n");
    }

    if (check_spam(chat2)) {
        printf("SPAM detected in chat2!\n");
    } else {
        printf("No spam detected in chat2.\n");
    }

    if (check_spam(chat3)) {
        printf("SPAM detected in chat3!\n");
    } else {
        printf("No spam detected in chat3.\n");
    }

    if (check_spam(chat4)) {
        printf("SPAM detected in chat4!\n");
    } else {
        printf("No spam detected in chat4.\n");
    }

    if (check_spam(chat5)) {
        printf("SPAM detected in chat5!\n");
    } else {
        printf("No spam detected in chat5.\n");
    }

    return 0;
}