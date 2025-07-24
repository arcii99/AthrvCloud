//FormAI DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    char mySpam[] = "Buy now and get 50% off!";

    char message[100];

    printf("Enter a message: ");
    fgets(message, 100, stdin);

    int randomNum = rand() % 10;

    if(randomNum == 5){
        printf("Error: Could not check for spam. Please try again later.\n");
        return 1;
    }

    if(strstr(message,mySpam) != NULL){
        printf("WARNING: This message contains spam!\n");
    }else{
        printf("This message is clean!\n");
    }

    return 0;
}