//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 20

struct Node {
    int row;
    int col;
    struct Node* next;
};

struct Maze {
    int grid[ROWS][COLS];
    int startRow;
    int startCol;
    int endRow;
    int endCol;
};

void initMaze(struct Maze* maze) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze->grid[i][j] = 1;
        }
    }
    maze->startRow = 0;
    maze->startCol = 0;
    maze->endRow = ROWS - 1;
    maze->endCol = COLS - 1;
}

void printMaze(struct Maze* maze) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze->grid[i][j] == 0) {
                printf("  ");
            } else if (maze->grid[i][j] == 1) {
                printf("# ");
            } else if (maze->grid[i][j] == 2) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int isCoordinateValid(struct Maze* maze, int row, int col) {
    if (row < 0 || row >= ROWS) {
        return 0;
    }
    if (col < 0 || col >= COLS) {
        return 0;
    }
    if (maze->grid[row][col] != 0) {
        return 0;
    }
    return 1;
}

void pushQueue(struct Node** head, int row, int col) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
}

void popQueue(struct Node** head) {
    if (*head != NULL) {
        struct Node* p = *head;
        *head = (*head)->next;
        free(p);
    }
}

int isQueueEmpty(struct Node** head) {
    if (*head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

struct Node* findRoute(struct Maze* maze) {
    int visited[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            visited[i][j] = 0;
        }
    }
    
    struct Node* queue = NULL;
    pushQueue(&queue, maze->startRow, maze->startCol);
    visited[maze->startRow][maze->startCol] = 1;
    
    int foundRoute = 0;
    int curRow, curCol;
    while (!isQueueEmpty(&queue)) {
        curRow = queue->row;
        curCol = queue->col;
        popQueue(&queue);
        
        if (curRow == maze->endRow && curCol == maze->endCol) {
            foundRoute = 1;
            break;
        }
        
        if (isCoordinateValid(maze, curRow-1, curCol) && visited[curRow-1][curCol] == 0) {
            pushQueue(&queue, curRow-1, curCol);
            visited[curRow-1][curCol] = 1;
        }
        if (isCoordinateValid(maze, curRow+1, curCol) && visited[curRow+1][curCol] == 0) {
            pushQueue(&queue, curRow+1, curCol);
            visited[curRow+1][curCol] = 1;
        }
        if (isCoordinateValid(maze, curRow, curCol-1) && visited[curRow][curCol-1] == 0) {
            pushQueue(&queue, curRow, curCol-1);
            visited[curRow][curCol-1] = 1;
        }
        if (isCoordinateValid(maze, curRow, curCol+1) && visited[curRow][curCol+1] == 0) {
            pushQueue(&queue, curRow, curCol+1);
            visited[curRow][curCol+1] = 1;
        }
    }
    
    if (foundRoute) {
        struct Node* route = NULL;
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->row = curRow;
        node->col = curCol;
        node->next = NULL;
        route = node;
        while (curRow != maze->startRow || curCol != maze->startCol) {
            if (isCoordinateValid(maze, curRow-1, curCol) && visited[curRow-1][curCol] == 1) {
                curRow--;
            } else if (isCoordinateValid(maze, curRow+1, curCol) && visited[curRow+1][curCol] == 1) {
                curRow++;
            } else if (isCoordinateValid(maze, curRow, curCol-1) && visited[curRow][curCol-1] == 1) {
                curCol--;
            } else if (isCoordinateValid(maze, curRow, curCol+1) && visited[curRow][curCol+1] == 1) {
                curCol++;
            }
            node = (struct Node*) malloc(sizeof(struct Node));
            node->row = curRow;
            node->col = curCol;
            node->next = route;
            route = node;
        }
        return route;
    } else {
        return NULL;
    }
}

int main() {
    struct Maze maze;
    initMaze(&maze);
    maze.grid[1][0] = 0;
    maze.grid[1][1] = 0;
    maze.grid[1][2] = 0;
    maze.grid[1][3] = 0;
    maze.grid[1][4] = 0;
    maze.grid[2][4] = 0;
    maze.grid[3][4] = 0;
    maze.grid[4][4] = 0;
    maze.grid[5][4] = 0;
    maze.grid[6][4] = 0;
    maze.grid[6][3] = 0;
    maze.grid[6][2] = 0;
    maze.grid[6][1] = 0;
    maze.grid[6][0] = 0;
    maze.grid[5][0] = 0;
    
    printf("Maze:\n");
    printMaze(&maze);
    
    struct Node* route = findRoute(&maze);
    if (route != NULL) {
        printf("Route:\n");
        while (route != NULL) {
            printf("(%d,%d) ", route->row, route->col);
            maze.grid[route->row][route->col] = 2;
            route = route->next;
        }
        printf("\n");
        printf("Solved Maze:\n");
        printMaze(&maze);
    } else {
        printf("No route found!\n");
    }
    
    return 0;
}