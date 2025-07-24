//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void translate(char word[]) {
    char translated[20];

    // Translate common words
    if(strcmp(word, "meow") == 0) {
        strcpy(translated, "hello");
    } else if(strcmp(word, "purr") == 0) {
        strcpy(translated, "yes");
    } else if(strcmp(word, "hiss") == 0) {
        strcpy(translated, "no");
    } else if(strcmp(word, "yowl") == 0) {
        strcpy(translated, "help");
    } else {
        strcpy(translated, "unknown");
    }

    printf("%s ", translated);
}

int main() {
    char sentence[100];
    char word[20];

    printf("Enter a sentence in C Cat Language: ");
    fgets(sentence, 100, stdin);

    printf("Translated sentence: ");
    for(int i = 0; i < strlen(sentence); i++) {
        if(sentence[i] != ' ' && sentence[i] != '\n') {
            strncat(word, &sentence[i], 1);
        } else {
            translate(word);
            memset(word, 0, sizeof(word));
        }
    }

    return 0;
}