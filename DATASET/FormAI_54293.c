//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

void cat_translate(char sentence[]) {
    char cat_sentence[1000] = "";
    int i, j;

    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            strcat(cat_sentence, "meow ");
        } else if (sentence[i] == 'e' || sentence[i] == 'E') {
            strcat(cat_sentence, "meow ");
        } else {
            strcat(cat_sentence, "nya ");
        }
    }

    printf("Cat: %s\n", cat_sentence);
}

int main() {
    char sentence[1000];

    printf("English: ");
    fgets(sentence, 1000, stdin);

    printf("Translation:\n");
    cat_translate(sentence);

    return 0;
}