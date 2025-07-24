//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* function to remove punctuations and convert to lowercase */
void preprocess(char *str) {
    int i, j = 0, len = strlen(str);
    char temp[len+1];

    for (i = 0; i < len; ++i) {
        if (isalpha(str[i])) {
            temp[j++] = tolower(str[i]);
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

/* function to check if string is palindrome or not */
int isPalindrome(char *str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len-1; i <= j; ++i, --j) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; /* to remove the newline character from fgets */

    preprocess(str);

    if (isPalindrome(str)) {
        printf("The string \"%s\" is palindrome!\n", str);
    } else {
        printf("The string \"%s\" is not palindrome.\n", str);
    }

    return 0;
}