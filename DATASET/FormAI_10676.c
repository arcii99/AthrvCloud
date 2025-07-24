//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char inputString[1000];

    printf("Enter some text to convert to ASCII art:\n");
    scanf("%[^\n]", inputString);

    // Step 1: Print top border
    for (int i = 0; i < strlen(inputString)+4; i++) {
        printf("*");
    }
    printf("\n");

    // Step 2: Print ASCII art
    printf("*  ");
    for (int i = 0; i < strlen(inputString); i++) {
        printf("%c  ", inputString[i]);
    }
    printf("*\n");

    // Step 3: Print bottom border
    for (int i = 0; i < strlen(inputString)+4; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}