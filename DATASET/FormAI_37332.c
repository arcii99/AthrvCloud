//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include <stdio.h>
#include <string.h>

void C_Cat_Language_Translator(char word[]) {
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        if (word[i] == 'c') {
            printf("meow ");
        }
        else if (word[i] == 'C') {
            printf("MEOW ");
        }
        else {
            printf("%c", word[i]);
        }
    }
    printf("\n");
}

int main() {
    char word[100];

    printf("Enter an English word: ");
    scanf("%s", word);

    printf("In C Cat Language: ");
    C_Cat_Language_Translator(word);

    return 0;
}