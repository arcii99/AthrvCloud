//FormAI DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program will convert a given string to title case and back to uppercase */

/* Function to convert a string to title case */
void toTitleCase(char *str) {
    int len = strlen(str);
    int i;

    /* First character of the string should be capitalized */
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }

    /* Capitalize every character after a space */
    for (i = 1; i < len; i++) {
        if (str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

/* Function to convert a string to uppercase */
void toUpperCase(char *str) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("\nOriginal string: %s\n", str);

    toTitleCase(str);
    printf("\nString in title case: %s\n", str);

    toUpperCase(str);
    printf("\nString in uppercase: %s\n", str);

    return 0;
}