//FormAI DATASET v1.0 Category: Text processing ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to find the frequency of a character in a string
int findFrequency(char str[], char ch)  
{  
    int count = 0;    
    for(int i = 0; str[i] != '\0'; i++)  
    {  
        if(str[i] == ch)  
            count++;  
    }  
    return count;  
}  

int main()  
{  
    // Declaring variables and getting user input
    char inputString[100];
    char inputChar;    
    printf("Enter a string: ");  
    fgets(inputString, sizeof(inputString), stdin);  
    printf("\nEnter a character: ");  
    scanf("%c", &inputChar);  

    // Removing the newline character from inputString
    int len = strlen(inputString);
    if(inputString[len-1] == '\n') 
        inputString[len-1] = '\0';

    // Printing the input and output
    printf("\nInput String: %s", inputString);  
    printf("\nInput Character: %c\n", inputChar);  
    printf("Frequency of character '%c' in the string: %d\n", inputChar, findFrequency(inputString, inputChar));  

    return 0;  
}