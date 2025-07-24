//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateGalaxy(int grid[][20], int size);
void printMap(int grid[][20], int size);

int main() {
    int galaxy[20][20] = {0}; 
    srand(time(NULL)); // random seed
    generateGalaxy(galaxy, 20); // generate a 20 by 20 galaxy
    printMap(galaxy, 20);
    return 0;
}

void generateGalaxy(int grid[][20], int size) {
    int starCount = rand() % (size*size/4) + size*size/4; // calculate the number of stars to place randomly
    int x, y;
    for (int i = 0; i < starCount; i++) {
        // randomly place stars in the galaxy
        do {
            x = rand() % size;
            y = rand() % size;
        } while (grid[x][y] == 1); // make sure the cell is empty
        grid[x][y] = 1; // place a star
    }
}

void printMap(int grid[][20], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                printf("*"); // print a star
            }
            else {
                printf("."); // print empty space
            }
        }
        printf("\n"); // new line for each row
    }
}