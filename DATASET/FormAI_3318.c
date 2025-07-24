//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

struct node {
    int row, col;
    int f, g, h;
    struct node* parent;
};

int maze[ROW][COL] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0,0},
    {0,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

struct node* createNode(int row, int col, struct node* parent, int g, int h) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->row = row;
    newNode->col = col;
    newNode->parent = parent;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h;
    return newNode;
}

struct node* pathfinding(int startRow, int startCol, int endRow, int endCol) {
    int openList[ROW*COL][2], closedList[ROW][COL], row, col, i, j, nodeIndex;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            closedList[i][j] = 0;
        }
    }

    int index = 0;
    openList[index][0] = startRow;
    openList[index][1] = startCol;

    struct node* currentNode = createNode(startRow, startCol, NULL, 0, abs(endRow - startRow) + abs(endCol - startCol));

    while (index < ROW*COL && currentNode->row != endRow && currentNode->col != endCol) {
        int nodeRow = openList[0][0];
        int nodeCol = openList[0][1];
        nodeIndex = 0;
        closedList[nodeRow][nodeCol] = 1;

        if (nodeRow == endRow && nodeCol == endCol)
            return currentNode;

        int fValue = ROW*COL + 1;

        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if (nodeRow + i > ROW || nodeCol + j > COL || nodeRow + i < 0 || nodeCol + j < 0 || (i == 0 && j == 0) || maze[nodeRow + i][nodeCol + j] == 1 || closedList[nodeRow + i][nodeCol + j] == 1)
                    continue;

                int gValue = currentNode->g + abs(i) + abs(j);
                int hValue = abs(nodeRow + i - endRow) + abs(nodeCol + j - endCol);
                int fValue = gValue + hValue;

                struct node* neighbor = createNode(nodeRow + i, nodeCol + j, currentNode, gValue, hValue);

                for (int k = 0; k < index; k++) {
                    if (openList[k][0] == neighbor->row && openList[k][1] == neighbor->col && fValue > neighbor->f)
                        continue;
                }

                index++;
                openList[index][0] = neighbor->row;
                openList[index][1] = neighbor->col;

                free(neighbor);
            }
        }

        for (i = 0; i < index; i++) {
            if (maze[openList[i][0]][openList[i][1]] == 1 || closedList[openList[i][0]][openList[i][1]] == 1)
                continue;

            if (currentNode->f > (abs(openList[i][0] - endRow) + abs(openList[i][1] - endCol))) {
                nodeRow = openList[i][0];
                nodeCol = openList[i][1];
                nodeIndex = i;
                currentNode = createNode(nodeRow, nodeCol, currentNode, currentNode->g + abs(nodeRow - currentNode->row) + abs(nodeCol - currentNode->col), abs(nodeRow - endRow) + abs(nodeCol - endCol));
            }
        }

        if (index > nodeIndex) {
            openList[nodeIndex][0] = openList[index][0];
            openList[nodeIndex][1] = openList[index][1];
            index--;
        }
    }
    return NULL;
}

int main() {
    struct node* node = pathfinding(1, 1, 8, 8);
    while (node != NULL) {
        printf("(%d,%d)\n", node->row, node->col);
        node = node->parent; // the path will be printed in reverse order since we are traversing from the end node to the start node
    }
    return 0;
}