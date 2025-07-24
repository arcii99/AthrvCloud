//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int is_palindrome(char *string);
int get_string(char *string, int max_length);

int main() {
    char string[MAX_LENGTH];
    int length;

    printf("Enter a string to check if it is a palindrome: ");
    length = get_string(string, MAX_LENGTH);

    if (is_palindrome(string)) {
        printf("%s is a palindrome\n", string);
    } else {
        printf("%s is not a palindrome\n", string);
    }

    return 0;
}

int is_palindrome(char *string) {
    int length = strlen(string);
    char *front = string;
    char *back = string + length - 1;

    while (front < back) {
        while (!isalnum(*front) && front < back) {
            front++;
        }
        while (!isalnum(*back) && front < back) {
            back--;
        }
        if (tolower(*front) != tolower(*back)) {
            return 0;
        }
        front++;
        back--;
    }

    return 1;
}

int get_string(char *string, int max_length) {
    char buffer[MAX_LENGTH];
    int length = 0;

    if (fgets(buffer, MAX_LENGTH, stdin)) {
        length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
            length--;
        }
    }

    strncpy(string, buffer, max_length);

    return length;
}