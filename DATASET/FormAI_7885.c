//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <string.h>

char* translate(char* phrase) {
    char catTalk[256] = "";
    char currentWord[256];
    int i = 0, j = 0;

    while (phrase[i] != '\0') {
        if (phrase[i] == ' ') {
            if (strcmp(currentWord, "the") == 0) {
                strcat(catTalk, "meow");
            } else if (strcmp(currentWord, "of") == 0) {
                strcat(catTalk, "purr");
            } else if (strcmp(currentWord, "and") == 0) {
                strcat(catTalk, "yowl");
            } else {
                strcat(catTalk, "meow");
            }
            strcat(catTalk, " ");
            memset(currentWord, 0, strlen(currentWord));
            j = 0;
        } else {
            currentWord[j] = phrase[i];
            j++;
        }
        i++;
    }

    if (strcmp(currentWord, "the") == 0) {
        strcat(catTalk, "meow");
    } else if (strcmp(currentWord, "of") == 0) {
        strcat(catTalk, "purr");
    } else if (strcmp(currentWord, "and") == 0) {
        strcat(catTalk, "yowl");
    } else {
        strcat(catTalk, "meow");
    }

    return catTalk;
}

int main() {
    char* catTalk = translate("Hello world");
    printf("%s\n", catTalk);
    return 0;
}