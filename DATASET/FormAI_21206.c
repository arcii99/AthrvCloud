//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the C Cat Language Translator!\n");

    char sentence[1000];
    printf("Enter a sentence in Cat Language: ");
    scanf("%[^\n]", sentence);

    char translated_sentence[1000] = "";
    int length = strlen(sentence);

    for (int i = 0; i < length; i++) {
        if (sentence[i] == 'm' && sentence[i + 1] == 'e' && (sentence[i + 2] == 'o' || sentence[i + 2] == 'a')) {
            strcat(translated_sentence, "you");
            i += 2;
        } else if (sentence[i] == 'm' && sentence[i + 1] == 'y') {
            strcat(translated_sentence, "your");
            i += 1;
        } else if (sentence[i] == 'i' && sentence[i + 1] == 'n') {
            strcat(translated_sentence, "out");
            i += 1;
        } else if (sentence[i] == 'm' && sentence[i + 1] == 'o' && sentence[i + 2] == 'w') {
            strcat(translated_sentence, "hello");
            i += 2;
        } else if (sentence[i] == 'h' && sentence[i + 1] == 'i' && sentence[i + 2] == 's' && sentence[i + 3] == 's') {
            strcat(translated_sentence, "thank you");
            i += 3;
        } else if (sentence[i] == 'p' && sentence[i + 1] == 'u' && sentence[i + 2] == 'r' && sentence[i + 3] == 'r') {
            strcat(translated_sentence, "please");
            i += 3;
        } else if (sentence[i] == 'e' && sentence[i + 1] == 'a' && sentence[i + 2] == 't') {
            strcat(translated_sentence, "food");
            i += 2;
        } else if (sentence[i] == 'n' && sentence[i + 1] == 'o' && sentence[i + 2] == 's' && sentence[i + 3] == 'i') {
            strcat(translated_sentence, "yes");
            i += 3;
        } else {
            strncat(translated_sentence, &sentence[i], 1);
        }
    }

    printf("Your sentence in English: %s\n", translated_sentence);

    return 0;
}