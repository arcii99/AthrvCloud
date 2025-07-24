//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";
    char temp[20];

    printf("Original strings:\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    // concatenate strings
    strcat(str1, " ");
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // copy string
    strcpy(temp, str1);
    printf("Copied string: %s\n", temp);

    // reverse string
    int len = strlen(str1);
    int i;
    for (i = 0; i < len / 2; i++) {
        char c = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = c;
    }
    printf("Reversed string: %s\n", str1);

    // find substring
    char sub[10] = "Wor";
    char *ptr = strstr(str1, sub);
    printf("Substring '%s' found at position %ld\n", sub, ptr - str1);

    // count occurrences of character
    char c = 'l';
    int count = 0;
    for (i = 0; i < len; i++) {
        if (str1[i] == c) {
            count++;
        }
    }
    printf("Character '%c' occurs %d times\n", c, count);

    return 0;
}