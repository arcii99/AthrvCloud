//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    //declare variables
    char userInput[50];
    int i, len;

    //get user input
    printf("What is your name?\n");
    fgets(userInput,50,stdin);

    //sanitze user input
    len = strlen(userInput);
    for(i=0; i<len; i++){
        if(isalpha(userInput[i])){
            userInput[i] = tolower(userInput[i]);
        } else if(userInput[i] == '\n'){
            userInput[i] = '\0';
        }
    }

    //output sanitized user input
    printf("Hello %s! It's great to meet you!\n",userInput);

    return 0;
}