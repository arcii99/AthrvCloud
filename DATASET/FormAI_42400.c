//FormAI DATASET v1.0 Category: QR code reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHeader() {
    printf("\n                __                \n");
    printf(" /\\  /\\  |__)  /  \\  |\\ |  |  |  \n");
    printf("/~~\\/__\\ |     \\__/  | \\|  \\__/  v1.0\n\n");
}

void printInstructions() {
    printf("Please scan the QR code.\n");
}

void error(char *message) {
    printf("\nError: %s. Please try again.\n", message);
}

int main() {
    char code[101];
    char expected[] = "CEA899D09998D1ED309BFA8CBE246A31";
    printHeader();
    printInstructions();
    scanf("%100s", code);

    if (strlen(code) != 32) {
        error("Invalid QR code length");
        return 1;
    }

    if (strcmp(code, expected) != 0) {
        error("QR code does not match");
        return 1;
    }

    printf("Congratulations! You have successfully read the QR code.\n");
    return 0;
}