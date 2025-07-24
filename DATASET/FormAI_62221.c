//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>

void translate(char* sentence) {
    int i, len = strlen(sentence);
    for (i = 0; i < len; i++) {
        if (sentence[i] == 'A') {
            printf("Z");
        } else if (sentence[i] == 'B') {
            printf("Y");
        } else if (sentence[i] == 'C') {
            printf("X");
        } else if (sentence[i] == 'D') {
            printf("W");
        } else if (sentence[i] == 'E') {
            printf("V");
        } else if (sentence[i] == 'F') {
            printf("U");
        } else if (sentence[i] == 'G') {
            printf("T");
        } else if (sentence[i] == 'H') {
            printf("S");
        } else if (sentence[i] == 'I') {
            printf("R");
        } else if (sentence[i] == 'J') {
            printf("Q");
        } else if (sentence[i] == 'K') {
            printf("P");
        } else if (sentence[i] == 'L') {
            printf("O");
        } else if (sentence[i] == 'M') {
            printf("N");
        } else if (sentence[i] == 'N') {
            printf("M");
        } else if (sentence[i] == 'O') {
            printf("L");
        } else if (sentence[i] == 'P') {
            printf("K");
        } else if (sentence[i] == 'Q') {
            printf("J");
        } else if (sentence[i] == 'R') {
            printf("I");
        } else if (sentence[i] == 'S') {
            printf("H");
        } else if (sentence[i] == 'T') {
            printf("G");
        } else if (sentence[i] == 'U') {
            printf("F");
        } else if (sentence[i] == 'V') {
            printf("E");
        } else if (sentence[i] == 'W') {
            printf("D");
        } else if (sentence[i] == 'X') {
            printf("C");
        } else if (sentence[i] == 'Y') {
            printf("B");
        } else if (sentence[i] == 'Z') {
            printf("A");
        } else {
            printf("%c", sentence[i]);
        }
    }
}

int main() {
    char sentence[1000];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Enter a sentence to translate: ");
    fgets(sentence, 1000, stdin);
    printf("Translated sentence: ");
    translate(sentence);
    printf("\n");
    return 0;
}