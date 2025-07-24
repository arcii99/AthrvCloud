//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 100

int main(){

    char messages[MAX_MESSAGES][MAX_LENGTH];
    int numMessages = 0;

    printf("Welcome to the Spam Detection System!\n");
    printf("Please input your messages. Enter 'exit' to end input.\n");

    while(numMessages < MAX_MESSAGES){ 
        char input[MAX_LENGTH];
        printf("Enter message %d: ", numMessages+1);
        fgets(input, MAX_LENGTH, stdin);
        if(strcmp(input, "exit\n") == 0){
            break;
        }
        strcpy(messages[numMessages++], input);
    }

    printf("\n*** RESULTS ***\n");

    // Check for repeat messages
    for(int i=0; i<numMessages-1; i++){
        for(int j=i+1; j<numMessages; j++){
            if(strcmp(messages[i], messages[j]) == 0){
                printf("Message %d and message %d are identical!\n", i+1, j+1);
            }
        }
    }

    // Check for frequent/common words used in spam
    char commonWords[10][20] = {"win", "free", "money", "prize", "click", "discount", "offer", "urgent", "limited", "act now"};
    int commonCount[10] = {0};
    for(int i=0; i<numMessages; i++){
        for(int j=0; j<10; j++){
            if(strstr(messages[i], commonWords[j]) != NULL){
                commonCount[j]++;
            }
        }
    }
    for(int i=0; i<10; i++){
        if(commonCount[i] > 1){
            printf("The common word '%s' was used %d times!\n", commonWords[i], commonCount[i]);
        }
    }

    return 0;
}