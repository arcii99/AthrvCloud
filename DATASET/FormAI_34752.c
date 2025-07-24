//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    printf("Please enter a word to check if it is a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;  // Removing the trailing newline character
    
    int length = strlen(input);
    int i, j;
    
    for(i = 0, j = length - 1; i < j; i++, j--) {
        if(input[i] != input[j]) {
            printf("%s is not a palindrome.", input);
            return 0;
        }
    }
    
    printf("%s is a palindrome!", input);
    return 0;
}