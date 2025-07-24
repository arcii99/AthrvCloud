//FormAI DATASET v1.0 Category: String manipulation ; Style: Alan Touring
//Alan Turing Style C string manipulation example

#include <stdio.h>
#include <string.h>

// function to remove spaces from string
void removeSpaces(char* str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
           str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}

int main()
{
    char inputStr[500];
    printf("Enter a string: ");
    fgets(inputStr, 500, stdin);
    
    // removing extra spaces from user input string
    removeSpaces(inputStr);
    
    int strLength = strlen(inputStr);
    int reversedString[strLength+1];
    
    // reversing the input string
    for(int i=0; i<strLength; i++) {
        reversedString[i] = inputStr[strLength-i-1];
    }
    reversedString[strLength] = '\0';
    
    // displaying the modified string on console
    printf("\nModified string: %s\n", reversedString);
    return 0;
}