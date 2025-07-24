//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include<stdio.h>
#include<string.h>

void translate(char phrase[]) {
    char translated_phrase[1000] = "";

    for(int i=0; i<strlen(phrase); i++) {
        if(phrase[i] == 'c') {
            strcat(translated_phrase, "meow");
        } else if(phrase[i] == 'C') {
            strcat(translated_phrase, "MEOW");
        } else {
            strncat(translated_phrase, &phrase[i], 1);
        }
    }

    printf("%s", translated_phrase);
}

int main() {
    char phrase[1000];
    printf("Enter a phrase in C Cat Language: ");
    fgets(phrase, sizeof(phrase), stdin);

    translate(phrase);

    return 0;
}