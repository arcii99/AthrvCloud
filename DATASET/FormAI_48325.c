//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int i, j;

    // Create a 2D array to store the ASCII art
    char art[10][44] = {
        "            _..----.._",
        "         .'  .--.    /-'" ,
        "        //  /    \\_ //",
        "       | | |  _     ||",
        "       |_| |_|\\_\\___//",
        "        \\           /",
        "         `--....___-'",
        "    _____       _____",
        "       /_______\\",
        "      (   o   o   )"
    };

    // Print the ASCII art
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 44; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    return 0;
}