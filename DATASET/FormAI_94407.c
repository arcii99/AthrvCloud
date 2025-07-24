//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
    char cat_lang[100];
    printf("Enter a phrase in C Cat Language: ");
    fgets(cat_lang, 100, stdin); // takes input from user

    char trans_lang[100];
    int j = 0;

    // loop through each character of input and translate accordingly
    for (int i = 0; i < strlen(cat_lang); i++) {
        if (cat_lang[i] == 'm') {
            trans_lang[j++] = 'C'; // translates 'm' to 'C'
        }
        else if (cat_lang[i] == 'e') {
            trans_lang[j++] = 'a'; // translates 'e' to 'a'
        }
        else if (cat_lang[i] == 'w') {
            trans_lang[j++] = 't'; // translates 'w' to 't'
        }
        else if (cat_lang[i] == 'q') {
            trans_lang[j++] = 'b'; // translates 'q' to 'b'
        }
        else if (cat_lang[i] == 's') {
            trans_lang[j++] = 'n'; // translates 's' to 'n'
        }
        else if (cat_lang[i] == 'y') {
            trans_lang[j++] = 'i'; // translates 'y' to 'i'
        }
        else {
            trans_lang[j++] = cat_lang[i]; // no translation necessary
        }
    }
    printf("Translated Phrase: %s\n", trans_lang);

    return 0;
}