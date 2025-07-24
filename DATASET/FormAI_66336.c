//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char alienLanguage[] = "xidel eniforp dna srettel txen lliw yletelpmoc dna erutcetihc si emit";
    char englishLanguage[] = "time is hectic and complex, psychology will tell us next letter letters and productivity ledixe";
    char translated[1000] = "";

    printf("Welcome to the C Alien Language Translator!\n");
    printf("The input Alien language is: %s\n", alienLanguage);
    printf("The translated English language is: %s\n", englishLanguage);

    printf("Enter a sentence in Alien language to translate: ");
    fgets(translated, 1000, stdin);

    int length = strlen(translated);

    // Removing newline character from input
    if (translated[length - 1] == '\n') {
        translated[length - 1] = '\0';
    }

    // Finding the index of each word in the input string
    char *word = strtok(translated, " ");
    while (word != NULL) {
        int index = (int)(word - translated);
        char *substring = strstr(alienLanguage, word);
        if (substring != NULL) {
            int length = strlen(substring);
            strncat(translated + index, englishLanguage + index, length);
            strcpy(translated + index + length, translated + index + strlen(word));
        }
        word = strtok(NULL, " ");
    }

    printf("The translated sentence is: %s\n", translated);

    return 0;
}