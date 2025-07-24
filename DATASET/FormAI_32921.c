//FormAI DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp;
    int i, j, length;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Concatenate str1 and str2
    length = strlen(str1);
    for (i = 0; str2[i] != '\0'; i++) {
        str1[length + i] = str2[i];
    }
    str1[length + i] = '\0';

    printf("\nConcatenated string: %s", str1);

    // Reverse str1
    length = strlen(str1);
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }

    printf("\nReversed string: %s", str1);

    // Check if str1 is a palindrome
    length = strlen(str1);
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str1[i] != str1[j]) {
            printf("\n%s is not a palindrome.", str1);
            return 0;
        }
    }

    printf("\n%s is a palindrome.", str1);

    return 0;
}