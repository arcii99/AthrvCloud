//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void clean_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if(isalpha(str[i]) == 0)
            for(int j = i; j < len; j++)
                str[j] = str[j+1];
        str[i] = tolower(str[i]);
    }
}

int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-1-i])
            return 0;
    }
    return 1;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    // Remove the newline character
    str[strcspn(str, "\n")] = 0;
    // Clean the string
    clean_string(str);
    // Check if it's a palindrome
    if (is_palindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
    return 0;
}