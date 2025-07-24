//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dictionary of words in Alien Language
char alienWords[5][10] = {"sckrow", "oomlaut", "flezion", "krump", "quol"};

//Corresponding translations in English
char englishWords[5][15] = {"hello", "goodbye", "thank you", "sorry", "please"};

//Function to translate the Alien Language word to English
void translate(char *word) {
    int i;
    for(i = 0; i < 5; i++) {
        if(strcmp(word, alienWords[i]) == 0) {
            printf("Translation: %s\n", englishWords[i]);
            return;
        }
    }
    printf("Translation not found for %s\n", word);
}

int main() {
    char input[10];
    printf("Enter a word in Alien Language: ");
    scanf("%s", &input);
    translate(input);
    return 0;
}