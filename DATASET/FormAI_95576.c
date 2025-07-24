//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include <stdio.h>
#include <stdbool.h>

#define ROW 22
#define COL 60

char grid[ROW][COL] = {
    "************************************************************",
    "*S                          *                               *",
    "*************  ***********************  *******  **********",
    "*            *  *                     *  *     *  *          *",
    "*********  * **  ******************* ** * ** *  ***********",
    "*       *  *  *  *                 *  *  *  * *            *",
    "*  ***  * *** ** *  *************  ** *** ** * ***********",
    "*  *G*  *     *  *  *           *  *  *    *  *           *",
    "****   ******** ** *********** ** ** * ** ** *********** *",
    "*      *      *  * *         * *  *  * * * * *           * *",
    "*  ****  ****** ** *  ******* ** ** * * * ** *********** *",
    "*  *  *      *    *       * *  *  * * * * *           * * *",
    "*  *  ********* ** ********* ** ** * * * ** *********** * *",
    "*  *           *  *         * *  *  * * * *             * *",
    "*  ****  ***** ** * ******** ** ** * * * ** *********** *",
    "*     *  *     *  * *       * *  *  * * * *             * *",
    "****** ** ******* ** ***** ** ** * ** * ** *********** * *",
    "*           *     * *     * *  *  * * * * *             * *",
    "*********** ** ***** * *** ** ** ** * * ** * *********** *",
    "*           *       *   * * *     * *    * *             *",
    "************************************************************"
};

typedef struct Node {
    int row, col;
} Node;

Node start = {1, 1};    // Starting position
Node end = {7, 3};      // Goal position

Node dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};   // Possible directions
char dirC[4] = {'D', 'U', 'R', 'L'};     // D -> Down, U -> Up, R -> Right, L -> Left

int distance[ROW][COL] = {0};   // To store distance of each node from the start position

int queue[ROW * COL];   // Queue for Breadth First Search
int front = 0, rear = 0;

// Function to check if a node is within the bounds of the grid
bool isWithinBounds(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

// Function to get the minimum distance node from the queue
int getMinDistanceNode() {
    int minDistance = distance[queue[front] / COL][queue[front] % COL];
    int minDistanceNode = queue[front];
    for (int i = front; i < rear; i++) {
        int r = queue[i] / COL;
        int c = queue[i] % COL;
        if (distance[r][c] < minDistance) {
            minDistance = distance[r][c];
            minDistanceNode = queue[i];
        }
    }
    return minDistanceNode;
}

// Function to perform Breadth First Search
void bfs() {
    queue[rear++] = start.row * COL + start.col;
    distance[start.row][start.col] = 0;

    while (front < rear) {
        int currNode = getMinDistanceNode();
        front++;

        int currRow = currNode / COL;
        int currCol = currNode % COL;

        if (currRow == end.row && currCol == end.col) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dir[i].row;
            int newCol = currCol + dir[i].col;
            if (isWithinBounds(newRow, newCol) && grid[newRow][newCol] != '*' && distance[newRow][newCol] == -1) {
                queue[rear++] = newRow * COL + newCol;
                distance[newRow][newCol] = distance[currRow][currCol] + 1;
            }
        }
    }
}

// Function to print the path from start to end
void printPath() {
    int currRow = end.row;
    int currCol = end.col;
    while (currRow != start.row || currCol != start.col) {
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dir[i].row;
            int newCol = currCol + dir[i].col;
            if (isWithinBounds(newRow, newCol) && grid[newRow][newCol] != '*' && distance[newRow][newCol] == distance[currRow][currCol] - 1) {
                currRow = newRow;
                currCol = newCol;
                printf("%c", dirC[i]);
                break;
            }
        }
    }
}

int main() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j] == '*') {
                distance[i][j] = -2;
            } else {
                distance[i][j] = -1;
            }
        }
    }

    bfs();

    printf("The shortest path from S to G: ");
    printPath();
    printf("\n");

    return 0;
}