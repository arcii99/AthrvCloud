//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void sanitizeInput(char *inputString){
    int i;
    for(i = 0; inputString[i] != '\0'; ++i){
        if(!isalpha(inputString[i]) && inputString[i] != ' '){
            inputString[i] = '-';
        }
    }
}

int main(){
    char input[100];
    printf("Enter some text:\n");
    fgets(input, 100, stdin);
    printf("Original input:\n%s\n", input);
    sanitizeInput(input);
    printf("Sanitized input:\n%s\n", input);
    return 0;
}