//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <string.h>
#define MAX_SPAM_WORDS 10

int main() {
    char spam_words[MAX_SPAM_WORDS][20] = {"viagra", "lottery", "inheritance", "bank account", "credit card", "nigerian prince", "enlargement", "meet singles", "earn money", "free gift"};

    char message[1000];
    printf("Enter message: ");
    fgets(message, 1000, stdin);

    int i, j, spam_count = 0;
    char* token = strtok(message, " ,.!?\n");

    while(token != NULL) {
        for(i = 0; i < MAX_SPAM_WORDS; i++) {
            if(strcmp(token, spam_words[i]) == 0) {
                spam_count++;
            }
        }
        token = strtok(NULL, " ,.!?\n");
    }

    if(spam_count == 0) {
        printf("This message is not spam!\n");
    } else {
        printf("This message is spam!\n");
    }
    return 0;
}