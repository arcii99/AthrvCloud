//FormAI DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

char* removeDuplicates(char* string) {
    int uniqueCharsCount = 0;
    char* uniqueCharsArray = (char*) calloc(MAX_CHARS, sizeof(char));
    if(uniqueCharsArray == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(EXIT_FAILURE);
    }
    
    int* charOccurenceArray = (int*) calloc(256, sizeof(int));
    if(charOccurenceArray == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(EXIT_FAILURE);
    }
    
    int stringLength = strlen(string);
    for(int i=0; i<stringLength; i++) {
        char currentChar = string[i];
        if(charOccurenceArray[(int) currentChar] == 0) {
            charOccurenceArray[(int) currentChar] = 1;
            uniqueCharsArray[uniqueCharsCount++] = currentChar;
        }
    }
    uniqueCharsArray[uniqueCharsCount] = '\0';
    
    free(charOccurenceArray);
    return uniqueCharsArray;
}

int main() {
    char inputString[MAX_CHARS];
    printf("Enter a string: ");
    scanf("%[^\n]s", inputString);
    
    char* uniqueChars = removeDuplicates(inputString);
    printf("Unique characters in the input string: %s", uniqueChars);
    
    free(uniqueChars);
    return 0;
}