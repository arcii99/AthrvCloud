//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *string);

int main() {
    char input[100];
    printf("Enter a string and we will check if it is a palindrome:\n");
    fgets(input, 100, stdin);
    if (is_palindrome(input)) {
        printf("Nice, \"%s\" is indeed a palindrome!", input);
    } else {
        printf("Sorry, \"%s\" is not a palindrome.", input);
    }
    return 0;
}

int is_palindrome(char *string) {
    int length = strlen(string);
    char *temp = (char *)malloc(length * sizeof(char));
    int i, j;
    for (i = 0; i < length; i++) {
        if (isalpha(string[i])) {
            temp[j++] = tolower(string[i]);
        }
    }
    temp[j] = '\0';
    length = strlen(temp);
    for (i = 0, j = length - 1; i < length / 2; i++, j--) {
        if (temp[i] != temp[j]) {
            return 0;
        }
    }
    return 1;
}