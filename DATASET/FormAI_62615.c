//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>

void convert(char c[]) {
    for (int i = 0; i < strlen(c); i++) {
        if (c[i] == 'a') {
            c[i] = 'b';
        } else if (c[i] == 'b') {
            c[i] = 'a';
        } else if (c[i] == 'c') {
            c[i] = 'd';
        } else if (c[i] == 'd') {
            c[i] = 'c';
        } else if (c[i] == 'e') {
            c[i] = 'f';
        } else if (c[i] == 'f') {
            c[i] = 'e';
        } else if (c[i] == 'g') {
            c[i] = 'h';
        } else if (c[i] == 'h') {
            c[i] = 'g';
        } else if (c[i] == 'i') {
            c[i] = 'j';
        } else if (c[i] == 'j') {
            c[i] = 'i';
        } else if (c[i] == 'k') {
            c[i] = 'l';
        } else if (c[i] == 'l') {
            c[i] = 'k';
        } else if (c[i] == 'm') {
            c[i] = 'n';
        } else if (c[i] == 'n') {
            c[i] = 'm';
        } else if (c[i] == 'o') {
            c[i] = 'p';
        } else if (c[i] == 'p') {
            c[i] = 'o';
        } else if (c[i] == 'q') {
            c[i] = 'r';
        } else if (c[i] == 'r') {
            c[i] = 'q';
        } else if (c[i] == 's') {
            c[i] = 't';
        } else if (c[i] == 't') {
            c[i] = 's';
        } else if (c[i] == 'u') {
            c[i] = 'v';
        } else if (c[i] == 'v') {
            c[i] = 'u';
        } else if (c[i] == 'w') {
            c[i] = 'x';
        } else if (c[i] == 'x') {
            c[i] = 'w';
        } else if (c[i] == 'y') {
            c[i] = 'z';
        } else if (c[i] == 'z') {
            c[i] = 'y';
        }
    }
}

int main() {
    char message[100];

    printf("Enter an alien message: ");
    fgets(message, sizeof(message), stdin);

    convert(message);

    printf("Translated message: %s", message);

    return 0;
}