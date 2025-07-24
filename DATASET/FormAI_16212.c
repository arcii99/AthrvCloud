//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define MAX_PLAYERS 5
#define INTRUDER 'I'
#define DEFENDER 'D'
#define VACANT '.'

typedef struct player {
    char type;
    int x;
    int y;
} player_t;

/* Function to initialize the grid */
void initializeGrid(char grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = VACANT;
        }
    }
}

/* Function to print the grid */
void printGrid(char grid[][GRID_SIZE]) {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

/* Function to randomly assign players to the grid */
void assignPlayers(player_t players[]){
    int playerCount = 0;
    while(playerCount < MAX_PLAYERS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        
        if (players[playerCount].type == INTRUDER) {
            if ((y < 2 || y > GRID_SIZE-3) && (players[playerCount-1].x != x || players[playerCount-1].y != y)) {
                players[playerCount].x = x;
                players[playerCount].y = y;
                playerCount++;
            }
        } else {
            if ((y > 2 && y < GRID_SIZE-3) && (players[playerCount-1].x != x || players[playerCount-1].y != y)) {
                players[playerCount].x = x;
                players[playerCount].y = y;
                playerCount++;
            }
        }
    }
}

/* Function to check if a player can move to a given coordinate */
int canMove(char grid[][GRID_SIZE], int x, int y) {
    if (x < 0 || x > GRID_SIZE-1 || y < 0 || y > GRID_SIZE-1) {
        return 0;
    }
    if (grid[x][y] != VACANT) {
        return 0;
    }
    return 1;
}

/* Main function */
int main() {
    srand(time(NULL));
    char grid[GRID_SIZE][GRID_SIZE];
    initializeGrid(grid);
    player_t players[MAX_PLAYERS];
    players[0].type = INTRUDER;
    for (int i = 1; i < MAX_PLAYERS; i++) {
        players[i].type = DEFENDER;
    }
    assignPlayers(players);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        grid[players[i].x][players[i].y] = players[i].type;
    }
    printGrid(grid);
    int currentPlayer = 0;
    while (1) {
        int currentX = players[currentPlayer].x;
        int currentY = players[currentPlayer].y;
        printf("\nPlayer %c, enter direction: ", players[currentPlayer].type);
        char input;
        scanf("%c", &input);
        getchar(); // fgets reads the \n from the input stream, so we need to remove it
        switch(input) {
            case 'w':
                if (canMove(grid, currentX-1, currentY)) {
                    grid[currentX][currentY] = VACANT;
                    players[currentPlayer].x--;
                    grid[currentX-1][currentY] = players[currentPlayer].type;
                }
                break;
            case 'a':
                if (canMove(grid, currentX, currentY-1)) {
                    grid[currentX][currentY] = VACANT;
                    players[currentPlayer].y--;
                    grid[currentX][currentY-1] = players[currentPlayer].type;
                }
                break;
            case 's':
                if (canMove(grid, currentX+1, currentY)) {
                    grid[currentX][currentY] = VACANT;
                    players[currentPlayer].x++;
                    grid[currentX+1][currentY] = players[currentPlayer].type;
                }
                break;
            case 'd':
                if (canMove(grid, currentX, currentY+1)) {
                    grid[currentX][currentY] = VACANT;
                    players[currentPlayer].y++;
                    grid[currentX][currentY+1] = players[currentPlayer].type;
                }
                break;
            default:
                printf("\nInvalid input\n");
        }
        printGrid(grid);
        currentPlayer++;
        if (currentPlayer == MAX_PLAYERS) {
            currentPlayer = 0;
        }
    }
    return 0;
}