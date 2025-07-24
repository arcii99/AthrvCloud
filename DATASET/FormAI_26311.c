//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], s3[100];

    // Take input from the user
    printf("Enter a string: ");
    scanf("%s", s1);

    // Reverse the string
    int len = strlen(s1);
    int i, j = 0;
    for (i = len - 1; i >= 0; i--) {
        s2[j] = s1[i];
        j++;
    }
    s2[j] = '\0';

    // Concatenate two strings
    strcat(s1, s2);

    // Copy a string to another string
    strcpy(s3, s1);

    // Capitalize the first letter of each word
    len = strlen(s3);
    for (i = 0; i < len; i++) {
        if (i == 0 || s3[i - 1] == ' ') {
            s3[i] = toupper(s3[i]);
        }
    }

    // Print the manipulated string
    printf("Original string: %s\n", s1);
    printf("Reversed string: %s\n", s2);
    printf("Capitalized string: %s\n", s3);

    return 0;
}