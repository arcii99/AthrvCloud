//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <string.h>

/* This is a User Input Sanitizer program that will help remove unwanted characters from input */


int main(){
    char input[100];
    printf("Please enter a string of text: \n");
    scanf("%[^\n]s", input); // read input from user
    int len = strlen(input); // get length of input string

    // remove unwanted characters
    for(int i=0; i<len; i++){
        if(input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '\'' || input[i] == '\"') {
            input[i] = ' ';
        }
    }

    printf("Your sanitized input is: \n%s", input); // print sanitized input
    
    return 0;
}