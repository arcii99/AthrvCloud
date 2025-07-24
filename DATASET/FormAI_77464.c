//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct Node {
    int i, j;
    double g, h, f;
    struct Node* parent;
    bool closed;
} Node;

Node* startNode;
Node* endNode;

Node* createNode(int i, int j, double g, double h, double f, Node* parent, bool closed) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->i = i;
    newNode->j = j;
    newNode->g = g;
    newNode->h = h;
    newNode->f = f;
    newNode->parent = parent;
    newNode->closed = closed;
    return newNode;
}

double heuristic(Node* currNode) {
    double dx = abs(currNode->i - endNode->i);
    double dy = abs(currNode->j - endNode->j);
    return sqrt(dx * dx + dy * dy);
}

Node* lowestFNode(Node* openList[]) {
    Node* lowestF = openList[0];
    int lowestIndex = 0;
    for(int i = 1; i < ROW * COL && openList[i] != NULL; i++) {
        if(openList[i]->f < lowestF->f) {
            lowestF = openList[i];
            lowestIndex = i;
        }
    }
    openList[lowestIndex] = NULL;
    return lowestF;
}

bool isOnClosedList(Node* currNode) {
    if(currNode->closed == true) {
        return true;
    }
    else {
        return false;
    }
}

bool isBlocked(int map[][COL], int i, int j) {
    if(map[i][j] == 1) {
        return true;
    }
    else {
        return false;
    }
}

bool isOnOpenList(Node* openList[], Node* currNode) {
    for(int i = 0; i < ROW * COL && openList[i] != NULL; i++) {
        if(currNode->i == openList[i]->i && currNode->j == openList[i]->j) {
            return true;
        }
    }
    return false;
}

bool isOnMap(int i, int j) {
    if(i < 0 || j < 0 || i >= ROW || j >= COL) {
        return false;
    }
    else {
        return true;
    }
}

void printMap(int map[][COL], Node* path[]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(map[i][j] == 1) {
                printf("# ");
            }
            else {
                if(startNode->i == i && startNode->j == j) {
                    printf("S ");
                    continue;
                }
                if(endNode->i == i && endNode->j == j) {
                    printf("E ");
                    continue;
                }
                bool onPath = false;
                for(int k = 0; k < ROW * COL && path[k] != NULL; k++) {
                    if(path[k]->i == i && path[k]->j == j) {
                        printf(". ");
                        onPath = true;
                        break;
                    }
                }
                if(!onPath) {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
}

void traceback(Node* path[]) {
    Node* currNode = endNode;
    int i = 0;
    while(currNode != startNode) {
        path[i] = currNode;
        i++;
        currNode = currNode->parent;
    }
    path[i] = startNode;
}

void AStar(int map[][COL]) {
    Node* openList[ROW * COL];
    Node* path[ROW * COL];

    for(int i = 0; i < ROW * COL; i++) {
        openList[i] = NULL;
        path[i] = NULL;
    }

    startNode = createNode(0, 0, 0, heuristic(startNode), heuristic(startNode), NULL, false);
    endNode = createNode(9, 9, INFINITY, 0, INFINITY, NULL, false);
    openList[0] = startNode;

    while(openList[0] != NULL) {
        Node* currNode = lowestFNode(openList);

        currNode->closed = true;

        if(currNode->i == endNode->i && currNode->j == endNode->j) {
            traceback(path);
            printMap(map, path);
            return;
        }

        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }

                int neighborI = currNode->i + i;
                int neighborJ = currNode->j + j;

                if(!isOnMap(neighborI, neighborJ) || isBlocked(map, neighborI, neighborJ)) {
                    continue;
                }

                double neighborG = currNode->g + 1;

                Node* neighborNode = createNode(neighborI, neighborJ, neighborG, heuristic(currNode), neighborG + heuristic(currNode), currNode, false);

                if(isOnClosedList(neighborNode)) {
                    continue;
                }

                if(!isOnOpenList(openList, neighborNode)) {
                    for(int k = 0; k < ROW * COL && openList[k] != NULL; k++) {
                        if(openList[k] == NULL) {
                            openList[k] = neighborNode;
                            break;
                        }
                    }
                }
                else {
                    for(int k = 0; k < ROW * COL && openList[k] != NULL; k++) {
                        if(openList[k]->i == neighborI && openList[k]->j == neighborJ) {
                            if(neighborNode->g < openList[k]->g) {
                                openList[k]->g = neighborNode->g;
                                openList[k]->h = neighborNode->h;
                                openList[k]->f = neighborNode->f;
                                openList[k]->parent = currNode;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int map[ROW][COL] = 
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, 1, 1, 0, 1, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
     {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    AStar(map);

    return 0;
}