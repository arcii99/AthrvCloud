//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include<stdio.h>
#include<string.h>

#define MAX_INPUT 256

/*function to sanitize user input*/
void sanitize_input(char* input){
    int len = strlen(input);
    /*removing any new line characters*/
    if(input[len-1] == '\n'){
        input[len-1] = '\0';
    }
    /*removing any leading whitespaces*/
    while(*input == ' '){
        ++input;
    }
    /*removing any trailing whitespace*/
    char* end = input + strlen(input) - 1;
    while(end > input && *end == ' '){
        --end;
    }
    *(end+1) = '\0';
    /*removing any special characters*/
    char temp[MAX_INPUT];
    int i = 0, j = 0;
    while(input[i] != '\0'){
        if(isalnum(input[i]) || input[i] == ' '){
            temp[j] = input[i];
            ++j;
        }
        ++i;
    }
    temp[j] = '\0';
    strcpy(input, temp);
}

int main(){
    char input[MAX_INPUT];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);
    sanitize_input(input);
    printf("Your sanitized input is: %s\n", input);
    return 0;
}