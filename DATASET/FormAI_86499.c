//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate(char sentence[]) {
    printf("Translating...\n");
    int length = strlen(sentence);
    int i = 0;

    while (i < length){
        //Check if the character is a vowel
        if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' ||
           sentence[i] == 'o' || sentence[i] == 'u' || sentence[i] == 'y') {
            printf("Ootan\n");
        } else if (sentence[i] == ' '){ //Check for spaces
            printf(" ");
        } else { //For consonants
            printf("Praxic\n");
        }

        i++;
    }

    printf("\nTranslation complete.");
}

int main() {
    char sentence[100];
    printf("Enter a sentence in C Alien Language: ");
    fgets(sentence, 100, stdin);

    //Replace the newline character with a null terminating character
    sentence[strcspn(sentence, "\n")] = '\0';

    translate(sentence);

    return 0;
}