//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <string.h>

// Function to convert alien language to English
void convertToEnglish(char alienLanguage[]) {
    int i;
    for(i=0; i<strlen(alienLanguage); i++) {
        switch(alienLanguage[i]) {
            case 'A': printf("a"); break;
            case 'B': printf("b"); break;
            case 'C': printf("c"); break;
            case 'D': printf("d"); break;
            case 'E': printf("e"); break;
            case 'F': printf("f"); break;
            case 'G': printf("g"); break;
            case 'H': printf("h"); break;
            case 'I': printf("i"); break;
            case 'J': printf("j"); break;
            case 'K': printf("k"); break;
            case 'L': printf("l"); break;
            case 'M': printf("m"); break;
            case 'N': printf("n"); break;
            case 'O': printf("o"); break;
            case 'P': printf("p"); break;
            case 'Q': printf("q"); break;
            case 'R': printf("r"); break;
            case 'S': printf("s"); break;
            case 'T': printf("t"); break;
            case 'U': printf("u"); break;
            case 'V': printf("v"); break;
            case 'W': printf("w"); break;
            case 'X': printf("x"); break;
            case 'Y': printf("y"); break;
            case 'Z': printf("z"); break;
            case 'a': printf("A"); break;
            case 'b': printf("B"); break;
            case 'c': printf("C"); break;
            case 'd': printf("D"); break;
            case 'e': printf("E"); break;
            case 'f': printf("F"); break;
            case 'g': printf("G"); break;
            case 'h': printf("H"); break;
            case 'i': printf("I"); break;
            case 'j': printf("J"); break;
            case 'k': printf("K"); break;
            case 'l': printf("L"); break;
            case 'm': printf("M"); break;
            case 'n': printf("N"); break;
            case 'o': printf("O"); break;
            case 'p': printf("P"); break;
            case 'q': printf("Q"); break;
            case 'r': printf("R"); break;
            case 's': printf("S"); break;
            case 't': printf("T"); break;
            case 'u': printf("U"); break;
            case 'v': printf("V"); break;
            case 'w': printf("W"); break;
            case 'x': printf("X"); break;
            case 'y': printf("Y"); break;
            case 'z': printf("Z"); break;
            default: printf("%c", alienLanguage[i]); break;
        }
    }
}

int main() {
    char alienLanguage[100];
    printf("Enter alien language: ");
    scanf("%[^\n]%*c", alienLanguage);
    convertToEnglish(alienLanguage);
    return 0;
}