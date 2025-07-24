//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 200

void sanitizeInput(char input[]){
    int i, j;
    char temp[MAX_INPUT_LENGTH];

    for(i=0, j=0; i < strlen(input); i++){
        if(isalnum(input[i])){
            temp[j++] = input[i];
        }
    }

    temp[j] = '\0';

    strcpy(input, temp);
}

int main(){
    char user_input[MAX_INPUT_LENGTH];

    printf("Welcome to CyberSanitize 3000 - the ultimate user input sanitizer.\n");
    printf("Please enter your input: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);

    sanitizeInput(user_input);

    printf("Your sanitized input is: %s\n", user_input);

    return 0;
}