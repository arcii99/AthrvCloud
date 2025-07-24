//FormAI DATASET v1.0 Category: Educational ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A fun C program to reverse a string!
int main()
{
    char string[100]; // string variable to hold user input
    int length = 0; // integer variable to hold string length
    int i; // loop control variable
      
    // Introduction message to user
    printf("Welcome to the string reverser program!\n");
    printf("Please enter a string: ");
    gets(string); // get user input string
       
    // Find the length of the input string
    length = strlen(string);
       
    // Reverse the string
    for(i=0;i<(length/2);i++)
    {
        char temp = string[i]; // temporary character variable
        string[i] = string[length-i-1];
        string[length-i-1] = temp;
    }
       
    // Display the reversed string to the user
    printf("The reversed string is: %s", string);
       
    // Success message!
    printf("\nThank you for using the string reverser program!");
       
    return 0; // End of program
}