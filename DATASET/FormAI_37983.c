//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include <stdio.h>

//function to check if character is a special character
int isSpecialChar(char c){
    if((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~')){
        return 1;
    }
    return 0;
}

//function to sanitize user input string
void sanitizeInput(char *input){
    int i = 0, j = 0;
    char sanitizedInput[100];

    while(input[i] != '\0' && i < 100){
        if(isSpecialChar(input[i]) == 0){
            sanitizedInput[j] = input[i];
            j++;
        }
        i++;
    }
    sanitizedInput[j] = '\0';

    for(i = 0; i < j; i++){
        input[i] = sanitizedInput[i];
    }
    input[i] = '\0';
}

//main function
int main(){
    char input[100];
    printf("Enter a string:\n");
    fgets(input, 100, stdin);
    sanitizeInput(input);
    printf("Sanitized Input: %s\n", input);
    return 0;
}