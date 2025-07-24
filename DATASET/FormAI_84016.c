//FormAI DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello,";
    char str2[] = " World!";
    char str3[50];

    // Concatenating str1 and str2
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Copying str2 to str3
    strcpy(str3, str2);
    printf("Copied string: %s\n", str3);

    // Finding the length of str1
    int len1 = strlen(str1);
    printf("Length of str1: %d\n", len1);

    // Comparing str1 and str2
    int cmp = strcmp(str1, str2);
    if (cmp == 0) {
        printf("str1 and str2 are equal\n");
    } else {
        printf("str1 and str2 are not equal\n");
    }

    // Finding the first occurrence of a character in str1
    char ch = 'o';
    char* ptr = strchr(str1, ch);
    if (ptr != NULL) {
        printf("First occurrence of %c in %s is at index: %d\n", ch, str1, ptr - str1);
    } else {
        printf("%c not found in %s\n", ch, str1);
    }

    return 0;
}