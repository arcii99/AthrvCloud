//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    int length, i, j, flag = 0;
    
    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a word, phrase, or sentence to check: ");
    fgets(input, sizeof(input), stdin);
    
    length = strlen(input) - 1;
    for (i = 0, j = length - 1; i < length; j--, i++) {
        while(ispunct(input[i]) || isspace(input[i])) {
            i++;
        }
        while(ispunct(input[j]) || isspace(input[j])) {
            j--;
        }
        if (tolower(input[i]) != tolower(input[j])) {
            flag = 1;
            break;
        }
    }
    
    if (flag) {
        printf("%s is NOT a palindrome.", input);
    } else {
        printf("%s is a palindrome!", input);
    }
    
    return 0;
}