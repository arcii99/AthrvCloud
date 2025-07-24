//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//function to detect spam words
bool isSpam(char *word){
    char *spamWords[] = {"offer", "money", "free", "credit", "loan"}; //array of spam words

    //compare each word with the spam words
    for(int i = 0; i < sizeof(spamWords)/sizeof(char *); i++){
        if(strcmp(word, spamWords[i]) == 0){
            return true; //word matched with a spam word
        }
    }

    return false; //word is not a spam word
}

int main(){
    char message[200]; //message to check for spam

    printf("Enter a message: ");
    fgets(message, 200, stdin); //get the message from user

    //tokenize the message into words
    char *token = strtok(message, " ");

    //check each word for spam
    while(token != NULL){
        if(isSpam(token)){
            printf("The message contains spam.\n");
            return 0; //exit the program
        }
        token = strtok(NULL, " ");
    }

    printf("The message is not spam.\n");
    return 0; //exit the program
}