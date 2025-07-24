//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// function to convert ASCII value to character
void ascii_to_char(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

// function to generate ASCII art
void ascii_art(char input[]) {
    int size = strlen(input);
    int art[size];

    for (int i = 0; i < size; i++) {
        if (input[i] == 'A' || input[i] == 'a') {
            art[i] = 65;
        } else if (input[i] == 'B' || input[i] == 'b') {
            art[i] = 66;
        } else if (input[i] == 'C' || input[i] == 'c') {
            art[i] = 67;
        } else if (input[i] == 'D' || input[i] == 'd') {
            art[i] = 68;
        } else if (input[i] == 'E' || input[i] == 'e') {
            art[i] = 69;
        } else if (input[i] == 'F' || input[i] == 'f') {
            art[i] = 70;
        } else if (input[i] == 'G' || input[i] == 'g') {
            art[i] = 71;
        } else if (input[i] == 'H' || input[i] == 'h') {
            art[i] = 72;
        } else if (input[i] == 'I' || input[i] == 'i') {
            art[i] = 73;
        } else if (input[i] == 'J' || input[i] == 'j') {
            art[i] = 74;
        } else if (input[i] == 'K' || input[i] == 'k') {
            art[i] = 75;
        } else if (input[i] == 'L' || input[i] == 'l') {
            art[i] = 76;
        } else if (input[i] == 'M' || input[i] == 'm') {
            art[i] = 77;
        } else if (input[i] == 'N' || input[i] == 'n') {
            art[i] = 78;
        } else if (input[i] == 'O' || input[i] == 'o') {
            art[i] = 79;
        } else if (input[i] == 'P' || input[i] == 'p') {
            art[i] = 80;
        } else if (input[i] == 'Q' || input[i] == 'q') {
            art[i] = 81;
        } else if (input[i] == 'R' || input[i] == 'r') {
            art[i] = 82;
        } else if (input[i] == 'S' || input[i] == 's') {
            art[i] = 83;
        } else if (input[i] == 'T' || input[i] == 't') {
            art[i] = 84;
        } else if (input[i] == 'U' || input[i] == 'u') {
            art[i] = 85;
        } else if (input[i] == 'V' || input[i] == 'v') {
            art[i] = 86;
        } else if (input[i] == 'W' || input[i] == 'w') {
            art[i] = 87;
        } else if (input[i] == 'X' || input[i] == 'x') {
            art[i] = 88;
        } else if (input[i] == 'Y' || input[i] == 'y') {
            art[i] = 89;
        } else if (input[i] == 'Z' || input[i] == 'z') {
            art[i] = 90;
        } else {
            art[i] = 32;
        }
    }

    ascii_to_char(art, size);
}

int main() {
    char input[100];

    printf("Enter text: ");
    fgets(input, 100, stdin);

    ascii_art(input);

    return 0;
}