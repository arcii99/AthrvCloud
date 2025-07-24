//FormAI DATASET v1.0 Category: Spam Detection System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1000

int check_for_spam(char *msg) {
    int spam_count = 0;
    char *spam_words[] = {"giveaway", "free", "money", "discount", "promotion", "click here"};
    int num_of_spam_words = 6;
    
    for(int i=0; i<num_of_spam_words; i++) {
        char *word = spam_words[i];
        if(strstr(msg, word) != NULL) {
            spam_count++;
        }
    }
    
    return spam_count;
}

void clear_buffer() {
    while(getchar() != '\n') {}
}

int main() {
    char msg[MAX_MSG_LEN];
    int spam_count = 0;
    printf("Enter your message:\n");
    fgets(msg, MAX_MSG_LEN, stdin);
    if(msg[strlen(msg)-1] == '\n') {
        msg[strlen(msg)-1] = '\0';
    }
    spam_count = check_for_spam(msg);
    if(spam_count == 0) {
        printf("No spam detected!\n");
    } else {
        printf("Spam detected! %d spam words found in your message.\n", spam_count);
    }
    return 0;
}