//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 9
#define COL 10
#define MAX_NODES ROW*COL

typedef struct {
    int row;
    int col;
} Node;

int heuristic(Node curr, Node goal) {
    return abs(curr.row - goal.row) + abs(curr.col - goal.col);
}

int fCost[MAX_NODES];
int gCost[MAX_NODES];
int cameFrom[MAX_NODES];
bool closedSet[MAX_NODES];
Node openSet[MAX_NODES];
int openSetSize = 0;

int getIndexOfNode(Node *node) {
    return node->row * COL + node->col;
}

Node getNodeAtIndex(int index) {
    return (Node){index / COL, index % COL};
}

void insertIntoOpenSet(Node *node) {
    int index = openSetSize;
    openSet[index] = *node;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (fCost[getIndexOfNode(&openSet[index])] >= fCost[getIndexOfNode(&openSet[parentIndex])]) break;

        Node tmp = openSet[index];
        openSet[index] = openSet[parentIndex];
        openSet[parentIndex] = tmp;
        index = parentIndex;
    }

    openSetSize++;
}

Node *getFromOpenSet() {
    openSetSize--;
    Node *result = malloc(sizeof(Node));
    *result = openSet[0];

    openSet[0] = openSet[openSetSize];

    int index = 0;

    while (true) {
        int leftChildIndex = index * 2 + 1;
        int rightChildIndex = index * 2 + 2;
        int smallestChildIndex = index;

        if (leftChildIndex < openSetSize && fCost[getIndexOfNode(&openSet[leftChildIndex])] < fCost[getIndexOfNode(&openSet[smallestChildIndex])])
            smallestChildIndex = leftChildIndex;

        if (rightChildIndex < openSetSize && fCost[getIndexOfNode(&openSet[rightChildIndex])] < fCost[getIndexOfNode(&openSet[smallestChildIndex])])
            smallestChildIndex = rightChildIndex;

        if (smallestChildIndex == index) break;

        Node tmp = openSet[index];
        openSet[index] = openSet[smallestChildIndex];
        openSet[smallestChildIndex] = tmp;

        index = smallestChildIndex;
    }

    return result;
}

void astar(int graph[][COL], Node start, Node goal) {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            int index = row * COL + col;
            fCost[index] = -1;
            gCost[index] = -1;
            cameFrom[index] = -1;
            closedSet[index] = false;
        }
    }

    fCost[getIndexOfNode(&start)] = heuristic(start, goal);
    gCost[getIndexOfNode(&start)] = 0;

    insertIntoOpenSet(&start);

    while (openSetSize > 0) {
        Node *current = getFromOpenSet();

        if (current->row == goal.row && current->col == goal.col) {
            free(current);
            break;
        }

        int currIndex = getIndexOfNode(current);
        closedSet[currIndex] = true;

        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dy == 0 && dx == 0) continue;

                int neighborRow = current->row + dy;
                int neighborCol = current->col + dx;

                if (neighborRow < 0 || neighborRow >= ROW || neighborCol < 0 || neighborCol >= COL) continue;

                if (graph[neighborRow][neighborCol] == -1) continue;

                int neighbourIndex = neighborRow * COL + neighborCol;

                if (closedSet[neighbourIndex]) continue;

                int tentativeGCost = gCost[currIndex] + abs(dx) + abs(dy);

                if (gCost[neighbourIndex] == -1 || tentativeGCost < gCost[neighbourIndex]) {
                    gCost[neighbourIndex] = tentativeGCost;
                    fCost[neighbourIndex] = tentativeGCost + heuristic((Node){neighborRow, neighborCol}, goal);
                    cameFrom[neighbourIndex] = currIndex;

                    bool foundInOpenSet = false;

                    for (int i = 0; i < openSetSize; i++) {
                        if (openSet[i].row == neighborRow && openSet[i].col == neighborCol) {
                            foundInOpenSet = true;
                            break;
                        }
                    }

                    if (!foundInOpenSet)
                        insertIntoOpenSet(&(Node){neighborRow, neighborCol});
                }
            }
        }

        free(current);
    }
}

void printPath(int graph[][COL], Node start, Node goal) {
    int index = getIndexOfNode(&goal);

    while (index != getIndexOfNode(&start)) {
        Node node = getNodeAtIndex(index);
        graph[node.row][node.col] = 'X';
        index = cameFrom[index];
    }

    graph[start.row][start.col] = 'S';
    graph[goal.row][goal.col] = 'G';

    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++)
            printf("%c", graph[row][col] == -1 ? '#' : graph[row][col]);
        printf("\n");
    }
}

int main() {
    int graph[ROW][COL] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, -1, -1, -1, -1, 0, 0, 0 },
        { 0, 0, 0, -1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, -1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, -1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, -1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, -1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, -1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, -1, -1, -1, -1, 0, 0, 0 }
    };

    Node start = { 1, 1 };
    Node goal = { 7, 8 };

    astar(graph, start, goal);
    printPath(graph, start, goal);

    return 0;
}