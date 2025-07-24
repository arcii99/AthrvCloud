//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cyberspace(void);
void translate(char *input);

int main(void) {
    cyberspace();
    char input[100];
    printf("Enter a string in C Alien Language: ");
    fgets(input, 100, stdin);
    translate(input);
    return 0;
}

void cyberspace(void) {
    printf("\n****************************************");
    printf("\n      C ALIEN LANGUAGE TRANSLATOR");
    printf("\n****************************************\n");
    printf("\nCYBERSPACE CONNECTION ESTABLISHED...\n");
    printf("ENTERING C ALIEN LANGUAGE MATRIX...\n");
    printf("CYBERSPACE CONNECTION SECURED...\n");
    printf("BEGINNING TRANSLATION PROCEDURE...\n");
    printf("\n****************************************\n\n");
}

void translate(char *input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (input[i] == 'B') {
            printf("0");
        } else if (input[i] == 'C') {
            printf("1");
        } else if (input[i] == 'D') {
            printf("2");
        } else if (input[i] == 'F') {
            printf("3");
        } else if (input[i] == 'G') {
            printf("4");
        } else if (input[i] == 'H') {
            printf("5");
        } else if (input[i] == 'J') {
            printf("6");
        } else if (input[i] == 'K') {
            printf("7");
        } else if (input[i] == 'L') {
            printf("8");
        } else if (input[i] == 'M') {
            printf("9");
        } else if (input[i] == 'N') {
            printf("&");
        } else if (input[i] == 'P') {
            printf("$");
        } else if (input[i] == 'Q') {
            printf("#");
        } else if (input[i] == 'R') {
            printf("@");
        } else if (input[i] == 'S') {
            printf("!");
        } else if (input[i] == 'T') {
            printf("^");
        } else if (input[i] == 'V') {
            printf("*");
        } else if (input[i] == 'W') {
            printf("(");
        } else if (input[i] == 'X') {
            printf(")");
        } else if (input[i] == 'Y') {
            printf("-");
        } else if (input[i] == 'Z') {
            printf("+");
        } else {
            printf("%c", input[i]);
        }
    }
    printf("\n\nTRANSLATION COMPLETE.\n");
    printf("CYBERSPACE CONNECTION TERMINATED.\n");
}