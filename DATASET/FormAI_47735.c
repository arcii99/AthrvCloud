//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROW_SIZE 20
#define COLUMN_SIZE 10

// Function prototypes
void generateMaze(int maze[ROW_SIZE][COLUMN_SIZE], int start[2], int end[2]);
void printMaze(int maze[ROW_SIZE][COLUMN_SIZE]);
int isValid(int row, int column);
int isDeadEnd(int maze[ROW_SIZE][COLUMN_SIZE], int row, int column, int visited[ROW_SIZE][COLUMN_SIZE]);
void createWall(int maze[ROW_SIZE][COLUMN_SIZE], int row, int column, int direction);
void connectCells(int maze[ROW_SIZE][COLUMN_SIZE], int row, int column, int direction);
void chooseRandomDirection(int directions[4]);
void shuffleDirections(int directions[4]);
int getOppositeDirection(int direction);
void carvePath(int maze[ROW_SIZE][COLUMN_SIZE], int current[2], int visited[ROW_SIZE][COLUMN_SIZE]);
void chooseRandomCell(int current[2], int end[2]);

int main()
{
    int maze[ROW_SIZE][COLUMN_SIZE] = {0};
    int start[2] = {0};
    int end[2] = {0};

    // Generate maze
    generateMaze(maze, start, end);

    // Print maze
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[ROW_SIZE][COLUMN_SIZE], int start[2], int end[2])
{
    int visited[ROW_SIZE][COLUMN_SIZE] = {0};
    int current[2] = {0};
    int direction = 0;
    int directions[4] = {1, 2, 3, 4};

    // Choose random starting and ending cells
    srand(time(NULL));
    chooseRandomCell(current, end);
    start[0] = ROW_SIZE - 1;
    start[1] = current[1];

    // Carve path through maze
    while (visited[current[0]][current[1]] == 0) {
        visited[current[0]][current[1]] = 1;
        carvePath(maze, current, visited);
        chooseRandomDirection(directions);
        shuffleDirections(directions);
        direction = 0;
        while (isDeadEnd(maze, current[0], current[1], visited) == 1 && direction < 4) {
            direction = directions[direction];
        }
        if (direction < 4) {
            connectCells(maze, current[0], current[1], direction);
            current[0] += ((direction - 1) % 2) * (2 - direction);
            current[1] += (direction % 2) * (3 - direction);    
        }
    }
}

void printMaze(int maze[ROW_SIZE][COLUMN_SIZE])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COLUMN_SIZE; j++) {
            if (maze[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int isValid(int row, int column)
{
    return row >= 0 && row < ROW_SIZE && column >= 0 && column < COLUMN_SIZE;
}

int isDeadEnd(int maze[ROW_SIZE][COLUMN_SIZE], int row, int column, int visited[ROW_SIZE][COLUMN_SIZE])
{
    int count = 0;

    if (isValid(row - 2, column) && maze[row - 1][column] == 1 && visited[row - 2][column] == 0) {
        count++;
    }
    if (isValid(row, column + 2) && maze[row][column + 1] == 1 && visited[row][column + 2] == 0) {
        count++;
    }
    if (isValid(row + 2, column) && maze[row + 1][column] == 1 && visited[row + 2][column] == 0) {
        count++;
    }
    if (isValid(row, column - 2) && maze[row][column - 1] == 1 && visited[row][column - 2] == 0) {
        count++;
    }

    return count < 2;
}

void createWall(int maze[ROW_SIZE][COLUMN_SIZE], int row, int column, int direction)
{
    if (direction == 1) {
        maze[row - 1][column] = 1;
    } else if (direction == 2) {
        maze[row][column + 1] = 1;
    } else if (direction == 3) {
        maze[row + 1][column] = 1;
    } else if (direction == 4) {
        maze[row][column - 1] = 1;
    }
}

void connectCells(int maze[ROW_SIZE][COLUMN_SIZE], int row, int column, int direction)
{
    maze[row][column] = 0;
    createWall(maze, row, column, direction);
}

void chooseRandomDirection(int directions[4])
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < 4; i++) {
        j = rand() % 4;
        temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
}

void shuffleDirections(int directions[4])
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < 4; i++) {
        j = rand() % 4;
        temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
}

int getOppositeDirection(int direction)
{
    if (direction == 1) {
        return 3;
    } else if (direction == 2) {
        return 4;
    } else if (direction == 3) {
        return 1;
    } else {
        return 2;
    }
}

void carvePath(int maze[ROW_SIZE][COLUMN_SIZE], int current[2], int visited[ROW_SIZE][COLUMN_SIZE])
{
    int direction = 0;
    int directions[4] = {1, 2, 3, 4};

    chooseRandomDirection(directions);
    shuffleDirections(directions);
    direction = 0;
    while (direction < 4) {
        if (directions[direction] == 1 && isValid(current[0] - 2, current[1]) && visited[current[0] - 2][current[1]] == 0) {
            connectCells(maze, current[0] - 1, current[1], 1);
            current[0] -= 2;
            visited[current[0]][current[1]] = 1;
            carvePath(maze, current, visited);
        } else if (directions[direction] == 2 && isValid(current[0], current[1] + 2) && visited[current[0]][current[1] + 2] == 0) {
            connectCells(maze, current[0], current[1] + 1, 2);
            current[1] += 2;
            visited[current[0]][current[1]] = 1;
            carvePath(maze, current, visited);
        } else if (directions[direction] == 3 && isValid(current[0] + 2, current[1]) && visited[current[0] + 2][current[1]] == 0) {
            connectCells(maze, current[0] + 1, current[1], 3);
            current[0] += 2;
            visited[current[0]][current[1]] = 1;
            carvePath(maze, current, visited);
        } else if (directions[direction] == 4 && isValid(current[0], current[1] - 2) && visited[current[0]][current[1] - 2] == 0) {
            connectCells(maze, current[0], current[1] - 1, 4);
            current[1] -= 2;
            visited[current[0]][current[1]] = 1;
            carvePath(maze, current, visited);
        }
        direction++;
    }
}

void chooseRandomCell(int current[2], int end[2])
{
    current[0] = 1;
    current[1] = rand() % COLUMN_SIZE;
    end[0] = ROW_SIZE - 2;
    end[1] = rand() % COLUMN_SIZE;
}