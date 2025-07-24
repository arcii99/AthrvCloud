//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>

void printMorseCode(char letter[]) {
    if (strcmp(letter, "A") == 0) {
        printf(".-");
    }
    else if (strcmp(letter, "B") == 0) {
        printf("-...");
    }
    else if (strcmp(letter, "C") == 0) {
        printf("-.-.");
    }
    else if (strcmp(letter, "D") == 0) {
        printf("-..");
    }
    else if (strcmp(letter, "E") == 0) {
        printf(".");
    }
    else if (strcmp(letter, "F") == 0) {
        printf("..-.");
    }
    else if (strcmp(letter, "G") == 0) {
        printf("--.");
    }
    else if (strcmp(letter, "H") == 0) {
        printf("....");
    }
    else if (strcmp(letter, "I") == 0) {
        printf("..");
    }
    else if (strcmp(letter, "J") == 0) {
        printf(".---");
    }
    else if (strcmp(letter, "K") == 0) {
        printf("-.-");
    }
    else if (strcmp(letter, "L") == 0) {
        printf(".-..");
    }
    else if (strcmp(letter, "M") == 0) {
        printf("--");
    }
    else if (strcmp(letter, "N") == 0) {
        printf("-.");
    }
    else if (strcmp(letter, "O") == 0) {
        printf("---");
    }
    else if (strcmp(letter, "P") == 0) {
        printf(".--.");
    }
    else if (strcmp(letter, "Q") == 0) {
        printf("--.-");
    }
    else if (strcmp(letter, "R") == 0) {
        printf(".-.");
    }
    else if (strcmp(letter, "S") == 0) {
        printf("...");
    }
    else if (strcmp(letter, "T") == 0) {
        printf("-");
    }
    else if (strcmp(letter, "U") == 0) {
        printf("..-");
    }
    else if (strcmp(letter, "V") == 0) {
        printf("...-");
    }
    else if (strcmp(letter, "W") == 0) {
        printf(".--");
    }
    else if (strcmp(letter, "X") == 0) {
        printf("-..-");
    }
    else if (strcmp(letter, "Y") == 0) {
        printf("-.--");
    }
    else if (strcmp(letter, "Z") == 0) {
        printf("--..");
    }
    else if (strcmp(letter, "0") == 0) {
        printf("-----");
    }
    else if (strcmp(letter, "1") == 0) {
        printf(".----");
    }
    else if (strcmp(letter, "2") == 0) {
        printf("..---");
    }
    else if (strcmp(letter, "3") == 0) {
        printf("...--");
    }
    else if (strcmp(letter, "4") == 0) {
        printf("....-");
    }
    else if (strcmp(letter, "5") == 0) {
        printf(".....");
    }
    else if (strcmp(letter, "6") == 0) {
        printf("-....");
    }
    else if (strcmp(letter, "7") == 0) {
        printf("--...");
    }
    else if (strcmp(letter, "8") == 0) {
        printf("---..");
    }
    else if (strcmp(letter, "9") == 0) {
        printf("----.");
    }
    else {
        printf("%s", letter);
    }
}

int main() {
    char text[100];
    printf("Enter the text to be converted to Morse code: ");
    fgets(text, 100, stdin);
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        printMorseCode(&text[i]);
        printf(" ");
    }
    return 0;
}