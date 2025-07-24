//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a sentence in Cat Language: ");

    char sentence[100];
    fgets(sentence, 100, stdin);

    printf("Your sentence in English: ");
    char *token = strtok(sentence, " ");

    while (token != NULL) {
        if (strcmp(token, "meow") == 0) {
            printf("I ");
        } else if (strcmp(token, "purr") == 0) {
            printf("am happy ");
        } else if (strcmp(token, "hiss") == 0) {
            printf("am angry ");
        } else if (strcmp(token, "scratch") == 0) {
            printf("need attention ");
        } else if (strcmp(token, "eat") == 0) {
            printf("am hungry ");
        } else if (strcmp(token, "run") == 0) {
            printf("am playful ");
        } else {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }
    printf("\nTranslation complete!\n");
    return 0;
}