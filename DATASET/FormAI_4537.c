//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str) {
    int len = strlen(str);
    char reverse[len+1];
    
    // Convert all characters to lowercase and copy string backwards into reverse[]
    for(int i=0; i<len; i++) {
        reverse[i] = tolower(str[len-i-1]);
    }
    reverse[len] = '\0'; // Add null terminator to end of string
    
    // Compare original string to reversed string
    if(strcmp(str, reverse) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char input[50];
    printf("Enter a word or phrase: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Replace newline character with null terminator
    
    if(is_palindrome(input)) {
        printf("\n%s is a palindrome!\n\n", input);
    }
    else {
        printf("\n%s is not a palindrome.\n\n", input);
    }
    return 0;
}