//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to create a unique string using mathematical operations
char* createUniqueString(char* str) {
    int len = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (len + 1));
    
    // loop through each character of the original string
    for(int i=0; i<len; i++) {
        int asciiVal = str[i];
        int num = asciiVal - 'A' + 1;
        
        // calculate the square root of the character's numerical value
        double sqrtVal = sqrt(num);
        
        // round up to the nearest integer
        int newVal = ceil(sqrtVal);
        
        // convert the integer back to a character
        char newChar = (char)(newVal + 'A' - 1);
        
        // add the new character to the new string
        newStr[i] = newChar;
    }
    
    // add null character at the end of the new string
    newStr[len] = '\0';
    
    return newStr;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    char* newStr = createUniqueString(str);
    
    printf("Original String: %s\n", str);
    printf("New String: %s\n", newStr);
    
    free(newStr);
    
    return 0;
}