//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToAsciiArt(char input[]) {
    int i, j;
    int length = strlen(input);

    char *asciiArt[7];
    asciiArt[0] = "        _____ _____ _____ _____ _____ _____ _____ _____\n";
    asciiArt[1] = "       |  _  |  _  |_   _|   __|  |  |     | __  |   __|\n";
    asciiArt[2] = "       |   __|     | | | |__   |  |  |  |  |    -|__   |\n";
    asciiArt[3] = "       |__|  |__|__| |_| |_____|_____|_____|__|__|_____|\n";
    asciiArt[4] = " |||||| |||||| |||||| |||||| |||||| |||||| |||||| ||||||\n";
    asciiArt[5] = " ||=||| ||=||| ||=||| || ||| ||=||| || ||| ||=||| ||=|||\n";
    asciiArt[6] = " |||||| |||||| |||||| |||||| |||||| |||||| |||||| ||||||\n";

    for(i = 0; i < 7; i++) {
        for(j = 0; j < length; j++) {
            int asciiCode = (int)input[j];
            printf(" %s",asciiArt[i]+(asciiCode*5));
        }
        printf("\n");
    }
}

int main() {
    char input[50];

    printf("Enter a string: ");
    fgets(input, 50, stdin);
    convertToAsciiArt(input);

    return 0;
}