//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Define world size */
#define WIDTH 10
#define HEIGHT 10

/* Define living cells coords */
int START_LIVING[] = {0, 1, 1, 2, 2, 0, 4, 5, 5, 6, 6, 4, 4, 6, 0, 2, 5};

/* Function to print the world */
void print_world(int world[][WIDTH])
{
    printf("\n");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(world[i][j] == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

/* Function to calculate the next generation */
void calculate_next(int world[][WIDTH])
{
    int new_world[HEIGHT][WIDTH] = {0};
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            /* Count number of living neighbors */
            int living = 0;
            for(int k = -1; k < 2; k++) {
                for(int l = -1; l < 2; l++) {
                    if((k != 0 || l != 0) && i+k >= 0 && i+k < HEIGHT && j+l >= 0 && j+l < WIDTH) {
                        living += world[i+k][j+l];
                    }
                }
            }
            /* Determine new state */
            if(world[i][j] == 1 && (living < 2 || living > 3)) {
                new_world[i][j] = 0;
            } else if(world[i][j] == 0 && living == 3) {
                new_world[i][j] = 1;
            } else {
                new_world[i][j] = world[i][j];
            }
        }
    }
    /* Update world */
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            world[i][j] = new_world[i][j];
        }
    }
}

/* Function to initialize the world */
void initialize_world(int world[][WIDTH])
{
    /* Set all cells to dead */
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            world[i][j] = 0;
        }
    }
    /* Set living cells */
    for(int i = 0; i < sizeof(START_LIVING)/sizeof(int); i+=2) {
        world[START_LIVING[i]][START_LIVING[i+1]] = 1;
    }
}

int main(void)
{
    int world[HEIGHT][WIDTH];
    initialize_world(world);
    for(int i = 0; i < 10; i++) {
        print_world(world);
        calculate_next(world);
        usleep(100000);
    }
    printf("Game of Life ended with a bang! Bye bye!\n");
    return 0;
}