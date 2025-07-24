//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

#define START_ROW 2
#define START_COL 1
#define END_ROW 6
#define END_COL 8

struct Point {
    int row;
    int col;
    int fCost;
    int hCost;
    int gCost;
    bool isObstacle;
    struct Point *parent;
};

bool isValid(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

bool isObstacle(int row, int col) {
    int obstacles[][2] = {{1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}};
    for (int i = 0; i < sizeof(obstacles)/sizeof(obstacles[0]); i++) {
        if (row == obstacles[i][0] && col == obstacles[i][1]) {
            return true;           
        }
    }
    return false;
}

int calculateHCost(int row, int col) {
    return abs(row - END_ROW) + abs(col - END_COL);
}

void printPath(struct Point *goal) {
    while (goal != NULL) {
        printf("(%d,%d)\n", goal->row, goal->col);
        goal = goal->parent;
    }
}

int main() {
    struct Point grid[ROW][COL];
    
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            grid[row][col].row = row;
            grid[row][col].col = col;
            grid[row][col].isObstacle = isObstacle(row, col);
        }
    }
    
    struct Point *openList[ROW*COL];
    struct Point *closedList[ROW*COL];
    int openListIdx = 0;
    int closedListIdx = 0;
    
    struct Point *start = &grid[START_ROW][START_COL];
    start->hCost = calculateHCost(START_ROW, START_COL);
    start->gCost = 0;
    start->fCost = start->hCost + start->gCost;
    openList[openListIdx++] = start;
    
    while (openListIdx > 0) {
        struct Point *current = openList[0];
        int currentIdx = 0;
        for (int i = 1; i < openListIdx; i++) {
            if (openList[i]->fCost < current->fCost) {
                current = openList[i];
                currentIdx = i;
            }
        }
        
        openListIdx--;
        for (int i = currentIdx; i < openListIdx; i++) {
            openList[i] = openList[i+1];
        }

        closedList[closedListIdx++] = current;
        
        if (current->row == END_ROW && current->col == END_COL) {
            printPath(current);
            return 0;
        }
        
        for (int row = current->row - 1; row <= current->row + 1; row++) {
            for (int col = current->col - 1; col <= current->col + 1; col++) {
                if (isValid(row, col) && !grid[row][col].isObstacle) {
                    bool inClosedList = false;
                    for (int i = 0; i < closedListIdx; i++) {
                        if (row == closedList[i]->row && col == closedList[i]->col) {
                            inClosedList = true;
                            break;
                        }
                    }
                    
                    if (!inClosedList) {
                        int gCost = current->gCost + (row == current->row || col == current->col ? 10 : 14);
                        bool inOpenList = false;
                        int openListIdxToUse = -1;
                        for (int i = 0; i < openListIdx; i++) {
                            if (row == openList[i]->row && col == openList[i]->col) {
                                inOpenList = true;
                                openListIdxToUse = i;
                                break;
                            }
                        }
                        
                        if (!inOpenList) {
                            struct Point *next = &grid[row][col];
                            next->parent = current;
                            next->hCost = calculateHCost(row, col);
                            next->gCost = gCost;
                            next->fCost = next->hCost + next->gCost;
                            openList[openListIdx++] = next;
                        } else if (gCost < openList[openListIdxToUse]->gCost) {
                            openList[openListIdxToUse]->gCost = gCost;
                            openList[openListIdxToUse]->fCost = openList[openListIdxToUse]->hCost + gCost;
                            openList[openListIdxToUse]->parent = current;
                        }
                    }
                }
            }
        }
    }
    
    printf("No path found\n");
    return 0;
}