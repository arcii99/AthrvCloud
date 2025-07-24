//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int is_palindrome(char str[]);
void remove_punct(char str[]);

int main() {
    char str[MAX_LEN];

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    remove_punct(str);

    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}

int is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

void remove_punct(char str[]) {
    int len = strlen(str);
    char result[MAX_LEN];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            result[j] = tolower(str[i]);
            j++;
        }
    }
    result[j] = '\0';
    strcpy(str, result);
}