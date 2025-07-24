//FormAI DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <string.h>

// Function that removes all the vowels from a given string
void removeVowels(char *str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                i++;
            } else {
                str[j] = str[i];
                i++;
                j++;
            }
    }
    str[j] = '\0';
}

int main() {
    char str1[100], str2[100];
    printf("Enter a string: ");
    scanf("%s", str1);

    // Copying the original string to another string
    strcpy(str2, str1);

    // Removing vowels from str1 and printing the modified string
    removeVowels(str1);
    printf("Modified String: %s\n", str1);

    // Printing the original string (str2) to show that it hasn't been modified
    printf("Original String: %s\n", str2);

    return 0;
}