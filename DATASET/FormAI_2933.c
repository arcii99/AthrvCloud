//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    char catTalk[100];
    printf("Meow, meow! Welcome to the CAT LANGUAGE TRANSLATOR!\n");
    printf("Meow, meow! Please enter a sentence that you want me to translate into human language:\n");
    scanf("%[^\n]s", catTalk);
    getchar();

    printf("\n");

    if (strcmp(catTalk, "Meow, meow!") == 0) {
        printf("I'm sorry, I cannot translate this as it is a universal feline greeting.\n");
    }
    else {
        int length = strlen(catTalk);
        for (int i = 0; i < length; i++) {
            if (catTalk[i] == 'm' || catTalk[i] == 'M') {
                printf(" ");
            }
            else if (catTalk[i] == 'e' || catTalk[i] == 'E') {
                printf("i");
            }
            else if (catTalk[i] == 'o' || catTalk[i] == 'O') {
                printf("u");
            }
            else if (catTalk[i] == 'w' || catTalk[i] == 'W') {
                printf("l");
            }
            else if (catTalk[i] == ',') {
                printf(",");
            }
            else if (catTalk[i] == '!') {
                printf(" meow!");
            }
            else {
                printf("%c", catTalk[i]);
            }
        }
        printf("\n");
        printf("Meow, meow! Did that make sense to you?\n");
    }

    return 0;
}