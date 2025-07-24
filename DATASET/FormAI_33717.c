//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int map[ROWS][COLS] = {0};

struct Node {
    int x, y;
    int f, g, h;
    struct Node *parent;
};

void initMap() {
    // randomly generate obstacles in the map
    srand(time(NULL));
    for (int i = 0; i < ROWS * COLS / 4; i++) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        map[r][c] = 1; // obstacle
    }

    // set start and end position
    map[0][0] = 2; // start
    map[ROWS-1][COLS-1] = 3; // end
}

int calcH(int x, int y) {
    return abs(x - ROWS + 1) + abs(y - COLS + 1);
}

int calcG(int sx, int sy, int x, int y) {
    int dx = abs(x - sx);
    int dy = abs(y - sy);
    if (dx > dy) return 14 * dy + 10 * (dx - dy);
    return 14 * dx + 10 * (dy - dx);
}

struct Node *newNode(int x, int y, int fx, int gx, int hx, struct Node *parent) {
    struct Node *node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->f = fx + hx;
    node->g = gx;
    node->h = hx;
    node->parent = parent;
    return node;
}

void printPath(struct Node *node) {
    while (node) {
        printf("(%d, %d) -> ", node->x, node->y);
        node = node->parent;
    }
    printf("END\n");
}

void aStar(int sx, int sy) {
    struct Node *openList[ROWS * COLS] = {NULL};
    struct Node *closedList[ROWS * COLS] = {NULL};

    int openCount = 0, closedCount = 0;
    int destX = ROWS - 1, destY = COLS - 1;
    struct Node *start = newNode(sx, sy, 0, 0, calcH(sx, sy), NULL);
    openList[openCount++] = start;

    while (openCount > 0) {
        struct Node *q = openList[0];
        int qIdx = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < q->f)
                q = openList[i], qIdx = i;
        }
        openList[qIdx] = openList[--openCount];

        int x = q->x, y = q->y;
        if (x == destX && y == destY) {
            printPath(q);
            return;
        }

        closedList[closedCount++] = q;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int nx = x + i, ny = y + j;
                if (nx < 0 || nx >= ROWS || ny < 0 || ny >= COLS) continue;
                if (map[nx][ny] == 1) continue;

                int g = q->g + calcG(x, y, nx, ny);
                int h = calcH(nx, ny);
                int f = g + h;

                struct Node *succ = NULL;
                for (int k = 0; k < openCount; k++) {
                    if (openList[k]->x == nx && openList[k]->y == ny) {
                        succ = openList[k];
                        break;
                    }
                }

                if (!succ) {
                    for (int k = 0; k < closedCount; k++) {
                        if (closedList[k]->x == nx && closedList[k]->y == ny) {
                            succ = closedList[k];
                            break;
                        }
                    }
                }

                if (!succ || f < succ->f) {
                    struct Node *newSucc = newNode(nx, ny, f, g, h, q);
                    if (succ) {
                        for (int k = 0; k < openCount; k++) {
                            if (openList[k] == succ) {
                                openList[k] = newSucc;
                                break;
                            }
                        }
                        for (int k = 0; k < closedCount; k++) {
                            if (closedList[k] == succ) {
                                closedList[k] = newSucc;
                                break;
                            }
                        }
                        free(succ);
                    } else openList[openCount++] = newSucc;
                }
            }
        }
    }

    printf("Path not found!\n");
}

int main() {
    initMap();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    aStar(0, 0);

    return 0;
}