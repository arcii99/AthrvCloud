//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to sanitize user input
void sanitizeInput(char *inputString){
    int len = strlen(inputString);
    char *outputString = (char*)malloc(len*sizeof(char));  // Allocate memory for output string
    int j = 0;  // Counter for output string

    for(int i=0; i<len; i++){
        if(inputString[i] >= 'A' && inputString[i] <= 'Z'){
            outputString[j++] = inputString[i] + 32;  // Convert uppercase to lowercase
        }
        else if(inputString[i] >= 'a' && inputString[i] <= 'z'){
            outputString[j++] = inputString[i];  // Keep lowercase letters as they are
        }
        else if(inputString[i] == ' '){
            outputString[j++] = '_';  // Replace spaces with underscores
        }
        else if(inputString[i] >= '0' && inputString[i] <= '9'){
            outputString[j++] = inputString[i];  // Keep digits as they are
        }
    }
    outputString[j] = '\0';  // Append null terminator at the end of output string

    printf("Sanitized input string: %s\n", outputString);
    free(outputString);  // Free allocated memory
}

// Main function
int main(){
    char inputString[100];

    printf("Enter string to sanitize: ");
    fgets(inputString, 100, stdin);  // Get input from user

    sanitizeInput(inputString);  // Call function to sanitize input
    
    return 0;
}