//FormAI DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SPAM_THRESHOLD 5

int isSpam(char *message);
// returns 1 if message is spam, 0 otherwise

int main(){
    char message[200];
    int spamCounter = 0;

    printf("Enter message: ");
    fgets(message, 200, stdin);

    // check if message is spam
    if(isSpam(message))
        spamCounter++;
        
    if(spamCounter >= SPAM_THRESHOLD)
        printf("This message is spam!\n");
    else
        printf("This message may not be spam.\n");
        
    return 0;
}

int isSpam(char *message){
    char *spamWords[] = {"buy", "now", "limited", "offer", "discount"};
    int spamWordsCount = sizeof(spamWords)/sizeof(spamWords[0]);
    int i;
    
    for(i=0; i<spamWordsCount; i++){
        if(strstr(message, spamWords[i]) != NULL)
            return 1;
    }
    
    return 0;
}