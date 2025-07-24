//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBorder(int width);

int main() {
    srand(time(0));

    int width = 20;
    char house[10][20] = {
        "###################",
        "#                 #",
        "#                 #",
        "#       &&        #",
        "#      &&&&       #",
        "#      &&&&       #",
        "#      &&&&       #",
        "#       &&        #",
        "#                 #",
        "###################"
    };

    int ghostRow = rand() % 8 + 1;
    int ghostCol = rand() % 18 + 1;

    house[ghostRow][ghostCol] = 'G';

    printBorder(width);

    for (int i = 0; i < 10; i++) {
        printf("%s\n", house[i]);
    }

    printBorder(width);
}

void printBorder(int width) {
    for (int i = 0; i < width; i++) {
        printf("#");
    }
    printf("\n");
}