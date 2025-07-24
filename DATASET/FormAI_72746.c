//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>

int main() {
    char input[100];
    printf("Enter text to convert to ASCII art:\n");
    scanf("%[^\n]", input);

    int asciiVal, i, j;
    for (i = 0; input[i] != '\0'; i++) {
        asciiVal = (int) input[i]; // get ASCII value of character
        printf("\t\t"); // add indentation
        for (j = 7; j >= 0; j--) {
            if ((asciiVal >> j) & 1) {
                printf("*"); // print asterisk for binary 1
            } else {
                printf(" "); // print space for binary 0
            }
        }
        printf("\n"); // move to next line for the next character
    }
    return 0;
}