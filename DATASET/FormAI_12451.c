//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include<stdio.h>
#include<string.h>

void reverse(char *str) { // A function that reverses the given string 
    int length = strlen(str); // Find the length of the string
    char temp[length]; // Create temp variable to store the reversed string
    strcpy(temp, str); // Copy the string into temp variable
    for(int i=0; i<length; i++) {
        str[i] = temp[length-i-1]; // Assign reversed string to original string
    }
}

int main() {
    char string[100]; // Declare a character array to store the string
    printf("Enter a string to be reversed: ");
    fgets(string, 100, stdin); // Read input string from the user
    
    // Remove trailing \n from the string read using fgets
    if(string[strlen(string)-1] == '\n') {
        string[strlen(string)-1] = '\0';
    }
    
    printf("\nOriginal String: %s", string);
    reverse(string); // Call the function to reverse the string
    printf("\nReversed String: %s", string); // Print the reversed string

    return 0;
}