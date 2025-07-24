//FormAI DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include<stdio.h>
#include<string.h>

int check_spam(char* message){
    int count = 0;
    char* spam_words[5] = {"buy now", "limited time", "exclusive offer", "click here", "win money"};

    for(int i = 0; i < 5; i++){
        if(strstr(message, spam_words[i]) != NULL){
            count++;
        }
    }

    if(count >= 2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    char message[1000];

    printf("Enter message: ");
    fgets(message, 1000, stdin);

    if(check_spam(message)){
        printf("SPAM DETECTED!\n");
    }
    else{
        printf("Message is not spam.\n");
    }

    return 0;
}