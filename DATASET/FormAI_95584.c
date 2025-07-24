//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>

void sanitize(char* input){
    int len = strlen(input);
    char sanitized[len+1]; //allocate space for sanitized input
    int index = 0; //initialize array index for sanitized input

    //loop through each character in input
    for(int i=0; i<len; i++){
        char c = input[i];

        //if character is a letter or digit, add it to the sanitized input
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            sanitized[index] = c;
            index++;
        }
        //if character is a space or punctuation mark, ignore it
        else if(c == ' ' || c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':'){
            continue;
        }
        //if character is something we can't use, replace it with '_'
        else{
            sanitized[index] = '_';
            index++;
        }
    }

    //terminate the sanitized input string with a null character
    sanitized[index] = '\0';

    //copy the sanitized input back into the original input string
    strcpy(input, sanitized);
}

int main(){
    char input[100];
    printf("Enter your input: ");
    fgets(input, 100, stdin);

    //remove trailing newline from input
    input[strlen(input)-1] = '\0';

    sanitize(input);
    printf("Your sanitized input is: %s\n", input);

    return 0;
}