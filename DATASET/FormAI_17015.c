//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int checkIfPalindrome(char str[]);

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", str);

    if (checkIfPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}

int checkIfPalindrome(char str[]) {
    int i, length = strlen(str);
    for (i = 0; i < length/2; i++) {
        if (str[i] != str[length-i-1]) {
            return 0;
        }
    }
    return 1;
}