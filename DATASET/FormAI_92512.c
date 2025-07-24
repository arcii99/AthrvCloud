//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int sec) {
    int ms = 1000 * sec;
    clock_t start_time = clock();
    while (clock() < start_time + ms);
}

void translate(char* word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (word[i] == 'A') {
            printf("NORG");
        } else if (word[i] == 'B') {
            printf("PLEX");
        } else if (word[i] == 'C') {
            printf("ZORG");
        } else if (word[i] == 'D') {
            printf("REVX");
        } else if (word[i] == 'E') {
            printf("KLOZ");
        } else if (word[i] == 'F') {
            printf("VULX");
        } else if (word[i] == 'G') {
            printf("MEST");
        } else if (word[i] == 'H') {
            printf("JUKN");
        } else if (word[i] == 'I') {
            printf("THYM");
        } else if (word[i] == 'J') {
            printf("TROQ");
        } else if (word[i] == 'K') {
            printf("ZIXA");
        } else if (word[i] == 'L') {
            printf("PEXO");
        } else if (word[i] == 'M') {
            printf("YARF");
        } else if (word[i] == 'N') {
            printf("JINX");
        } else if (word[i] == 'O') {
            printf("QIXO");
        } else if (word[i] == 'P') {
            printf("POGO");
        } else if (word[i] == 'Q') {
            printf("ZOUL");
        } else if (word[i] == 'R') {
            printf("WERT");
        } else if (word[i] == 'S') {
            printf("BORT");
        } else if (word[i] == 'T') {
            printf("GLEN");
        } else if (word[i] == 'U') {
            printf("FRAX");
        } else if (word[i] == 'V') {
            printf("QUER");
        } else if (word[i] == 'W') {
            printf("OPIO");
        } else if (word[i] == 'X') {
            printf("KOPT");
        } else if (word[i] == 'Y') {
            printf("FIKE");
        } else if (word[i] == 'Z') {
            printf("ZART");
        } else {
            printf("%c", word[i]);
        }
    }
}

int main() {
    printf("ALIEN LANGUAGE TRANSLATOR\n");
    while (1) {
        printf("\nEnter a word or phrase to translate: ");
        char input[100];
        scanf("%[^\n]%*c", input);
        printf("\nTranslating...\n");
        delay(2);
        printf("\nTranslation: ");
        translate(input);
        printf("\n");
    }
    return 0;
}