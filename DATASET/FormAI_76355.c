//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 500

struct Message {
    int id;
    char content[MAX_MESSAGE_LENGTH];
    int is_spam;
};

int is_spam(char *message) {
    char *spam_words[] = {"buy", "cheap", "discount", "free", "money", "win"};
    int spam_word_count = 6;
    int i;
    char *token;

    token = strtok(message, " ");
    while(token != NULL) {
        for(i=0; i<spam_word_count; i++) {
            if(strcmp(token, spam_words[i]) == 0) {
                return 1;
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

void mark_spam(struct Message *message) {
    message->is_spam = 1;
}

void process_message(struct Message *message, int message_count) {
    if(is_spam(message->content)) {
        mark_spam(message);
    }
}

int main() {
    struct Message messages[10];
    int i;

    // dummy messages for testing
    for(i=0; i<10; i++) {
        messages[i].id = i+1;
        printf("Enter message %d: ", i+1);
        fgets(messages[i].content, MAX_MESSAGE_LENGTH, stdin);
        messages[i].is_spam = 0;
        process_message(&messages[i], i+1);
    }

    // print spam messages
    printf("Spam messages:\n");
    for(i=0; i<10; i++) {
        if(messages[i].is_spam) {
            printf("%d. %s", messages[i].id, messages[i].content);
        }
    }

    // print non-spam messages
    printf("Non-spam messages:\n");
    for(i=0; i<10; i++) {
        if(!messages[i].is_spam) {
            printf("%d. %s", messages[i].id, messages[i].content);
        }
    }

    return 0;
}