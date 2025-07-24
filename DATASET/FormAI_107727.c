//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>

/* define the dimensions of the ASCII art */
#define ROWS 10
#define COLS 40

/* function to print the ASCII art */
void printArt(char art[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    /* create the ASCII art */
    char happyArt[ROWS][COLS] = {
        "       *****           *****        \n",
        "    ***     ***     ***     ***     \n",
        "  **           ** **           **   \n",
        " **              *              ** \n",
        "**     _____ ____ _____    ___  **\n",
        "**    |  ___|  _ \\_   _|  / _ \\ **\n",
        "**    | |_  | |_) || |   | | | |**\n",
        " **   |  _| |  _ < | |   | |_| | \n",
        "  **  |_|   |_| \\_\\|_|    \\___/  \n",
        "    ***                         ***\n"
    };

    /* print the happy ASCII art */
    printArt(happyArt);

    return 0;
}