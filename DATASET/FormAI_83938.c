//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
// C Cat Language Translator
// Cyberpunk style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[1000];
    char output[1000];
    char* catSounds[] = {"meow", "purr", "hiss", "yowl", "growl", "chirp"};
    char catChar[] = {'_','^','`','-','='};
    int catMeowCount = 0;
    int catPurrCount = 0;
    int catHissCount = 0;
    int catYowlCount = 0;
    int catGrowlCount = 0;
    int catChirpCount = 0;
    int catCharacterIndex = 0;
    int i, j, len;

    printf("Enter a sentence in C Cat Language: ");
    fgets(input, 1000, stdin);
    len = strlen(input);

    printf("Translating...\n");
        
    for (i = 0; i < len; i++) {
        if (input[i] == ' ') {
            continue;
        }

        if (input[i] == 'M' || input[i] == 'm') {
            output[i] = catSounds[0][catMeowCount % 4];
            catMeowCount++;
        } else if (input[i] == 'P' || input[i] == 'p') {
            output[i] = catSounds[1][catPurrCount % 4];
            catPurrCount++;
        } else if (input[i] == 'H' || input[i] == 'h') {
            output[i] = catSounds[2][catHissCount % 4];
            catHissCount++;
        } else if (input[i] == 'Y' || input[i] == 'y') {
            output[i] = catSounds[3][catYowlCount % 4];
            catYowlCount++;
        } else if (input[i] == 'G' || input[i] == 'g') {
            output[i] = catSounds[4][catGrowlCount % 4];
            catGrowlCount++;
        } else if (input[i] == 'C' || input[i] == 'c') {
            output[i] = catSounds[5][catChirpCount % 4];
            catChirpCount++;
        } else {
            output[i] = input[i];
        }

        if (i % 5 == 0) {
            catCharacterIndex++;
            if (catCharacterIndex >= 5) {
                catCharacterIndex = 0;
            }
        }

        printf("%c%c", output[i], catChar[catCharacterIndex]);
    }

    printf("\n");

    return 0;
}