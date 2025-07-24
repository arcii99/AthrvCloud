//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
  
    printf("Enter a string: ");
    fgets(str, 100, stdin);
  
    for (int i = 0; str[i] != '\0'; i++) {
        // Count vowels
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
            str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
            str[i] == 'U') {
            vowels++;
        }
        // Count consonants
        else if ((str[i] >= 'a' && str[i] <= 'z') ||
                 (str[i] >= 'A' && str[i] <= 'Z')) {
            consonants++;
        }
        // Count digits
        else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        }
        // Count spaces
        else if (str[i] == ' ') {
            spaces++;
        }
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of spaces: %d\n", spaces);

    return 0;
}