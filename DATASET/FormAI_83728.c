//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter text to convert to ASCII art:\n");
    fgets(input, 1000, stdin);
    int length = strlen(input);

    int conversion[length][7];

    for(int i = 0; i < length; i++) {
        int ascii = (int)input[i];
        for(int j = 0; j < 7; j++) {
            conversion[i][j] = (ascii >> (6-j)) & 1;
        }
    }

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < length; j++) {
            if(conversion[j][i] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}