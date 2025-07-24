//FormAI DATASET v1.0 Category: String manipulation ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50], new_str[100];
    int i = 0, j = 0;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove the newline character from the end of the strings
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    // Concatenate the two strings
    while (str1[i] != '\0') {
        new_str[j] = str1[i];
        i++;
        j++;
    }

    i = 0;

    while (str2[i] != '\0') {
        new_str[j] = str2[i];
        i++;
        j++;
    }

    new_str[j] = '\0';

    printf("The concatenated string is: %s\n", new_str);

    // Reverse the new string
    int len = strlen(new_str);

    for (i = 0; i < len / 2; i++) {
        char temp = new_str[i];
        new_str[i] = new_str[len - i - 1];
        new_str[len - i - 1] = temp;
    }

    printf("The reversed string is: %s\n", new_str);

    // Remove all vowels from the reversed string
    i = 0;
    j = 0;

    while (new_str[i] != '\0') {
        if (new_str[i] != 'a' && new_str[i] != 'e' && new_str[i] != 'i' && new_str[i] != 'o' && new_str[i] != 'u' &&
            new_str[i] != 'A' && new_str[i] != 'E' && new_str[i] != 'I' && new_str[i] != 'O' && new_str[i] != 'U') {
            new_str[j] = new_str[i];
            j++;
        }
        i++;
    }

    new_str[j] = '\0';

    printf("The reversed string without vowels is: %s\n", new_str);

    return 0;
}