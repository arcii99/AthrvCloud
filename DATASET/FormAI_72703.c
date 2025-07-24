//FormAI DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define MAX_ENTRIES 30

typedef struct {
    int row;
    int column;
} Entry;

int main(void) {

    int map[GRID_SIZE][GRID_SIZE] = {0}; // initialize all to 0
    Entry entries[MAX_ENTRIES];

    srand(time(NULL)); // seed random number generator with current time

    // randomly place entries on the map
    for (int i = 0; i < MAX_ENTRIES; i++) {
        int row = rand() % GRID_SIZE;
        int column = rand() % GRID_SIZE;

        // check if entry already exists at this location
        if (map[row][column] == 0) {
            map[row][column] = i + 1; // store entry number in map
            entries[i].row = row;
            entries[i].column = column;
        } else {
            i--; // try again
        }
    }

    // perform data analysis
    int total_entries = 0;
    int total_robots = 0;
    int total_weapons = 0;
    int total_food = 0;

    for (int i = 0; i < MAX_ENTRIES; i++) {
        int row = entries[i].row;
        int column = entries[i].column;

        int value = map[row][column];
        total_entries++;

        switch (value) {
            case 1: // robot
                total_robots++;
                break;
            case 2: // weapon
                total_weapons++;
                break;
            case 3: // food
                total_food++;
                break;
        }
    }

    // print results
    printf("Data analysis results:\n");
    printf("Total entries: %d\n", total_entries);
    printf("Total robots: %d\n", total_robots);
    printf("Total weapons: %d\n", total_weapons);
    printf("Total food: %d\n", total_food);

    return 0;
}