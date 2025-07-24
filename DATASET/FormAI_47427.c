//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256 //maximum length of input is assumed to be 256 characters

void sanitize_input(char* input); //function to sanitize the input

int main()
{
    char input[MAX_INPUT_LENGTH];
    
    printf("Enter a string to sanitize: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); //get the input string from user
    
    sanitize_input(input); //sanitize the input
    
    printf("Sanitized Input: %s", input); //print the sanitized input
    
    return 0;
}

void sanitize_input(char* input)
{
    int i = 0, j = 0; //i is used to traverse the input string, j is used to store the position of the next valid character
    
    while(input[i] != '\0' && i < MAX_INPUT_LENGTH) //iterate till end of input or maximum length
    {
        if(isalnum(input[i]) || ispunct(input[i])) //check if the character is alphabetic, numeric or punctuation
        {
            input[j] = input[i]; //store the valid character
            j++;
        }
        i++;
    }
    input[j] = '\0'; //add null terminator at the end of sanitized input
}