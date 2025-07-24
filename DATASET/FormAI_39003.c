//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a word or a sentence to check if it's a palindrome: ");
    fgets(input, 100, stdin); // Reading input from user

    char reversed[100];
    int len = strlen(input);
    int i, j;
    for (i = 0, j = len - 1; j >= 0; i++, j--) {
        reversed[i] = input[j]; // Reversing the input string
    }

    if (strcmp(input, reversed) == 0) { // Comparing original input with reversed string
        printf("\n%s is a palindrome!\n", input);
    } else {
        printf("\n%s is NOT a palindrome.\n", input);
    }

    return 0;
}