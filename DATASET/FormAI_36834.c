//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitize(char *input);

int main(){
    char input[MAX_INPUT_LENGTH];
    
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    sanitize(input);
    
    printf("Sanitized input: %s", input);
    
    return 0;
}

void sanitize(char *input){
    int i, j;
    char temp[MAX_INPUT_LENGTH];
    
    for(i = 0, j = 0; input[i] != '\0'; i++){
        if(isalnum(input[i])){
            temp[j++] = input[i];
        }
    }
    
    temp[j] = '\0';
    strcpy(input, temp);
}