//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include<stdio.h>
#include<ctype.h>

#define MAX_INPUT_LEN 100 // maximum input length

void sanitize_input(char* input_string); // function to sanitize input string

int main(){
    char input[MAX_INPUT_LEN];

    printf("Enter input string: ");
    fgets(input, MAX_INPUT_LEN, stdin); // get input from user

    sanitize_input(input); // sanitize input string
    
    printf("Sanitized input : %s\n", input); // display sanitized input string

    return 0;
}

void sanitize_input(char* input_string){
    char sanitized_input[MAX_INPUT_LEN] = {'\0'}; // initialize sanitized input string with null characters
    int index = 0;

    while(input_string[index] != '\n' && input_string[index] != '\0' && index < (MAX_INPUT_LEN - 1)){ // iterate till the end of input string or maximum length is reached
        if(isalpha(input_string[index])){ // check if character is an alphabet
            sanitized_input[index] = tolower(input_string[index]); // convert character to lower case and add to sanitized input string
        }
        else if(isspace(input_string[index])){ // check if character is a white space
            sanitized_input[index] = ' '; // add a single space to sanitized input string
        }
        // add more conditions as per requirement
        index++;
    }
    sanitized_input[index] = '\0'; // add null character at the end of the sanitized input string
    
    //overwrite original input string with the sanitized input string
    for(index=0; sanitized_input[index] != '\0'; index++){
        input_string[index] = sanitized_input[index];
    }
    input_string[index] = '\0'; // add null character at the end of the input string
}