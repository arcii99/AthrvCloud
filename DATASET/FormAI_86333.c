//FormAI DATASET v1.0 Category: Text processing ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to our text analysis program!\n\n");
    printf("Please enter your text:\n");

    char text[1000];
    fgets(text, sizeof(text), stdin);

    printf("\nAnalyzing your text...\n\n");

    int vowels = 0, consonants = 0, digits = 0, spaces = 0, symbols = 0;

    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
           text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            vowels++;
        }
        else if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            consonants++;
        }
        else if(text[i] >= '0' && text[i] <= '9') {
            digits++;
        }
        else if(text[i] == ' ') {
            spaces++;
        }
        else {
            symbols++;
        }
    }

    printf("Analysis complete.\n\n");

    printf("Here are some insights about your text:\n");
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of spaces: %d\n", spaces);
    printf("Number of symbols: %d\n", symbols);
    
    printf("\nWould you like to see your text in reverse order? (y/n)\n");
    
    char answer = getchar();
    
    if(answer == 'y' || answer == 'Y') {
        printf("Reversing your text...\n\n");
        
        for(int i = strlen(text) - 1; i >= 0; i--) {
            printf("%c", text[i]);
        }
    }
    
    printf("\n\nThank you for using our program.\n");
    
    return 0;
}