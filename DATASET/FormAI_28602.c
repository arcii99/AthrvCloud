//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: genious
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void sanitizeInput(char input[], int maxLength);

int main(){
    char userInput[100];
    int maxInputLength = 50;

    //Prompt user for input
    printf("Enter your input (max %d characters): ", maxInputLength);
    fgets(userInput, 100, stdin);

    //sanitize user input
    sanitizeInput(userInput, maxInputLength);

    //Print sanitized input
    printf("Sanitized Input: %s", userInput);

    return 0;
}

// This function sanitizes user input by removing any non-alphabetical characters and converting all alphabetical characters to lowercase
void sanitizeInput(char input[], int maxLength){
    int i, j;

    //Convert all alphabetical characters to lowercase
    for(i=0; i<strlen(input); i++){
        input[i] = tolower(input[i]);
    }

    //Remove any non-alphabetical characters
    for(i=0, j=0; i<strlen(input) && j<maxLength; i++){
        if(isalpha(input[i])){
            input[j] = input[i];
            j++;
        }
    }

    //Add null character at the end to terminate string
    input[j] = '\0';
}