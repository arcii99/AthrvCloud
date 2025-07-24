//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// Function to translate C Cat language sentences
void cCatTranslator(char sentence[]) {
    // Split the sentence into words
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        // Check if the word is a C Cat keyword
        if (strcmp(word, "meow") == 0) {
            printf("int ");
        } else if (strcmp(word, "purr") == 0) {
            printf("char ");
        } else if (strcmp(word, "hiss") == 0) {
            printf("float ");
        } else if (strcmp(word, "pounce") == 0) {
            printf("double ");
        } else if (strcmp(word, "scratch") == 0) {
            printf("long ");
        } else if (strcmp(word, "claw") == 0) {
            printf("short ");
        } else if (strcmp(word, "lick") == 0) {
            printf("void ");
        } else {
            // If the word is not a keyword, print it as is
            printf("%s ", word);
        }
        // Move to the next word
        word = strtok(NULL, " ");
    }
}

int main() {
    // Examples of C Cat language sentences
    char sentence1[] = "meow main purr meow argc, purr purr char pawprintpurr[]purr";
    char sentence2[] = "meow getchar lick meow";
    char sentence3[] = "scratch catnip equals meow 5 pounce 3.14 meow";
    
    // Translate the sentences and print the result
    cCatTranslator(sentence1);
    printf("\n");
    cCatTranslator(sentence2);
    printf("\n");
    cCatTranslator(sentence3);
    
    return 0;
}