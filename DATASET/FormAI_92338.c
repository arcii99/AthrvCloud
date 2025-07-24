//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], rev[100];
    int len, i, j, count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    // Reversing the String
    for (i = len - 1; i >= 0; i--) {
        rev[len - i - 1] = str[i];
    }
    rev[len] = '\0';

    // Counting the number of occurrences of each letter
    printf("\nOccurrences of each letter in the string:\n");
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            count = 1;
            for (j = i + 1; j < len; j++) {
                if (str[i] == str[j]) {
                    count++;
                    str[j] = ' ';
                }
            }
            printf("%c - %d\n", str[i], count);
        }
    }

    // Comparing the original string with the reversed string
    if (strcmp(str, rev) == 0) {
        printf("\nThe original string is a palindrome.");
    } else {
        printf("\nThe original string is not a palindrome.");
    }

    return 0;
}