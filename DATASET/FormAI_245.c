//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
    char input[100]; 
    char sanitized_input[100]; 
    int i, j = 0; 
    int flag = 0; 
  
    printf("Enter your input: "); 
    fgets(input, 100, stdin); 
    
    // replace newline character with null character
    input[strlen(input)-1] = '\0';

    // sanitize the input by removing all non-alphabetic characters and converting to lowercase
    for (i = 0; i < strlen(input); i++) { 
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) { 
            sanitized_input[j++] = tolower(input[i]);  
            flag = 1; 
        } 
    } 
    
    // if the input only contained non-alphabetic characters, inform the user and exit the program
    if (flag == 0) { 
        printf("\nNo alphabetic characters found. Program will exit.\n"); 
        return 0; 
    } 

    // add null character to end of sanitized input
    sanitized_input[j] = '\0'; 
    
    // output the sanitized input
    printf("\nSanitized Input: %s\n", sanitized_input); 
        
    return 0; 
}