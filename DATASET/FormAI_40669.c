//FormAI DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include<stdio.h>
#include<string.h>

int main(){
    char message[100];
    int spamCount = 0;
    int length = strlen(message);

    printf("Enter message: ");
    fgets(message, 100, stdin);
    
    //Check for spam words and increase spamCount
    if(strstr(message, "win a free prize") != NULL){
        spamCount++;
    }
    if(strstr(message, "discount") != NULL){
        spamCount++;
    }
    if(strstr(message, "limited time offer") != NULL){
        spamCount++;
    }
    if(strstr(message, "buy now") != NULL){
        spamCount++;
    }

    //Print appropriate message based on spamCount
    if(spamCount >= 2){
        printf("This message appears to be spam. Please do not respond.\n");
    }else{
        printf("This message is safe to respond to.\n");
    }

    return 0;
}