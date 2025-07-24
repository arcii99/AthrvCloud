//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    printf("\n\n");

    int longest = 0;
    for (int i = 0; i < sizeof(input); i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        int ascii_value = input[i];
        if (ascii_value > longest) {
            longest = ascii_value;
        }
        for (int j = 0; j < ascii_value; j++) {
            printf("*");
        }
    }
    printf("\n\n");

    for (int i = 0; i < longest; i++) {
        for (int j = 0; j < sizeof(input); j++) {
            if (input[j] != '\n') {
                int ascii_value = input[j];
                if (ascii_value <= i) {
                    printf("   ");
                } else {
                    printf(" * ");
                }
            }
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}