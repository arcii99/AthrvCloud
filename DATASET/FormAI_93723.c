//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 20
#define WALL_CHR '#'
#define EMPTY_CHR ' '
#define START_CHR 'S'
#define GOAL_CHR 'G'
#define PATH_CHR '@'
#define COST_DIAGONAL 14
#define COST_STRAIGHT 10

typedef struct {
    int x, y;
    int f, g, h;
} Node;

void printBoard(char board[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isInRange(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

bool isPassable(char board[ROWS][COLS], int x, int y) {
    return board[x][y] == EMPTY_CHR || board[x][y] == GOAL_CHR;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int findLowestF(Node list[], int length) {
    int index = 0;
    for (int i = 1; i < length; i++) {
        if (list[i].f < list[index].f) {
            index = i;
        }
    }
    return index;
}

void reconstructPath(char board[ROWS][COLS], Node cameFrom[][COLS], Node current) {
    while (true) {
        board[current.x][current.y] = PATH_CHR;
        if (board[current.x][current.y] == START_CHR) {
            break;
        }
        current = cameFrom[current.x][current.y];
    }
}

void aStar(char board[ROWS][COLS], Node start, Node goal) {
    Node openList[ROWS*COLS];
    int openListLength = 0;
    Node closedList[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            closedList[i][j].x = -1;
            closedList[i][j].y = -1;
        }
    }
    bool foundGoal = false;
    start.g = 0;
    start.h = heuristic(start.x, start.y, goal.x, goal.y);
    start.f = start.g + start.h;
    openList[openListLength++] = start;
    while (openListLength > 0) {
        int currentIndex = findLowestF(openList, openListLength);
        Node current = openList[currentIndex];
        if (current.x == goal.x && current.y == goal.y) {
            reconstructPath(board, closedList, current);
            foundGoal = true;
            break;
        }
        if (currentIndex != openListLength-1) {
            Node swap = openList[currentIndex];
            openList[currentIndex] = openList[openListLength-1];
            openList[openListLength-1] = swap;
        }
        openListLength--;
        closedList[current.x][current.y] = current;
        Node neighbors[8];
        int neighborCount = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i != 0 || j != 0) {
                    int x = current.x + i;
                    int y = current.y + j;
                    if (isInRange(x, y) && isPassable(board, x, y)) {
                        int cost = COST_STRAIGHT;
                        if (abs(i) == 1 && abs(j) == 1) {
                            cost = COST_DIAGONAL;
                        }
                        Node next = {
                            .x = x,
                            .y = y,
                            .g = current.g + cost,
                            .h = heuristic(x, y, goal.x, goal.y),
                            .f = current.g + cost + heuristic(x, y, goal.x, goal.y)
                        };
                        bool skipNeighbor = false;
                        for (int k = 0; k < openListLength; k++) {
                            if (openList[k].x == x && openList[k].y == y && openList[k].f < next.f) {
                                skipNeighbor = true;
                                break;
                            }
                        }
                        if (!skipNeighbor) {
                            for (int k = 0; k < neighborCount; k++) {
                                if (next.x == neighbors[k].x && next.y == neighbors[k].y && next.f < neighbors[k].f) {
                                    neighbors[k] = next;
                                    skipNeighbor = true;
                                    break;
                                }
                            }
                            if (!skipNeighbor) {
                                neighbors[neighborCount++] = next;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < neighborCount; i++) {
            bool skipNeighbor = false;
            for (int j = 0; j < openListLength; j++) {
                if (openList[j].x == neighbors[i].x && openList[j].y == neighbors[i].y && openList[j].f < neighbors[i].f) {
                    skipNeighbor = true;
                    break;
                }
            }
            if (!skipNeighbor) {
                for (int j = 0; j < openListLength; j++) {
                    if (openList[j].x == neighbors[i].x && openList[j].y == neighbors[i].y) {
                        openList[j] = neighbors[i];
                        skipNeighbor = true;
                        break;
                    }
                }
                if (!skipNeighbor) {
                    openList[openListLength++] = neighbors[i];
                }
            }
        }
    }
    if (!foundGoal) {
        printf("No path found.\n");
    }
}

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                board[i][j] = WALL_CHR;
            } else {
                board[i][j] = EMPTY_CHR;
            }
        }
    }
    board[ROWS/2][COLS/3] = START_CHR;
    board[ROWS/2][2*COLS/3] = GOAL_CHR;
}

int main() {
    char board[ROWS][COLS];
    initBoard(board);
    printBoard(board);
    Node start = { .x = ROWS/2, .y = COLS/3 };
    Node goal = { .x = ROWS/2, .y = 2*COLS/3 };
    aStar(board, start, goal);
    printBoard(board);
    return 0;
}