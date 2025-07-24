//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define ROWS 5
#define COLS 5
#define MAX_QUEUE_SIZE ROWS*COLS

typedef struct {
    int x;
    int y;
    int dist;
} point;

typedef struct {
    point items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} queue;

void init(queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(queue *q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(queue *q, point p) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    } else if (is_empty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->items[q->rear] = p;
}

point dequeue(queue *q) {
    point item;
    if (is_empty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    } else if (q->front == q->rear) {
        item = q->items[q->front];
        q->front = q->rear = -1;
    } else {
        item = q->items[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return item;
}

void print_matrix(int m[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void bfs(int m[ROWS][COLS], point src, point dest) {
    int visited[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            visited[i][j] = 0;
        }
    }
    visited[src.x][src.y] = 1;

    queue q;
    init(&q);
    enqueue(&q, src);

    while (!is_empty(&q)) {
        point curr = dequeue(&q);

        if (curr.x == dest.x && curr.y == dest.y) {
            m[curr.x][curr.y] = curr.dist;
            break;
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (i = 0; i < 4; i++) {
            int next_x = curr.x + dx[i];
            int next_y = curr.y + dy[i];
            if (next_x >= 0 && next_x < ROWS && next_y >= 0 && next_y < COLS && !visited[next_x][next_y]) {
                visited[next_x][next_y] = 1;
                point next = {next_x, next_y, curr.dist + 1};
                enqueue(&q, next);
            }
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
            {0, 0, 0, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0}
    };
    point src = {0, 0, 0};
    point dest = {ROWS - 1, COLS - 1, 0};
    bfs(matrix, src, dest);
    print_matrix(matrix);
    return 0;
}