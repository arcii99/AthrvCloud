//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <string.h>

void translator(char alien_word[]) {
    int len = strlen(alien_word);
    int vowels[len];
    int vowel_count = 0;
    int consonants[len];
    int consonant_count = 0;

    for(int i = 0; i < len; i++) {
        if(alien_word[i] == 'a' || alien_word[i] == 'e' || alien_word[i] == 'i' || alien_word[i] == 'o' || alien_word[i] == 'u') {
            vowels[vowel_count] = i;
            vowel_count++;
        } 
        else {
            consonants[consonant_count] = i;
            consonant_count++;
        }
    }

    for(int i = 0; i < vowel_count; i++) {
        printf("%c", alien_word[vowels[i]]);
    }

    printf(" ");

    for(int i = 0; i < consonant_count; i++) {
        printf("%c", alien_word[consonants[i]]);
    }

    printf("\n");
}

int main() {
    int num_words;

    printf("How many alien words do you want to translate? ");
    scanf("%d", &num_words);

    for(int i = 0; i < num_words; i++) {
        printf("Enter alien word %d: ", i+1);
        char alien_word[50];
        scanf("%s", alien_word);
        translator(alien_word);
    }

    return 0;
}