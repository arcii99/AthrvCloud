//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

char* alienLanguageTranslator(char* sentence) {
    char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
    char translated[1000] = "";
    int k = 0;
    int len = strlen(sentence);
    for(int i=0; i<len; i++) {
        if (sentence[i] == ' ') {
            strcat(translated, " ");
            continue;
        }
        int isVowel = 0;
        for(int j=0; j<10; j++) {
            if (sentence[i] == vowels[j]) {
                isVowel = 1;
                break;
            }
        }
        if (isVowel) {
            translated[k] = sentence[i];
            translated[k+1] = 'g';
            translated[k+2] = sentence[i];
            k += 3;
        }
        else {
            translated[k] = sentence[i];
            k++;
        }
    }
    return translated;
}

int main() {
    printf("Enter a sentence in alien language: ");
    char sentence[1000];
    fgets(sentence, 1000, stdin);
    sentence[strcspn(sentence, "\n")] = 0;
    char* translatedSentence = alienLanguageTranslator(sentence);
    printf("Translated sentence: %s\n", translatedSentence);
    return 0;
}