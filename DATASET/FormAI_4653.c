//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUM_ROWS 5
#define NUM_COLS 5

/* Welcome to the Curious Pathfinding Algorithm!
 * This algorithm is designed to explore every possible path from the starting point to the end point. 
 * It may not be the most efficient, but it is certainly curious. 
 * Let's see how it works. */

int maze[NUM_ROWS][NUM_COLS] = {
    {1, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {1, 0, 0, 0, 1}
};

bool visited[NUM_ROWS][NUM_COLS];

/* Let's start with a helper function that checks if a given cell is a valid move.*/
bool is_valid_move(int row, int col) {
    if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && maze[row][col] && !visited[row][col]) {
        return true;
    }
    return false;
}

/* And now, the main function. */
void curious_pathfinding(int row, int col) {
    visited[row][col] = true;
    printf("Visited cell: %d,%d\n", row, col);

    /* Check for end point. */
    if (row == NUM_ROWS - 1 && col == NUM_COLS - 1) {
        printf("Hurray! We have reached the end point!\n");
        return;
    }

    /* Check all possible moves. */
    if (is_valid_move(row, col + 1)) {
        curious_pathfinding(row, col + 1);
    }
    if (is_valid_move(row + 1, col)) {
        curious_pathfinding(row + 1, col);
    }
    if (is_valid_move(row, col - 1)) {
        curious_pathfinding(row, col - 1);
    }
    if (is_valid_move(row - 1, col)) {
        curious_pathfinding(row - 1, col);
    }

    /* Backtracking. */
    printf("Backtracking from cell: %d,%d\n", row, col);
    visited[row][col] = false;
}

/* Let's test this algorithm on our maze. */
int main() {
    curious_pathfinding(0, 0);
    return 0;
}