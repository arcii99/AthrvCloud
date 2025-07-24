//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {

    char text[1000];
    int consonants = 0, vowels = 0, spaces = 0, digits = 0, symbols = 0;
    
    printf("Please enter some text:\n");
    fgets(text, sizeof(text), stdin);
    text[strlen(text)-1] = '\0';

    for(int i=0; i<strlen(text); i++) {
        
        if(text[i] == ' ') {
            spaces++;
        }
        else if(text[i] == '0' || text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4' || text[i] == '5' || text[i] == '6' || text[i] == '7' || text[i] == '8' || text[i] == '9') {
            digits++;
        }
        else if(isalpha(text[i])) {
            if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
                vowels++;
            }
            else {
                consonants++;
            }
        }
        else {
            symbols++;
        }
    }

    printf("\nText analysis:\n\n");
    printf("Number of consonants: %d\n", consonants);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of spaces: %d\n", spaces);
    printf("Number of digits: %d\n", digits);
    printf("Number of symbols: %d\n", symbols);

    return 0;
}