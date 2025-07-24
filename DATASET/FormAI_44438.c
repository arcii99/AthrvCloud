//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>

int main() {

    char sentence[1000];
    int i = 0;

    printf("Enter a sentence in C Cat Language:\n");

    // read input sentence until a newline character is encountered
    while ((sentence[i] = getchar()) != '\n') {
        i++;
    }

    // null terminate the string
    sentence[i] = '\0';

    printf("\nTranslation in English Cat Language: ");

    i = 0;

    // loop through the input string until null character is encountered
    while (sentence[i] != '\0') {
        // print the translated character according to C Cat Language rules
        switch(sentence[i]) {
            case 'M': printf("Meow"); break;
            case 'P': printf("Purr"); break;
            case 'H': printf("Hiss"); break;
            case 'W': printf("Whisker"); break;
            default: printf("%c", sentence[i]); // print the character as it is
        }
        i++;
    }

    return 0;
}