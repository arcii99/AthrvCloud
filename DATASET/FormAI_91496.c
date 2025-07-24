//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, len, flag = 0;

    printf("Welcome to Palindrome Checker!\n");
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0, j = len-1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Sorry! %s is not a Palindrome.", str);
    } 
    else {
        printf("Great! %s is a Palindrome.", str);
    }

    return 0;
}