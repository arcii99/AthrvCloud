//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 15

int maze[ROW][COL] = 
{ 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
{0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
{0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
{0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0},
{0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0},
{0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0},
{0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0},
{0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int visited[ROW][COL];

struct location {
    int row;
    int col;
};

struct queue {
    struct location q[ROW*COL];
    int size;
};

void init_queue(struct queue *q) {
    q->size = 0;
}

void enqueue(struct queue *q, struct location cell) {
    q->q[q->size++] = cell;
}

struct location dequeue(struct queue *q) {
    int i;
    struct location cell = q->q[0];

    q->size--;

    for (i=0; i<q->size; i++) {
        q->q[i] = q->q[i+1];
    }

    return cell;
}

int is_empty(struct queue *q) {
    return q->size == 0;
}

void print_maze() {
    int i, j;
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void print_visited() {
    int i, j;
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

void bfs(struct location start, struct location end) {
    struct queue q;
    struct location curr, next;
    int i, row, col;

    init_queue(&q);

    for (i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            visited[i][j] = 0;
        }
    }

    enqueue(&q, start);

    while (!is_empty(&q)) {
        curr = dequeue(&q);

        if (curr.row == end.row && curr.col == end.col) {
            printf("Path found!\n");
            return;
        }

        row = curr.row;
        col = curr.col;

        if (row-1 >= 0 && !visited[row-1][col] && maze[row-1][col]) {
            next.row = row-1;
            next.col = col;
            visited[row-1][col] = 1;
            enqueue(&q, next);
        }

        if (row+1 < ROW && !visited[row+1][col] && maze[row+1][col]) {
            next.row = row+1;
            next.col = col;
            visited[row+1][col] = 1;
            enqueue(&q, next);
        }

        if (col-1 >= 0 && !visited[row][col-1] && maze[row][col-1]) {
            next.row = row;
            next.col = col-1;
            visited[row][col-1] = 1;
            enqueue(&q, next);
        }

        if (col+1 < COL && !visited[row][col+1] && maze[row][col+1]) {
            next.row = row;
            next.col = col+1;
            visited[row][col+1] = 1;
            enqueue(&q, next);
        }
    }

    printf("Path not found :(\n");
}

int main() {
    struct location start, end;

    start.row = 1;
    start.col = 1;
    end.row = ROW-2;
    end.col = COL-2;

    printf("Maze:\n");
    print_maze();
    printf("\n");
    printf("Visited:\n");
    print_visited();
    printf("\n");

    bfs(start, end);

    return 0;
}