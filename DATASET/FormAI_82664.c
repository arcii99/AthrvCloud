//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
    // Prompt user for input string
    char input[100];
    printf("Please enter a string to check if it's a palindrome: ");
    scanf("%s", input);
    
    // Create a copy of the input string
    char reversed[100];
    strcpy(reversed, input);
    
    // Reverse the copy string
    int len = strlen(reversed);
    for (int i = 0; i < len / 2; i++) {
        char temp = reversed[i];
        reversed[i] = reversed[len - i - 1];
        reversed[len - i - 1] = temp;
    }
    
    // Compare the input string with the reversed copy string
    if (strcmp(input, reversed) == 0) {
        printf("The input string is a palindrome!\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }
    
    return 0;
}