//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: artistic
#include <stdio.h>

#define ROW 10
#define COL 10
#define START_ROW 5
#define START_COL 5
#define END_ROW 8
#define END_COL 9

typedef struct {
    int row;
    int col;
} Node;

int main() {
    int graph[ROW][COL] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };

    Node start = {START_ROW, START_COL};
    Node end = {END_ROW, END_COL};

    int visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    Node queue[ROW * COL];
    int front = 0, rear = 0;
    queue[rear++] = start;

    visited[start.row][start.col] = 1;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (front < rear) {
        Node current = queue[front++];

        if (current.row == end.row && current.col == end.col) {
            printf("Reached destination!\n");
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_row = current.row + dx[i];
            int next_col = current.col + dy[i];

            if (next_row < 0 || next_row >= ROW || next_col < 0 || next_col >= COL) {
                continue;
            }
            if (graph[next_row][next_col] == 1) {
                continue;
            }
            if (visited[next_row][next_col] == 0) {
                visited[next_row][next_col] = 1;
                queue[rear++] = (Node){next_row, next_col};
            }
        }
    }

    return 0;
}