//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include<stdio.h>
#include<string.h>
 
void catLanguageTranslator(char catWord[]) {
    char englishWord[20];
 
    if (strcmp(catWord, "meow") == 0) {
        strcpy(englishWord, "hello");
    }
    else if (strcmp(catWord, "purr") == 0) {
        strcpy(englishWord, "thank you");
    }
    else if (strcmp(catWord, "hiss") == 0) {
        strcpy(englishWord, "go away");
    }
    else if (strcmp(catWord, "scratch") == 0) {
        strcpy(englishWord, "pet me");
    }
    else if (strcmp(catWord, "yowl") == 0) {
        strcpy(englishWord, "feed me");
    }
    else {
        printf("Sorry, I don't understand \n");
        return;
    }
 
    printf("%s \n", englishWord);
}
 
int main() {
    char catWord[20];
 
    printf("Enter a word in cat language: ");
    scanf("%s", catWord);
 
    catLanguageTranslator(catWord);
 
    return 0;
}