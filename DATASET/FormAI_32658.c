//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: cheerful
#include <stdio.h>
#include <string.h>

void draw_char(char c) {
    int ascii = c;
    int i, j;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++) {
            if ((i == 0 && j == 2) || (i == 6 && j == 2)) {
                printf("*");
            } else if ((i == 1 || i == 5) && (j == 1 || j == 3)) {
                printf("*");
            } else if ((i == 2 || i == 4) && (j == 0 || j == 4)) {
                printf("*");
            } else if (i == 3) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("ASCII value: %d \n", ascii);
}

int main() {
    char input[50];

    printf("Enter some text: ");
    fgets(input, 50, stdin);

    printf("-------------------------------------------\n");
    printf("Your input in ASCII art:\n");

    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        draw_char(input[i]);
    }

    printf("-------------------------------------------\n");
    return 0;
}