//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>

char* catWords[] = {"meow", "purr", "hiss", "scratch", "claw"};

char* englishWords[] = {"hello", "love", "no", "annoyed", "angry"};

int wordCount = 5;

char* translateToEnglish(char* catWord) {
    int i;
    for (i = 0; i < wordCount; i++) {
        if (strcmp(catWords[i], catWord) == 0) {
            return englishWords[i];
        }
    }
    return "unknown";
}

char* translateToCat(char* englishWord) {
    int i;
    for (i = 0; i < wordCount; i++) {
        if (strcmp(englishWords[i], englishWord) == 0) {
            return catWords[i];
        }
    }
    return "unknown";
}

int main() {
    char catWord[10];
    char englishWord[10];
    
    printf("Enter a cat word:\n");
    scanf("%s", catWord);
    printf("Translation: %s\n", translateToEnglish(catWord));
    
    printf("Enter an English word:\n");
    scanf("%s", englishWord);
    printf("Translation: %s\n", translateToCat(englishWord));
    
    return 0;
}