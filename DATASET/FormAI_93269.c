//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
// Romeo and Juliet Pathfinding Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 8
#define COL 8

// Function to check if a given cell (row, col) is a valid spot to visit
int isValid(int row, int col, int grid[][COL], int visited[][COL])
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (grid[row][col] == 1 && !visited[row][col]);
}

// Function to solve Romeo and Juliet pathfinding problem
int RomeoAndJuliet(int grid[][COL], int start_row, int start_col, int end_row, int end_col)
{
    if (!grid[start_row][start_col] || !grid[end_row][end_col])
    {
        printf("Alas, my dear Romeo and Juliet, one of you is not present on the board!\n");
        return 0; // one of the characters is not present at start or end location
    }

    if (grid[start_row][start_col] == 0 || grid[end_row][end_col] == 0)
    {
        printf("Oh my! One of the characters is trapped in a forbidden cell!\n");
        return 0; // one of the characters is trapped in a forbidden cell
    }

    if ((start_row == end_row) && (start_col == end_col))
    {
        printf("Hark! Romeo and Juliet have finally reunited!\n");
        return 1; // the characters have already met at the same cell
    }

    int visited[ROW][COL];
    memset(visited, 0, sizeof visited);

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    visited[start_row][start_col] = 1;

    int queue[ROW * COL];
    int head = 0, tail = 0;
    queue[tail++] = start_row * COL + start_col;

    int steps = 0;
    while (head < tail)
    {
        int cur_size = tail - head;
        while (cur_size--)
        {
            int cur = queue[head++];
            int row = cur / COL;
            int col = cur % COL;

            if (row == end_row && col == end_col)
            {
                printf("At last! Romeo and Juliet have met after %d steps!\n", steps);
                return 1; // Romeo and Juliet have met!
            }

            for (int i = 0; i < 4; ++i)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                if (isValid(newRow, newCol, grid, visited))
                {
                    visited[newRow][newCol] = 1;
                    queue[tail++] = newRow * COL + newCol;
                }
            } 
        }
        steps++;
    }
    printf("My poor Romeo and Juliet have been separated by the boundaries of this board!\n");
    return 0; // Romeo and Juliet can't meet within the boundaries of the board
}

int main(void)
{
    // initialize start and end coordinates
    int start_row = 0, start_col = 0, end_row = 0, end_col = 0;

    // initialize board
    int board[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
    };

    int result = RomeoAndJuliet(board, start_row, start_col, end_row, end_col);
    printf("Result: %d\n", result);

    return 0;
}