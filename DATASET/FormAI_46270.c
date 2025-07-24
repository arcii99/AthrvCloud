//FormAI DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 500

int is_spam(char message[]){
    char* spam_words[] = {"buy", "now", "click", "limited time offer", "get rich quick", "free", "cash", "prize", "won", "call now", "order", "subscribe", "money back guarantee"};
    int num_spam_words = sizeof(spam_words)/sizeof(spam_words[0]);

    int i;
    for(i = 0; i < num_spam_words; i++){
        if(strstr(message, spam_words[i]) != NULL){
            return 1;
        }
    }
    return 0;
}

int main(){
    char message[MAX_MSG_LEN];
    printf("Enter a message: ");
    fgets(message, MAX_MSG_LEN, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    if(is_spam(message)){
        printf("This is a spam message.\n");
    } else{
        printf("This is not a spam message.\n");
    }
    return 0;
}