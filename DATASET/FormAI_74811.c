//FormAI DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[100];
    int vowels = 0, consonants = 0;

    printf("Please enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for(int i = 0; sentence[i] != '\0'; i++) {
        if(isalpha(sentence[i])) {
            switch(tolower(sentence[i])) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    consonants++;
            }
        }
    }

    printf("Your sentence contains %d vowels and %d consonants.", vowels, consonants);

    return 0;
}