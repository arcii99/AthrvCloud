//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int main(){
    char input[100];
    printf("Enter your input: ");
    fgets(input, 100, stdin); // gets input from user
    // sanitize the input by removing any non-alphanumeric characters
    int sanitized_index = 0; //this is for the new sanitized input
    char sanitized_input[100];
    for(int i = 0; i<strlen(input); i++){
        if((input[i]>='0' && input[i]<='9') || (input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z')){
            sanitized_input[sanitized_index] = input[i]; //add only alphanumeric characters to the sanitized input
            sanitized_index++;
        }
    }
    sanitized_input[sanitized_index] = '\0'; //terminate the sanitized input with a null character
    printf("Input after sanitization: %s", sanitized_input);
    return 0;
}