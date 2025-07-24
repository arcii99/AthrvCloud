//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function prototypes
void initializeMaze(char maze[][COLS]);
void printMaze(char maze[][COLS]);
void calculateRoute(char maze[][COLS], int startRow, int startCol, int numOfPlayers);

int main() {
    char maze[ROWS][COLS];
    int startRow, startCol, numOfPlayers;
    
    // Initialize maze
    initializeMaze(maze);
    
    // Prompt user for starting point
    printf("Enter starting row and column separated by a space: ");
    scanf("%d %d", &startRow, &startCol);
    
    // Prompt user for number of players
    printf("Enter number of players: ");
    scanf("%d", &numOfPlayers);
    
    // Calculate route for each player
    calculateRoute(maze, startRow, startCol, numOfPlayers);
    
    return 0;
}

// Initializes maze with random obstacles and endpoint
void initializeMaze(char maze[][COLS]) {
    int i, j;
    srand(time(NULL));
    
    // Fill maze with empty spaces
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = ' ';
        }
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Create random obstacles
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS-1 || j == COLS-1 || rand() % 5 == 0) {
                maze[i][j] = '#';
            }
        }
    }
    
    // Add endpoint at random location
    int endpointRow = rand() % ROWS;
    int endpointCol = rand() % COLS;
    maze[endpointRow][endpointCol] = '$';
}

// Prints the maze
void printMaze(char maze[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Calculates the optimal route for each player
void calculateRoute(char maze[][COLS], int startRow, int startCol, int numOfPlayers) {
    int player, i, j;
    int distances[ROWS][COLS];
    
    // Initialize distances array with large values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            distances[i][j] = 1000000;
        }
    }
    
    // Set distance to starting point to 0
    distances[startRow][startCol] = 0;
    
    // Calculate distance to endpoint using Dijkstra's algorithm
    for (i = 0; i < ROWS*COLS; i++) {
        int minDistance = 1000000;
        int minRow, minCol;
        for (j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                if (distances[j][k] < minDistance && maze[j][k] != '#' && distances[j][k] != -1) {
                    minDistance = distances[j][k];
                    minRow = j;
                    minCol = k;
                }
            }
        }
        
        // Update distances of neighboring cells
        if (minDistance == 1000000) break;
        if (maze[minRow][minCol] == '$') break;
        if (numOfPlayers == 1 || (numOfPlayers > 1 && i % numOfPlayers == 0)) maze[minRow][minCol] = '*';
        
        if (minRow > 0 && distances[minRow-1][minCol] > minDistance + 1 && maze[minRow-1][minCol] != '#') {
            distances[minRow-1][minCol] = minDistance + 1;
        }
        if (minRow < ROWS-1 && distances[minRow+1][minCol] > minDistance + 1 && maze[minRow+1][minCol] != '#') {
            distances[minRow+1][minCol] = minDistance + 1;
        }
        if (minCol > 0 && distances[minRow][minCol-1] > minDistance + 1 && maze[minRow][minCol-1] != '#') {
            distances[minRow][minCol-1] = minDistance + 1;
        }
        if (minCol < COLS-1 && distances[minRow][minCol+1] > minDistance + 1 && maze[minRow][minCol+1] != '#') {
            distances[minRow][minCol+1] = minDistance + 1;
        }
    }
    
    // Print maze with optimal routes from all starting points
    for (player = 0; player < numOfPlayers; player++) {
        printf("Route for player %d:\n", player+1);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (distances[i][j] == 1000000) distances[i][j] = -1;
                if (i == startRow && j == startCol + player) printf("%c ", 'A'+player);
                else if (maze[i][j] == '*') printf("%c ", 'A'+player);
                else if (maze[i][j] == '#') printf("# ");
                else if (distances[i][j] == -1) printf(". ");
                else printf("%d ", distances[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}