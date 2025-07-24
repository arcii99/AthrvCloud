//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
This program is a C Alien Language Translator.
It converts English sentences into its equivalent C Alien Language sentences.
C Alien Language is the language spoken by the aliens from planet C.
*/

int main() {

    char english_sentence[500];
    int i, j;
    int length;
    int word_length;
    char *c_alien_word;
    char *token;
    char delimiters[] = " ,.-!?";

    printf("Enter English sentence to be translated into C Alien Language:\n");
    fgets(english_sentence, sizeof(english_sentence), stdin);

    /* Removing '\n' from input string */
    if ((strlen(english_sentence) > 0) && (english_sentence[strlen(english_sentence) - 1] == '\n'))
        english_sentence[strlen(english_sentence) - 1] = '\0';

    /* Tokenizing sentence into words */
    token = strtok(english_sentence, delimiters);

    /* Loop through each word and translate to C Alien Language */
    while (token != NULL) {

        length = strlen(token);

        /* Allocate memory for new C Alien Language word */
        c_alien_word = (char*) malloc(length + 1);

        /* Copy the input word, reversing its characters */
        for (i = 0; i < length; i++) {
            c_alien_word[i] = token[length - i - 1];
        }
        c_alien_word[length] = '\0';

        /* Print the C Alien Language word */
        printf("%s", c_alien_word);

        /* Count the number of vowels in the word and append 'ok' accordingly */
        word_length = strlen(c_alien_word);
        int vowel_count = 0;
        for (j = 0; j < word_length; j++) {
            if (c_alien_word[j] == 'a' || c_alien_word[j] == 'e' || c_alien_word[j] == 'i' || c_alien_word[j] == 'o' || c_alien_word[j] == 'u') {
                vowel_count++;
            }
        }
        if (vowel_count == 0) {
            printf("wq");
        } else if (vowel_count == 1) {
            printf("op");
        } else {
            printf("ud");
        }
        printf(" ");

        /* Free the memory allocated for C Alien Language word */
        free(c_alien_word);

        /* Get the next word */
        token = strtok(NULL, delimiters);
    }

    return 0;
}