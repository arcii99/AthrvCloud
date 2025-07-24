//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <string.h>

void convert_char_to_morse(char c);

int main() {
    char input[100];
    int i;

    printf("Enter a string of characters: ");
    fgets(input, sizeof(input), stdin);

    for (i = 0; i < strlen(input); i++) {
        convert_char_to_morse(input[i]);
    }

    return 0;
}

void convert_char_to_morse(char c) {
    if (c == 'a') {
        printf(".- ");
    } else if (c == 'b') {
        printf("-... ");
    } else if (c == 'c') {
        printf("-.-. ");
    } else if (c == 'd') {
        printf("-.. ");
    } else if (c == 'e') {
        printf(". ");
    } else if (c == 'f') {
        printf("..-. ");
    } else if (c == 'g') {
        printf("--. ");
    } else if (c == 'h') {
        printf(".... ");
    } else if (c == 'i') {
        printf(".. ");
    } else if (c == 'j') {
        printf(".--- ");
    } else if (c == 'k') {
        printf("-.- ");
    } else if (c == 'l') {
        printf(".-.. ");
    } else if (c == 'm') {
        printf("-- ");
    } else if (c == 'n') {
        printf("-. ");
    } else if (c == 'o') {
        printf("--- ");
    } else if (c == 'p') {
        printf(".--. ");
    } else if (c == 'q') {
        printf("--.- ");
    } else if (c == 'r') {
        printf(".-. ");
    } else if (c == 's') {
        printf("... ");
    } else if (c == 't') {
        printf("- ");
    } else if (c == 'u') {
        printf("..- ");
    } else if (c == 'v') {
        printf("...- ");
    } else if (c == 'w') {
        printf(".-- ");
    } else if (c == 'x') {
        printf("-..- ");
    } else if (c == 'y') {
        printf("-.-- ");
    } else if (c == 'z') {
        printf("--.. ");
    } else {
        printf("%c ", c);
    }
}