//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
/* C Cat Language Translator by Linus Torvalds */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* translate(char*);

int main() {
    char input[100];
    printf("Please enter your C Cat language:\n");
    fgets(input, 100, stdin);
    char* translation = translate(input);
    printf("Translated output:\n%s\n", translation);
    free(translation);
    return 0;
}

char* translate(char* input) {
    int size = strlen(input);
    char* buffer = malloc(size * 3 + 1);
    int i;
    for (i = 0; i < size; i++) {
        if (input[i] == 'c') {
            strcat(buffer, "meow ");
        } else if (input[i] == 'C') {
            strcat(buffer, "MEOW ");
        } else {
            char tmp[2];
            tmp[0] = input[i];
            tmp[1] = '\0';
            strcat(buffer, tmp);
        }
    }
    return buffer;
}