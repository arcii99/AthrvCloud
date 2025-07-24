//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DECLARATION OF GLOBAL VARIABLES */
char cinput[100];
char catoutput[100];
int ctoi;

/* FUNCTION DECLARATIONS */
int count_vowels(char*);
int translate_cat_language(char*);

/* MAIN FUNCTION */
int main(int argc, char *argv[]) {
    /* ACCEPT USER INPUT */
    printf("Please enter a sentence in Cat Language:\n");
    fgets(cinput, 100, stdin);

    /* REMOVE NEWLINE CHARACTER */
    cinput[strcspn(cinput, "\n")] = 0;

    /* CALL COUNT_VOWELS FUNCTION */
    ctoi = count_vowels(cinput);

    /* CALL TRANSLATE_CAT_LANGUAGE FUNCTION */
    translate_cat_language(cinput);

    /* PRINT OUTPUT */
    printf("Number of vowels: %d\n", ctoi);
    printf("Translated sentence: %s\n", catoutput);

    return 0;
}

/* FUNCTION TO COUNT NUMBER OF VOWELS IN INPUT STRING */
int count_vowels(char *str) {
    int i, count = 0;
    char c;

    for (i = 0; str[i]; i++) {
        c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    return count;
}

/* FUNCTION TO TRANSLATE INPUT STRING INTO CAT LANGUAGE */
int translate_cat_language(char *str) {
    int i;
    char c;

    for(i = 0; i < strlen(str); i++) {
        c = str[i];

        switch(c) {
            case 'a':
                strcat(catoutput, "meow");
                break;
            case 'e':
                strcat(catoutput, "purr");
                break;
            case 'i':
                strcat(catoutput, "hiss");
                break;
            case 'o':
                strcat(catoutput, "yowl");
                break;
            case 'u':
                strcat(catoutput, "growl");
                break;
            default:
                strncat(catoutput, &c, 1);
        }
    }

    return 0;
}