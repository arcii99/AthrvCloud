//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str1[100], str2[100];
    int i, j;

    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    // Find the length of both strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Concatenate the two strings
    for (i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i];
    }

    // Reverse the concatenated string
    int len = len1 + len2;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }

    // Replace all vowels with '*'
    for (i = 0; i < len; i++) {
        if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' ||
            str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U') {
            str1[i] = '*';
        }
    }

    printf("Modified string: %s", str1);

    return 0;
}