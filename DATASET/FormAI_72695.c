//FormAI DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100 // Maximum number of messages that can be stored in the system
#define SPAM_THRESHOLD 3 // Minimum amount of occurrences of a word before it's considered spam

// Struct for storing a single message in the system
typedef struct {
    char text[500]; // Maximum length of a message
    int words_count; // Total number of words
    char* words[50]; // Array of pointers to each word in the message
} Message;

// Struct for storing the list of messages in the system
typedef struct {
    Message messages[MAX_MESSAGES]; // Array of messages
    int count; // Current number of messages in the system
} MessageList;

// Check if a given word is present in a message
int word_in_message(Message* message, char* word) {
    for (int i = 0; i < message->words_count; i++) {
        if (strcmp(message->words[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Check if a given message is spam
int is_spam(Message* message, MessageList* message_list) {
    int count = 0;
    for (int i = 0; i < message_list->count; i++) {
        if (word_in_message(&message_list->messages[i], message->words[0])) {
            count++;
        }
    }
    return count >= SPAM_THRESHOLD;
}

// Add a new message to the system
void add_message(char* text, MessageList* message_list) {
    Message* message = &message_list->messages[message_list->count];
    strcpy(message->text, text);
    message->words_count = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        message->words[message->words_count++] = token;
        token = strtok(NULL, " ");
    }
    message_list->count++;
    if (is_spam(message, message_list)) {
        printf("Warning: possible spam detected!\n");
    }
}

int main() {
    MessageList message_list = { 0 };
    add_message("Hello, how are you?", &message_list);
    add_message("Hi there, doing okay", &message_list);
    add_message("Hey you, how are we today?", &message_list);
    add_message("Make $10000 in one day with this secret method", &message_list);
    add_message("Get rich quick by working only 1 hour per week", &message_list);
    add_message("Do you want to lose weight fast? Try this amazing new product", &message_list);
    return 0;
}