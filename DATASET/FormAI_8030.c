//FormAI DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100];
    int length, vowels = 0, consonants = 0, digits = 0, spaces = 0;

    printf("Enter a string: \n");
    scanf("%[^\n]", inputString);
    length = strlen(inputString);

    for (int i = 0; i < length; i++) {
        if (inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' ||
            inputString[i] == 'o' || inputString[i] == 'u' || inputString[i] == 'A' ||
            inputString[i] == 'E' || inputString[i] == 'I' || inputString[i] == 'O' ||
            inputString[i] == 'U') {
            vowels++;
        } else if ((inputString[i] >= 'a' && inputString[i] <= 'z') ||
                   (inputString[i] >= 'A' && inputString[i] <= 'Z')) {
            consonants++;
        } else if (inputString[i] >= '0' && inputString[i] <= '9') {
            digits++;
        } else if (inputString[i] == ' ') {
            spaces++;
        }
    }

    printf("\n\n**************************************************\n\n");
    printf("Your string \"%s\" has:\n", inputString);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("\n**************************************************\n");

    return 0;
}