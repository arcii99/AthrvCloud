//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include<stdio.h>
#include<string.h>

#define MAX_SPAM_WORDS 100
#define MAX_MSG_LENGTH 1000

char spamWords[MAX_SPAM_WORDS][50];
char message[MAX_MSG_LENGTH];
int numSpamWords = 0;

//function to check if a word is a spam word
int isSpam(char *word){
    for(int i = 0; i < numSpamWords; i++){
        if(strcmp(word, spamWords[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    //add some random spam words to the list
    strcpy(spamWords[numSpamWords++], "lottery");
    strcpy(spamWords[numSpamWords++], "free");
    strcpy(spamWords[numSpamWords++], "money");
    
    //get message from user
    printf("Enter your message: \n");
    fgets(message, MAX_MSG_LENGTH, stdin);
    
    //split the message into words
    char *word = strtok(message, " ,.-\n");
    while(word != NULL){
        //check if the word is a spam word
        if(isSpam(word)){
            printf("Warning! This message contains spam words.\n");
            return 0;
        }
        word = strtok(NULL, " ,.-\n");
    }
    
    printf("This message is clean.\n");
    
    return 0;
}