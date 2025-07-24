//FormAI DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 500
#define MAX_SPAM_WORDS 100
#define MAX_PAST_MESSAGES 500

char spam_words[MAX_SPAM_WORDS][20] = {"survivor", "raider", "zombie", "apocalypse", "end times", "radiation", "mutation", "nuclear", "wasteland", "mutation", "famine", "disease", "plague", "outbreak", "ersatz","reavers", "progenitor","deathclaws", "super mutants", "ghouls", "radroaches", "deathskull", "bloody mess", "dismemberment", "corpse eater", "cannibal"}, past_messages[MAX_PAST_MESSAGES][MAX_MESSAGE_LENGTH];
int current_index = 0;

int is_spam(char *message) {
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        char *occurrence = strstr(message, spam_words[i]);
        if (occurrence) {
            return 1;
        }
    }
    return 0;
}

int has_spam_recently(char *message) {
    for (int i = 0; i < MAX_PAST_MESSAGES; i++) {
        if (strcmp(message, past_messages[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_message_to_past_messages(char *message) {
    strcpy(past_messages[current_index], message);
    current_index++;
    if (current_index >= MAX_PAST_MESSAGES) {
        current_index = 0;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    while (1) {
        printf("Enter your message:\n");
        fgets(message, sizeof(message), stdin);
        if (is_spam(message) || has_spam_recently(message)) {
            printf("SPAM DETECTED\n");
        } else {
            printf("MESSAGE ACCEPTED\n");
            add_message_to_past_messages(message);
        }
    }
    return 0;
}