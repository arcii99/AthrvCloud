//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 5
#define COL 5

// define Node structure
struct Node {
    int row;
    int col;
    int hScore;
    int gScore;
    int fScore;
    struct Node *parent;
    int closed;
    int obstacle;
};

typedef struct Node node;

// define global variables
node grid[ROW][COL];
node *closedList[ROW*COL];
node *openList[ROW*COL];
int openSize = 0;
int closedSize = 0;

// define helper functions
float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int isValid(int row, int col) {
    return row >= 0 && col >= 0 && row < ROW && col < COL && !grid[row][col].obstacle;
}

node* getNode(int row, int col) {
    return &grid[row][col];
}

int isInClosedList(node *n) {
    int i;
    for (i = 0; i < closedSize; i++)
        if (n == closedList[i])
            return 1;
    return 0;
}

int isInOpenList(node *n) {
    int i;
    for (i = 0; i < openSize; i++)
        if (n == openList[i])
            return 1;
    return 0;
}

void removeFromOpenList(node *n) {
    int i, j;
    for (i = 0; i < openSize; i++)
        if (n == openList[i]) {
            for (j = i; j < openSize - 1; j++)
                openList[j] = openList[j + 1];
            openSize--;
            break;
        }
}

int getLowestFScoreOpenList() {
    int i, idx = 0;
    int lowest = openList[0]->fScore;
    
    for (i = 1; i < openSize; i++) {
        if (openList[i]->fScore < lowest) {
            lowest = openList[i]->fScore;
            idx = i;
        }
    }

    return idx;
}

// define a* pathfinding function
void aStarPathfinding(int startRow, int startCol, int endRow, int endCol) {
    int i, j;
    node *current, *temp;
    int tentativeGScore;
    
    // add starting node to open list
    grid[startRow][startCol].gScore = 0;
    grid[startRow][startCol].hScore = (int)distance(startRow, startCol, endRow, endCol);
    grid[startRow][startCol].fScore = grid[startRow][startCol].hScore;
    openList[openSize++] = &grid[startRow][startCol];
    
    while (openSize > 0) {
        // get the node with the lowest fScore from the open list
        current = openList[getLowestFScoreOpenList()];

        // if we found the end node, return the path
        if (current == &grid[endRow][endCol]) {
            printf("\nPath found!\n");
            printf("Total distance: %d\n", current->fScore);
            while (current->parent != NULL) {
                printf("(%d,%d)\n", current->row, current->col);
                current = current->parent;
            }
            return;
        }

        // move current node to closed list
        removeFromOpenList(current);
        closedList[closedSize++] = current;
        current->closed = 1;

        // explore neighbors
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (isValid(current->row + i, current->col + j)) {
                    temp = getNode(current->row + i, current->col + j);
                    tentativeGScore = current->gScore + (int)distance(current->row, current->col, temp->row, temp->col);

                    if (isInClosedList(temp) && tentativeGScore >= temp->gScore)
                        continue;

                    if (!isInOpenList(temp) || tentativeGScore < temp->gScore) {
                        temp->parent = current;
                        temp->gScore = tentativeGScore;
                        temp->hScore = (int)distance(temp->row, temp->col, endRow, endCol);
                        temp->fScore = temp->gScore + temp->hScore;

                        if (!isInOpenList(temp)) {
                            openList[openSize++] = temp;
                        }
                    }
                }
            }
        }
    }
    
    // if we reached here, there is no path
    printf("\nNo path found!\n");
}

int main() {
    int i, j;
    int startRow = 2, startCol = 2, endRow = 4, endCol = 4;
    
    // create nodes and obstacles
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].gScore = 9999999;
            grid[i][j].obstacle = (rand() % 6 == 0) ? 1 : 0; // 1/6 chance of obstacle
        }
    }
    grid[startRow][startCol].obstacle = 0;
    grid[endRow][endCol].obstacle = 0;

    // print grid
    printf("Grid:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", grid[i][j].obstacle);
        }
        printf("\n");
    }

    // find path
    aStarPathfinding(startRow, startCol, endRow, endCol);

    return 0;
}