//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: visionary
#include<stdio.h> 

int main() 
{ 
    char string[1000]; 

    printf("Enter a string to check if it is a palindrome: "); 
    fgets(string, 1000, stdin); // Getting input string from user

    int length = 0; 

    /* Calculating length of the entered string */
    while (string[length] != '\0') 
    { 
        length++; 
    } 

    int mid = length/2; 
    int i, j; 

    /* Comparing each character of the entered string from start to middle and from end to middle */
    for (i = 0, j = length-1; i < mid && j >= mid; i++, j--) 
    { 
        if (string[i] != string[j]) 
        { 
            printf("'%s' is not a palindrome", string); 
            return 0; 
        } 
    } 

    printf("'%s' is a palindrome", string); 
    return 0; 
}