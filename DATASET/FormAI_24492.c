//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

/* Function to check if a given character is alphanumeric */
int is_alphanumeric(char c) {
    return isalpha(c) || isdigit(c);
}

/* Function to convert a string to lowercase */
void str_to_lowercase(char* str) {
    int i;
    for(i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

/* Function to check if a given string is a palindrome */
int is_palindrome(char* str) {
    int i = 0, j = strlen(str) - 1;
    while(i < j) {
        /* Skip non-alphanumeric characters */
        while(i < j && !is_alphanumeric(str[i])) {
            i++;
        }
        while(i < j && !is_alphanumeric(str[j])) {
            j--;
        }
        /* Convert characters to lowercase */
        str[i] = tolower(str[i]);
        str[j] = tolower(str[j]);
        /* Compare characters */
        if(str[i] != str[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);
    /* Remove newline character from input */
    input[strcspn(input, "\n")] = '\0';
    /* Convert the input string to lowercase */
    str_to_lowercase(input);
    /* Check if the input string is a palindrome */
    if(is_palindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    return 0;
}