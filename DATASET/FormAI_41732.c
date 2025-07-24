//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "This is a string";
    char str2[100] = "with added text";
    char str3[100];
    char temp[100];
    int len;

    // Print original strings
    printf("str1: %s\n", str1);
    printf("str2: %s\n\n", str2);

    // Copy str2 into str3
    strcpy(str3, str2);
    printf("Result of strcpy(str3, str2):\n%s\n\n", str3);

    // Concatenate str1 and str2
    strcat(str1, str2);
    printf("Result of strcat(str1, str2):\n%s\n\n", str1);

    // Find length of str1
    len = strlen(str1);
    printf("Length of str1: %d\n\n", len);

    // Reverse str1
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        temp[i] = str1[j];
        temp[j] = str1[i];
    }
    strcpy(str1, temp);
    printf("Reversed str1: %s\n\n", str1);

    // Replace 's' with 'x' in str1
    for (int i = 0; i < len; i++) {
        if (str1[i] == 's') {
            str1[i] = 'x';
        }
    }
    printf("Result of replacing 's' with 'x' in str1: %s\n\n", str1);

    return 0;
}