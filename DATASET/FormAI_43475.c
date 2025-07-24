//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50];
    char str2[50];
    char str3[50];
    int length;

    printf("Enter a string: ");
    fgets(str1, 50, stdin);

    // Reversing the string
    length = strlen(str1);
    for (int i = 0; i < length; i++) {
        str2[i] = str1[length - 1 - i];
    }
    str2[length] = '\0';
    printf("Reversed string: %s\n", str2);

    // Copying first half of string
    strncpy(str3, str1, length/2);
    str3[length/2] = '\0';
    printf("First half of string: %s\n", str3);

    // Removing spaces from string
    length = strlen(str1);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str1[i] != ' ') {
            str1[j++] = str1[i];
        }
    }
    str1[j] = '\0';
    printf("String without spaces: %s\n", str1);

    // Replacing uppercase characters with lowercase
    length = strlen(str1);
    for (int i = 0; i < length; i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = str1[i] + 32;
        }
    }
    printf("String with uppercases replaced with lowercases: %s\n", str1);

    return 0;
}