//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

void printLetterA();
void printLetterD();
void printLetterL();
void printLetterO();
void printLetterV();
void printLetterE();

int main() {
    char input[100];
    printf("Enter a word or phrase: ");
    fgets(input, 100, stdin);

    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == 'a' || input[i] == 'A') {
            printLetterA();
        } else if(input[i] == 'd' || input[i] == 'D') {
            printLetterD();
        } else if(input[i] == 'l' || input[i] == 'L') {
            printLetterL();
        } else if(input[i] == 'o' || input[i] == 'O') {
            printLetterO();
        } else if(input[i] == 'v' || input[i] == 'V') {
            printLetterV();
        } else if(input[i] == 'e' || input[i] == 'E') {
            printLetterE();
        } else if(input[i] == ' ') {
            printf("\n\n");
        }
    }

    return 0;
}

void printLetterA() {
    printf("   A\n");
    printf("  A A\n");
    printf(" A   A\n");
    printf("AAAAAAA\n");
    printf("A     A\n");
    printf("A     A\n\n"); 
}

void printLetterD() {
    printf("DDDDDD\n");
    printf("D     D\n");
    printf("D     D\n");
    printf("D     D\n");
    printf("D     D\n");
    printf("DDDDDD\n\n"); 
}

void printLetterL() {
    printf("L\n");
    printf("L\n");
    printf("L\n");
    printf("L\n");
    printf("L\n");
    printf("LLLLLLL\n\n"); 
}

void printLetterO() {
    printf(" OOOOO\n");
    printf("O     O\n");
    printf("O     O\n");
    printf("O     O\n");
    printf("O     O\n");
    printf(" OOOOO\n\n"); 
}

void printLetterV() {
    printf("V     V\n");
    printf("V     V\n");
    printf(" V   V\n");
    printf("  V V\n");
    printf("   V\n\n"); 
}

void printLetterE() {
    printf("EEEEEE\n");
    printf("E     \n");
    printf("E     \n");
    printf("EEEE\n");
    printf("E     \n");
    printf("EEEEEE\n\n"); 
}