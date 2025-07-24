//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_lang[100];
    int i, j;

    printf("Enter a sentence in C Cat Language: ");
    gets(c_cat_lang);

    // Loop through the sentence and replace every instance of "meow" with "C"
    for (i = 0; i < strlen(c_cat_lang); i++) {
        if (c_cat_lang[i] == 'm' && c_cat_lang[i+1] == 'e' && c_cat_lang[i+2] == 'o' && c_cat_lang[i+3] == 'w') {
            c_cat_lang[i] = 'C';
            for (j = i+1; j < strlen(c_cat_lang)-3; j++) {
                c_cat_lang[j] = c_cat_lang[j+3];
            }
            c_cat_lang[j] = '\0';
        }
    }

    // Print out the translated sentence
    printf("\nTranslated sentence: %s\n", c_cat_lang);

    return 0;
}