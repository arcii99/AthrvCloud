//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char string[100];
    int len, vowels = 0, consonants = 0, uppercase = 0;
    
    printf("Enter some text: ");
    fgets(string, 100, stdin);
    
    len = strlen(string);
    
    for (int i = 0; i < len; i++) {
        if (isalpha(string[i])) {
            if (tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        
        if (isupper(string[i])) {
            uppercase++;
            string[i] = tolower(string[i]); // Convert uppercase letter to lowercase
        }
    }
    
    printf("\nText analysis:\n");
    printf("----------------\n");
    printf("Total number of characters: %d\n", len-1); // Subtract 1 to exclude newline character
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of uppercase letters: %d\n", uppercase);
    printf("Lowercase text: %s", string);
    
    return 0;
}