//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

#define SIZE 1024

void processString(char *str, int *numUpper, int *numLower) {
    int len = strlen(str);
    *numUpper = 0;
    *numLower = 0;

    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            (*numUpper)++;
        } else if (islower(str[i])) {
            (*numLower)++;
        }
    }
}

bool isPalindrome(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    printf("Enter a string:\n");
    char str[SIZE];
    fgets(str, SIZE, stdin);

    int numUpper, numLower;
    processString(str, &numUpper, &numLower);

    printf("Number of upper case letters: %d\n", numUpper);
    printf("Number of lower case letters: %d\n", numLower);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}