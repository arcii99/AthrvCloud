//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>

int main() {

    char text[200];
    printf("Enter some text: ");
    scanf("%[^\n]", text);

    int vowels = 0, consonants = 0, digits = 0, spaces = 0, special = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        char currentChar = tolower(text[i]);
        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
            ++vowels;
        }
        else if ((currentChar >= 'a' && currentChar <= 'z')) {
            ++consonants;
        }
        else if (currentChar >= '0' && currentChar <= '9') {
            ++digits;
        }
        else if (currentChar == ' ') {
            ++spaces;
        }
        else {
            ++special;
        }
    }

    printf("\n\n==================================\n");
    printf("Wow! Your Text Analysis is Ready:\n");
    printf("==================================\n\n");

    printf("You Type This:\n\n%s\n\n", text);

    printf("Total Vowels in Text: %d\n", vowels);
    printf("Total Consonants in Text: %d\n", consonants);
    printf("Total Digits in Text: %d\n", digits);
    printf("Total Spaces in Text: %d\n", spaces);
    printf("Total Special Characters in Text: %d\n", special);


    return 0;
}