//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    //Variable Declaration
    char userInput[100];
    char sanitizedString[100];
    int i, j;

    //Getting user input
    printf("Enter a String: ");
    scanf("%[^\n]s", userInput);

    //Sanitizing User Input
    i=j=0;
    while(userInput[i]){
        if(isalnum(userInput[i])){
            sanitizedString[j] = tolower(userInput[i]);
            j++;
        } 
        i++;
    }
    
    //Adding a null terminator at the end of the sanitized string
    sanitizedString[j] = '\0';

    //Printing Sanitized String
    printf("Sanitized String: %s", sanitizedString);

    return 0;
}