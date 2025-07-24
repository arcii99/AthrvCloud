//FormAI DATASET v1.0 Category: String manipulation ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[50];
    char str2[50];
    char result[100];

    // Ask the user to enter two strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove the newline character from the strings
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Concatenate the two strings
    strcat(result, str1);
    strcat(result, " ");
    strcat(result, str2);

    // Convert the first letter of each word to upper case
    for (int i = 0; result[i] != '\0'; i++) {
        if (i == 0 || result[i - 1] == ' ') {
            result[i] = toupper(result[i]);
        }
    }

    // Replace all occurrences of the letter 'a' with 'z'
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] == 'a') {
            result[i] = 'z';
        }
    }

    printf("Result: %s", result);

    return 0;
}