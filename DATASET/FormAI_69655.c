//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 10

char spamWords[MAX_SPAM_WORDS][20] = {"buy", "money", "free", "win", "rich", "offer", "limited", "special", "discount", "act now"};

// Returns true if word is spam
int isSpam(char *word){
    for(int i=0; i<MAX_SPAM_WORDS; i++){
        if(strcmp(spamWords[i], word) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    char input[1000];
    int numSpamWords = 0;
    int numTotalWords = 0;

    printf("Enter the message:\n");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while(token != NULL){
        if(isSpam(token)){
            numSpamWords++;
        }
        numTotalWords++;
        token = strtok(NULL, " ");
    }

    float spamRatio = (float) numSpamWords / numTotalWords;

    if(spamRatio > 0.2){
        printf("\nWARNING: This message contains a high amount of spam words.");
        printf("\nSPAM RATIO: %.2f", spamRatio);
    }else{
        printf("\nMessage is not considered spam.");
        printf("\nSPAM RATIO: %.2f", spamRatio);
    }

    return 0;
}