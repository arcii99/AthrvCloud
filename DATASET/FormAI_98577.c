//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: calm
#include<stdio.h>

//Defining constants for the maximum number of rows and columns.
#define ROWS 10
#define COLS 10

//Defining the different directions for the RC car
enum direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

//Function to print the grid for the simulation
void print_grid(char grid[][COLS], int rows) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<COLS;j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

//Function to move the RC car based on the direction
void move_car(int *x, int *y, enum direction dir) {
    switch(dir) {
        case NORTH:
            if(*x > 0) {
                (*x)--;
            }
            break;
        case SOUTH:
            if(*x < ROWS-1) {
                (*x)++;
            }
            break;
        case EAST:
            if(*y < COLS-1) {
                (*y)++;
            }
            break;
        case WEST:
            if(*y > 0) {
                (*y)--;
            }
            break;
    }
}

int main() {
    char grid[ROWS][COLS];

    //Initializing the grid with blank spaces
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            grid[i][j] = ' ';
        }
    }

    //Setting the initial position of the RC car
    int x = 0;
    int y = 0;
    grid[x][y] = 'C';

    //Starting the simulation
    printf("Welcome to the RC car simulator\n");
    printf("Use the following keys to control the RC car:\n");
    printf("N: Move car north\n");
    printf("S: Move car south\n");
    printf("E: Move car east\n");
    printf("W: Move car west\n");
    printf("Q: Quit simulation\n");

    //Looping until the user enters the quit command
    while(1) {
        print_grid(grid, ROWS);
        char command = getchar();

        //Clearing the input buffer
        while(getchar() != '\n');

        //Checking the user command and moving the RC car accordingly
        switch(command) {
            case 'N':
                move_car(&x, &y, NORTH);
                grid[x][y] = 'C';
                break;
            case 'S':
                move_car(&x, &y, SOUTH);
                grid[x][y] = 'C';
                break;
            case 'E':
                move_car(&x, &y, EAST);
                grid[x][y] = 'C';
                break;
            case 'W':
                move_car(&x, &y, WEST);
                grid[x][y] = 'C';
                break;
            case 'Q':
                return 0;
            default:
                printf("Invalid command\n");
                break;
        }
    }
}