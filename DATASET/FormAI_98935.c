//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char text[MAX_LEN];
    int words = 0, vowels = 0, consonants = 0, digits = 0, spaces = 0, symbols = 0;

    printf("Enter some text: ");
    fgets(text, MAX_LEN, stdin);

    text[strcspn(text, "\n")] = '\0'; // Removes the newline character from input

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(text[i])) {
            digits++;
        } else if (isspace(text[i])) {
            spaces++;
        } else {
            symbols++;
        }
    }

    words = spaces + 1;

    printf("\n\nSTATISTICAL ANALYSIS\n");
    printf("--------------------\n");
    printf("Input Text : %s\n", text);
    printf("No. of Words : %d\n", words);
    printf("No. of Vowels : %d\n", vowels);
    printf("No. of Consonants : %d\n", consonants);
    printf("No. of Digits : %d\n", digits);
    printf("No. of Spaces : %d\n", spaces);
    printf("No. of Symbols : %d\n", symbols);

    return 0;
}