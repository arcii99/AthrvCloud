//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main() {

    char str[MAX_LEN], new_str[MAX_LEN];
    int i, j;

    // Get input string from user
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    
    // Remove spaces and punctuation marks from input string
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i]) && !ispunct(str[i])) {
            new_str[j++] = tolower(str[i]);
        }
    }
    new_str[j] = '\0';
    
    // Check if input string is a palindrome
    int len = strlen(new_str);
    int k = len - 1;
    for (i = 0; i < len/2; i++) {
        if (new_str[i] != new_str[k]) {
            printf("The input string is not a palindrome.\n");
            return 0;
        }
        k--;
    }
    
    printf("The input string is a palindrome!\n");
    
    return 0;
}