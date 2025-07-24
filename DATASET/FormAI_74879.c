//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void translate(char *str) {
    char buffer[1024] = {0};
    const char *p = str;

    while(*p != '\0') {
        if(isalpha(*p)) {
            if(isupper(*p)) {
                strcat(buffer, "/\\_/\\ ");
            } else {
                strcat(buffer, "/    \\ ");
            }
        } else {
            strcat(buffer, "       ");
        }
        p++;
    }

    printf("%s\n", buffer);
}

int main() {
    char sentence[1024];

    printf("Enter a sentence in English: ");
    fgets(sentence, 1024, stdin);

    printf("\n");
    printf("Translation to Cat language using ASCII art:\n");
    translate(sentence);

    return 0;
}