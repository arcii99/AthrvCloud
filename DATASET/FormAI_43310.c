//FormAI DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
    printf("Please enter a string: ");
    char myString[100];
    fgets(myString, 100, stdin); // read input string from user
    
    // Get length of string
    printf("\nLength of string: %d\n", strlen(myString));
    
    // Convert all characters to uppercase
    for(int i = 0; i < strlen(myString); i++) {
        if(myString[i] >= 'a' && myString[i] <= 'z') {
            myString[i] = myString[i] - ('a' - 'A');
        }
    }
    printf("\nString in uppercase: %s", myString);
    
    // Reverse the string
    char reversedString[100];
    int j = 0;
    for(int i = strlen(myString) - 1; i >= 0; i--) {
        reversedString[j++] = myString[i];
    }
    reversedString[j] = '\0'; // add null character to end of reversed string
    printf("\nReversed string: %s", reversedString);
    
    // Remove all spaces from string
    int count = 0;
    for(int i = 0; myString[i]; i++) {
        if (myString[i] != ' ') {
            myString[count++] = myString[i];
        }
    }
    myString[count] = '\0'; // add null character to end of modified string
    printf("\nString without spaces: %s", myString);
    
    return 0;
}