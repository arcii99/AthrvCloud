//FormAI DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define MIN_SPAM_SCORE 3

char* banned_words[] = {"buy now", "limited time offer", "make money fast"};

bool is_spam(char* message){
    int spam_score = 0;
    for(int i=0; i<sizeof(banned_words)/sizeof(banned_words[0]); i++){
        if(strstr(message, banned_words[i]) != NULL){
            spam_score++;
        }
    }
    return spam_score >= MIN_SPAM_SCORE;
}

int main(){
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    if(is_spam(message)){
        printf("SPAM DETECTED!");
    }
    else{
        printf("Message is not spam.");
    }
    
    return 0;
}