//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], reverse_str[100];
    int i, j, len, palindrome_flag;

    printf("Welcome to Palindrome Checker!\n");
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Reversing the input string
    for(i = len - 1, j = 0; i >= 0; i--, j++) {
        reverse_str[j] = str[i];
    }
    reverse_str[len] = '\0';

    // Comparing input string with reversed str
    palindrome_flag = strcmp(str, reverse_str);

    if(palindrome_flag == 0) {
        printf("\n%s is a palindrome!", str);
    }
    else {
        printf("\n%s is not a palindrome.", str);
    }

    printf("\n");
    return 0;
}