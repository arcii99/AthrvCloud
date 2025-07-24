//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the input string contains any spam words
int checkSpam(char input[]){
    char *spamWords[] = {"viagra", "lottery", "free", "click here", "act now", "discount", "limited", "offer", "win", "prize"};
    int size = sizeof(spamWords)/sizeof(*spamWords);
    int i, j, count = 0;

    for(i = 0; i < strlen(input); i++){
        input[i] = tolower(input[i]);
    }

    for(i = 0; i < size; i++){
        char *found = strstr(input, spamWords[i]);
        if(found != NULL){
            count++;
        }
    }

    return count;
}

int main(){
    char message[1000];

    printf("Welcome to the Spam Detection System\n\n");
    printf("Please enter the message you want to check: ");
    fgets(message, sizeof(message), stdin);

    int spamCount = checkSpam(message);

    if(spamCount > 0){
        printf("\nWarning: This message contains %d spam words.\nPlease review before sending.\n", spamCount);
    } else {
        printf("\nThis message is clean and spam free!\n");
    }

    return 0;
}