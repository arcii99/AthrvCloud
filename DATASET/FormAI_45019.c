//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: decentralized
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//sanitize function to remove any special characters or numbers from a string
void sanitize(char *input) {

    int len = strlen(input);
    
    for(int i=0; i<len; i++) {
        if(!isalpha(input[i])) { //if the character is not an alphabet
            for(int j=i; j<len; j++) {
                input[j] = input[j+1]; //shift the characters left by 1
            }
            len--; //decrement the length of the string
            i--; //decrement i so that it checks the same index again
        }
    }
    input[len] = '\0'; //end the string with a null character
}

int main() {

    char input[100]; //initializing string to store user input

    printf("Enter a string: ");
    scanf("%[^\n]", input); //get user input until newline encountered
    
    sanitize(input); //sanitize the user input

    printf("Sanitized input: %s\n", input);

    return 0;
}