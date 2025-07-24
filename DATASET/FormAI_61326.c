//FormAI DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100]; // message to check for spam
    int spam_counter = 0;

    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter a message to check for spam: ");
    fgets(message, sizeof(message), stdin);

    char* spam_keywords[] = {
        "free", "money", "prince", "inheritance", "lottery", "win", "cash",
        "credit", "card", "debt", "guaranteed", "limited", "offer", "opportunity",
        "promotion", "discount", "special", "deal", "exclusive", "bonus", "click",
        "now", "fast", "act", "today", "urgent", "secret", "confidential", "spam"
    };

    int num_keywords = sizeof(spam_keywords) / sizeof(spam_keywords[0]);

    for(int i = 0; i < num_keywords; i++) {
        if(strstr(message, spam_keywords[i]) != NULL) {
            spam_counter++;
        }
    }

    if(spam_counter > 0) {
        printf("\nALERT! This message contains %d spam keywords.", spam_counter);
        printf("\nDo NOT open any links or respond to this message.\n");
        printf("Please forward this message to your IT department immediately.\n\n");
    } else {
        printf("\nThis message is safe to open and respond to.\n");
    }

    return 0;
}