//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char alien_input[100];
    char translated_output[100];

    printf("Greetings, I am the Alien Language Translator, capable of deciphering the complex tongues of extraterrestrials. What would you like me to translate?\n");

    fgets(alien_input, 100, stdin);

    // alien_input is scanned for the presence of "S.O.S" code. 
    if (strstr(alien_input, "1010101") != NULL) {
        printf("Ah, it appears that this is a distress signal. Let us decode it immediately.\n");

        // "S.O.S" in binary is 1010101
        // loop through the input string and check for the presence of "1010101", then add '-' in between each letter.
        int i, j;
        j = 0;
        for (i = 0; i < strlen(alien_input); i+=7) {
            if (alien_input[i] == '1' && alien_input[i+1] == '0' && alien_input[i+2] == '1' && alien_input[i+3] == '0' && alien_input[i+4] == '1' && alien_input[i+5] == '0' && alien_input[i+6] == '1') {
                translated_output[j] = '-';
                translated_output[j+1] = '.';
                translated_output[j+2] = '-';
                j += 3;
            } else {
                translated_output[j] = alien_input[i];
                translated_output[j+1] = alien_input[i+1];
                translated_output[j+2] = alien_input[i+2];
                translated_output[j+3] = alien_input[i+3];
                translated_output[j+4] = alien_input[i+4];
                translated_output[j+5] = alien_input[i+5];
                translated_output[j+6] = alien_input[i+6];
                j += 7;
            }
        }

        printf("The distress signal has been translated to:\n");
        printf("%s", translated_output);
    } else {
        printf("Hmmm, this language is unfamiliar to me. Perhaps we should consult my trusty book of intergalactic languages.\n");
    }

    return 0;
}