//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 256

int countWords(char *msg){
    int count = 0;
    char *token = strtok(msg, " ");

    while(token != NULL){
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

int main(){

    char msg[MAX_MSG_SIZE];
    int wordCount;

    printf("Enter your message:\n");
    fgets(msg, MAX_MSG_SIZE, stdin);

    wordCount = countWords(msg);

    if(wordCount > 10){
        printf("This message seems like spam.\n");
    } else {
        printf("This message is valid.\n");
    }

    return 0;
}