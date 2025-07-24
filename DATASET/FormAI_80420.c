//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
    char cCat[100];
    int i, j;
    printf("Enter a sentence in C Cat language: ");
    fgets(cCat, 100, stdin);
    
    for(i = 0; i < strlen(cCat); i++) {
        if(cCat[i] == 'M') {
            printf("Meow ");
        } else if(cCat[i] == 'P') {
            printf("Purr ");
        } else if(cCat[i] == 'H') {
            printf("Hiss ");
        } else if(cCat[i] == 'T') {
            printf("Treat ");
        } else if(cCat[i] == 'N') {
            printf("Nap ");
        } else if(cCat[i] == 'L') {
            printf("Lick ");
        } else if(cCat[i] == 'C') {
            printf("Crinkle ");
        } else if(cCat[i] == 'S') {
            printf("Scratch ");
        } else if(cCat[i] == 'B') {
            printf("Bird ");
        } else if(cCat[i] == 'F') {
            printf("Fish ");
        } else if(cCat[i] == 'D') {
            printf("Doze ");
        } else if(cCat[i] == 'G') {
            printf("Groom ");
        } else if(cCat[i] == 'Y') {
            printf("Yawn ");
        } else if(cCat[i] == 'R') {
            printf("Roll ");
        } else if(cCat[i] == 'A') {
            printf("Aloof ");
        } else if(cCat[i] == 'E') {
            printf("Explore ");
        } else if(cCat[i] == 'V') {
            printf("Vex ");
        } else if(cCat[i] == 'W') {
            printf("Warm ");
        } else if(cCat[i] == 'Z') {
            printf("Zzz ");
        } else {
            printf("%c", cCat[i]);
            if(cCat[i] == ' ' && cCat[i + 1] == 'M' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Meow ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'P' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Purr ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'H' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Hiss ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'T' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Treat ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'N' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Nap ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'L' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Lick ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'C' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Crinkle ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'S' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Scratch ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'B' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Bird ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'F' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Fish ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'D' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Doze ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'G' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Groom ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'Y' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Yawn ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'R' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Roll ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'A' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Aloof ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'E' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Explore ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'V' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Vex ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'W' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Warm ");
                i += 2;
            } else if(cCat[i] == ' ' && cCat[i + 1] == 'Z' && (cCat[i + 2] == ' ' || cCat[i + 2] == '\n')) {
                printf("Zzz ");
                i += 2;
            }
        }
    }
    return 0;
}