//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

/* Function to decode Alien language words */
void decode_alien_word(char word[]) {
    int i = 0;
    while(word[i] != '\0') {
        switch(word[i]) {

            /* A -> E */
            case 'A':
                word[i] = 'E';
                break;

            /* B -> F */
            case 'B':
                word[i] = 'F';
                break;

            /* C -> G */
            case 'C':
                word[i] = 'G';
                break;

            /* D -> H */
            case 'D':
                word[i] = 'H';
                break;

            /* E -> I */
            case 'E':
                word[i] = 'I';
                break;

            /* F -> J */
            case 'F':
                word[i] = 'J';
                break;

            /* G -> K */
            case 'G':
                word[i] = 'K';
                break;

            /* H -> L */
            case 'H':
                word[i] = 'L';
                break;

            /* I -> M */
            case 'I':
                word[i] = 'M';
                break;

            /* J -> N */
            case 'J':
                word[i] = 'N';
                break;

            /* K -> O */
            case 'K':
                word[i] = 'O';
                break;

            /* L -> P */
            case 'L':
                word[i] = 'P';
                break;

            /* M -> Q */
            case 'M':
                word[i] = 'Q';
                break;

            /* N -> R */
            case 'N':
                word[i] = 'R';
                break;

            /* O -> S */
            case 'O':
                word[i] = 'S';
                break;

            /* P -> T */
            case 'P':
                word[i] = 'T';
                break;

            /* Q -> U */
            case 'Q':
                word[i] = 'U';
                break;

            /* R -> V */
            case 'R':
                word[i] = 'V';
                break;

            /* S -> W */
            case 'S':
                word[i] = 'W';
                break;

            /* T -> X */
            case 'T':
                word[i] = 'X';
                break;

            /* U -> Y */
            case 'U':
                word[i] = 'Y';
                break;

            /* V -> Z */
            case 'V':
                word[i] = 'Z';
                break;

            /* W -> A */
            case 'W':
                word[i] = 'A';
                break;

            /* X -> B */
            case 'X':
                word[i] = 'B';
                break;

            /* Y -> C */
            case 'Y':
                word[i] = 'C';
                break;

            /* Z -> D */
            case 'Z':
                word[i] = 'D';
                break;
        }

        /* Move to the next letter in the word */
        i++;
    }
}

int main() {
    char input_str[MAX_STR_LEN];
    printf("Enter an Alien Language word: ");
    scanf("%s", input_str);

    /* Call the Alien language word decoder */
    decode_alien_word(input_str);

    /* Print the decoded word */
    printf("Decoded Alien Language word: %s\n", input_str);

    return 0;
}