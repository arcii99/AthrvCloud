//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
    char alien_language[100];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a word in the alien language:\n");
    scanf("%s", alien_language);
    int len = strlen(alien_language);
    printf("Translation:\n");
    for(int i=0; i<len; i++) {
        if(alien_language[i]=='A') {
            printf("D");
        }
        else if(alien_language[i]=='B') {
            printf("F");
        }
        else if(alien_language[i]=='C') {
            printf("G");
        }
        else if(alien_language[i]=='D') {
            printf("H");
        }
        else if(alien_language[i]=='E') {
            printf("J");
        }
        else if(alien_language[i]=='F') {
            printf("K");
        }
        else if(alien_language[i]=='G') {
            printf("L");
        }
        else if(alien_language[i]=='H') {
            printf("M");
        }
        else if(alien_language[i]=='I') {
            printf("N");
        }
        else if(alien_language[i]=='J') {
            printf("P");
        }
        else if(alien_language[i]=='K') {
            printf("Q");
        }
        else if(alien_language[i]=='L') {
            printf("R");
        }
        else if(alien_language[i]=='M') {
            printf("S");
        }
        else if(alien_language[i]=='N') {
            printf("T");
        }
        else if(alien_language[i]=='O') {
            printf("V");
        }
        else if(alien_language[i]=='P') {
            printf("W");
        }
        else if(alien_language[i]=='Q') {
            printf("X");
        }
        else if(alien_language[i]=='R') {
            printf("Y");
        }
        else if(alien_language[i]=='S') {
            printf("Z");
        }
        else if(alien_language[i]=='T') {
            printf("A");
        }
        else if(alien_language[i]=='U') {
            printf("E");
        }
        else if(alien_language[i]=='V') {
            printf("B");
        }
        else if(alien_language[i]=='W') {
            printf("C");
        }
        else if(alien_language[i]=='X') {
            printf("I");
        }
        else if(alien_language[i]=='Y') {
            printf("O");
        }
        else if(alien_language[i]=='Z') {
            printf("U");
        }
        else {
            printf("%c", alien_language[i]);
        }
    }
    printf("\n");
    return 0;
}