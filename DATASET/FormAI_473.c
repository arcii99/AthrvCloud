//FormAI DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[100];
    printf("Please type in a string: ");
    fgets(string, 100, stdin);
    printf("\nYou typed: %s", string);
    
    // Remove spaces from the string
    int len = strlen(string);
    int j = 0;
    for(int i = 0; i < len; i++) {
        if(string[i] != ' ') {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
    printf("\nString without spaces: %s", string);
    
    // Convert all characters to uppercase
    for(int i = 0; i < j; i++) {
        if(string[i] >= 'a' && string[i] <= 'z') {
            string[i] = string[i] - 32;
        }
    }
    printf("\nString in upper case: %s", string);
    
    // Find the length of the string
    len = strlen(string);
    printf("\nLength of the string: %d", len);
    
    return 0;
}