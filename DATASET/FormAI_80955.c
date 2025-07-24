//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void clearBuffer() {
    while(getchar() != '\n');
}

int isPalindrome(char *str) {
    int start = 0, end = strlen(str) - 1;

    while(start < end) {
        if(tolower(str[start]) != tolower(str[end]))
            return 0;
        start++;
        end--;
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    clearBuffer();

    if(isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}