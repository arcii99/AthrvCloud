//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char english[100];
    char cat[100];
    int i;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter your message: ");
    fgets(english, 100, stdin);

    for (i = 0; i < strlen(english); i++) {
        if (english[i] == 'h' || english[i] == 'h') {
            strcat(cat, "meow");
        } else if (english[i] == 't' || english[i] == 'T') {
            strcat(cat, "purr");
        } else if (english[i] == 's' || english[i] == 'S') {
            strcat(cat, "hiss");
        } else if (english[i] == 'e' || english[i] == 'E') {
            strcat(cat, "mew");
        } else if (english[i] == ' ' || english[i] == '\n') {
            strcat(cat, " ");
        }
    }

    printf("In cat language, your message is: %s\n", cat);

    return 0;
}