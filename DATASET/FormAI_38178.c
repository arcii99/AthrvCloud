//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: calm
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char dungeon[20][79];

void generateDungeon(int seed) {
    srand(seed);

    // Generate dungeon
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 79; col++) {
            // Randomly place walls
            if (rand() % 100 < 40) {
                dungeon[row][col] = '#';
            } else {
                dungeon[row][col] = '.';
            }
        }
    }

    // Randomly place player
    int playerRow = rand() % 19;
    int playerCol = rand() % 78;
    dungeon[playerRow][playerCol] = '@';
}

void printDungeon() {
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 79; col++) {
            printf("%c", dungeon[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int seed = time(NULL); // Use current time as seed
    generateDungeon(seed);
    printDungeon();
    return 0;
}