//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to translate Alien Language to English
void translate(char alien[]) {
    char english[21];
    int vowel_count = 0, consonant_count = 0;

    // check each letter of alien word for vowel or consonant
    for (int i = 0; i < strlen(alien); i++) {
        // if letter is a vowel
        if (alien[i] == 'a' || alien[i] == 'e' || alien[i] == 'i' || alien[i] == 'o' || alien[i] == 'u') {
            english[i] = alien[i];
            vowel_count++;
        }
        // if letter is a consonant
        else {
            english[i] = alien[i] - 1; // shift letter back by 1 in the English alphabet
            consonant_count++;
        }
    }

    // print out translation and statistics
    printf("Alien word: %s\n", alien);
    printf("Translated to English: %s\n", english);
    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);
}

int main() {
    char alien1[] = "qzmfs";
    char alien2[] = "plrgtyn";
    char alien3[] = "dvkj";
    char alien4[] = "sfqm";
    char alien5[] = "bnhltw";

    // translate each alien word
    translate(alien1);
    printf("\n");
    translate(alien2);
    printf("\n");
    translate(alien3);
    printf("\n");
    translate(alien4);
    printf("\n");
    translate(alien5);

    return 0;
}