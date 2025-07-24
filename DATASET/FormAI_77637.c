//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define ROW 7
#define COL 8

typedef struct {
    int row;
    int col;
    int isVisited;
} Cell;

int queue[ROW * COL];
int front = -1, rear = -1;

void Enqueue(int pos) {
    if (rear == ROW * COL - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = pos;
}

int Dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int pos = queue[front];
    front++;
    return pos;
}

int IsEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

void BFS(Cell maze[][COL], int startRow, int startCol, int endRow, int endCol) {
    maze[startRow][startCol].isVisited = 1;
    Enqueue(startRow * COL + startCol);

    int rowDir[] = {-1, 0, 1, 0};
    int colDir[] = {0, 1, 0, -1};

    while (!IsEmpty()) {
        int pos = Dequeue();
        int row = pos / COL;
        int col = pos % COL;
        if (row == endRow && col == endCol) {
            return;
        }
        for (int i = 0; i < 4; i++) {
            int newRow = row + rowDir[i];
            int newCol = col + colDir[i];
            if (newRow < 0 || newRow >= ROW || newCol < 0 || newCol >= COL) {
                continue;
            }
            if (maze[newRow][newCol].isVisited == 1) {
                continue;
            }
            if (maze[newRow][newCol].row == -1) {
                continue;
            }
            maze[newRow][newCol].isVisited = 1;
            Enqueue(newRow * COL + newCol);
        }
    }
}

void PrintMaze(Cell maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j].row == -1) {
                printf("# ");
            } else if (maze[i][j].isVisited == 1) {
                printf("o ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Cell maze[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j].row = i;
            maze[i][j].col = j;
            maze[i][j].isVisited = 0;
        }
    }
    //Randomly add some walls
    int numWalls = (int)(ROW * COL * 0.2);
    for (int i = 0; i < numWalls; i++) {
        int row = rand() % ROW;
        int col = rand() % COL;
        if (maze[row][col].row == -1) {
            i--;
            continue;
        }
        maze[row][col].row = -1;
        maze[row][col].col = -1;
    }
    PrintMaze(maze);

    int startRow = rand() % ROW;
    int startCol = rand() % COL;
    while (maze[startRow][startCol].row == -1) {
        startRow = rand() % ROW;
        startCol = rand() % COL;
    }

    int endRow = rand() % ROW;
    int endCol = rand() % COL;
    while (maze[endRow][endCol].row == -1 || endRow == startRow || endCol == startCol) {
        endRow = rand() % ROW;
        endCol = rand() % COL;
    }

    printf("Start: (%d, %d)\n", startRow, startCol);
    printf("End: (%d, %d)\n", endRow, endCol);

    BFS(maze, startRow, startCol, endRow, endCol);
    PrintMaze(maze);

    return 0;
}