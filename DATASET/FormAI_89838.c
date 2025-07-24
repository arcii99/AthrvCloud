//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to Palindrome Checker\n");
    char str[1000];
    printf("Please enter a word or phrase to check if it is a Palindrome: ");
    scanf("%[^\n]", str);
    int len = strlen(str);
    int mid = len / 2;
    int i, j;

    for(i = 0, j = len - 1; i < mid; i++, j--) {
        if(str[i] != str[j]) {
            printf("Sorry! %s is NOT a Palindrome\n", str);
            return 0;
        }
    }

    printf("Congratulations! %s is a Palindrome\n", str);
    return 0;
}