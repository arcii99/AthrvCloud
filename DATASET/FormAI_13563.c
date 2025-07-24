//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

void alienLanguageTranslator(char inputString[]) {
    char outputString[1000];
    int length = strlen(inputString);
    for (int i = 0; i < length; i++) {
        if (inputString[i] == 'A' || inputString[i] == 'a') {
            strcat(outputString, "E");
        } else if (inputString[i] == 'B' || inputString[i] == 'b') {
            strcat(outputString, "O");
        } else if (inputString[i] == 'C' || inputString[i] == 'c') {
            strcat(outputString, "U");
        } else if (inputString[i] == 'D' || inputString[i] == 'd') {
            strcat(outputString, "I");
        } else if (inputString[i] == 'E' || inputString[i] == 'e') {
            strcat(outputString, "A");
        } else if (inputString[i] == 'F' || inputString[i] == 'f') {
            strcat(outputString, "Y");
        } else if (inputString[i] == 'G' || inputString[i] == 'g') {
            strcat(outputString, "S");
        } else if (inputString[i] == 'H' || inputString[i] == 'h') {
            strcat(outputString, "R");
        } else if (inputString[i] == 'I' || inputString[i] == 'i') {
            strcat(outputString, "D");
        } else if (inputString[i] == 'J' || inputString[i] == 'j') {
            strcat(outputString, "K");
        } else if (inputString[i] == 'K' || inputString[i] == 'k') {
            strcat(outputString, "M");
        } else if (inputString[i] == 'L' || inputString[i] == 'l') {
            strcat(outputString, "F");
        } else if (inputString[i] == 'M' || inputString[i] == 'm') {
            strcat(outputString, "C");
        } else if (inputString[i] == 'N' || inputString[i] == 'n') {
            strcat(outputString, "W");
        } else if (inputString[i] == 'O' || inputString[i] == 'o') {
            strcat(outputString, "B");
        } else if (inputString[i] == 'P' || inputString[i] == 'p') {
            strcat(outputString, "Z");
        } else if (inputString[i] == 'Q' || inputString[i] == 'q') {
            strcat(outputString, "X");
        } else if (inputString[i] == 'R' || inputString[i] == 'r') {
            strcat(outputString, "G");
        } else if (inputString[i] == 'S' || inputString[i] == 's') {
            strcat(outputString, "V");
        } else if (inputString[i] == 'T' || inputString[i] == 't') {
            strcat(outputString, "N");
        } else if (inputString[i] == 'U' || inputString[i] == 'u') {
            strcat(outputString, "H");
        } else if (inputString[i] == 'V' || inputString[i] == 'v') {
            strcat(outputString, "J");
        } else if (inputString[i] == 'W' || inputString[i] == 'w') {
            strcat(outputString, "Q");
        } else if (inputString[i] == 'X' || inputString[i] == 'x') {
            strcat(outputString, "P");
        } else if (inputString[i] == 'Y' || inputString[i] == 'y') {
            strcat(outputString, "T");
        } else if (inputString[i] == 'Z' || inputString[i] == 'z') {
            strcat(outputString, "L");
        } else {
            strcat(outputString, "#");
        }
    }
    printf("Alien Language Translation: %s", outputString);
}

int main() {
    char inputString[1000];
    printf("Enter the string to translate in Alien Language: ");
    fgets(inputString, 1000, stdin);
    alienLanguageTranslator(inputString);
    return 0;
}