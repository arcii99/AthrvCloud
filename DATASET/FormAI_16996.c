//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

char* translate(char* english) {
    char* cat = strdup(english); // Copy the input string
    int length = strlen(cat);

    // Translate words
    if (strcmp(cat, "hello") == 0) {
        strcpy(cat, "meow");
    } else if (strcmp(cat, "world") == 0) {
        strcpy(cat, "purr");
    } else if (strcmp(cat, "food") == 0) {
        strcpy(cat, "yum");
    } else if (strcmp(cat, "water") == 0) {
        strcpy(cat, "hiss");
    } else if (strcmp(cat, "sleep") == 0) {
        strcpy(cat, "nap");
    }

    // Add cat noises at the end
    cat[length] = ' ';
    cat[length+1] = 'm';
    cat[length+2] = 'e';
    cat[length+3] = 'o';
    cat[length+4] = 'w';
    cat[length+5] = '\0';

    return cat;
}

int main() {
    char english[100];
    printf("Enter English text:\n");
    fgets(english, 100, stdin);

    char* cat = translate(english);
    printf("Translated to Cat language: %s\n", cat);
    free(cat);
    
    return 0;
}