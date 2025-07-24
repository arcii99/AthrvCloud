//FormAI DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "Hello";
    char str2[50] = " World";
    char new_str[100];

    // Concatenate str1 and str2 into new_str
    strcat(new_str, str1);
    strcat(new_str, str2);

    printf("Old Strings: %s and %s\n", str1, str2);
    printf("New String: %s\n", new_str);

    // Copy new_str into str1
    strcpy(str1, new_str);
    printf("Copied String from new_str to str1: %s\n", str1);

    // Get the length of str1
    int length = strlen(str1);
    printf("Length of str1: %d\n", length);

    // Change all characters in str1 to uppercase
    for(int i = 0; i < length; i++) {
        str1[i] = toupper(str1[i]);
    }
    printf("Uppercase String: %s\n", str1);

    return 0;
}