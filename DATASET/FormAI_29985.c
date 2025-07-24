//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    char newStr[len + 1];

    // Reverse the string
    for (int i = 0; i < len; i++) {
        newStr[i] = str[len - i - 1];
    }
    newStr[len] = '\0';
    printf("Reversed string: %s\n", newStr);

    // Count number of vowels in the string
    int vowels = 0;
    for (int i = 0; i < len; i++) {
        if (newStr[i] == 'a' || newStr[i] == 'e' || newStr[i] == 'i' || newStr[i] == 'o' || newStr[i] == 'u') {
            vowels++;
        }
    }
    printf("Number of vowels in the string: %d\n", vowels);

    // Remove all vowels from the string
    char newStr2[len + 1];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (newStr[i] != 'a' && newStr[i] != 'e' && newStr[i] != 'i' && newStr[i] != 'o' && newStr[i] != 'u') {
            newStr2[j] = newStr[i];
            j++;
        }
    }
    newStr2[j] = '\0';
    printf("String with vowels removed: %s\n", newStr2);

    // Add a random word to the end of the string
    char* randomWord = "supercalifragilisticexpialidocious";
    strcat(newStr2, randomWord);
    printf("New string with random word added: %s\n", newStr2);

    return 0;
}