//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int graph[ROWS][COLS];

typedef struct node {
    int x;
    int y;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

Node *create_node(int x, int y) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    return temp;
}

Queue *create_queue() {
    Queue *temp = (Queue*)malloc(sizeof(Queue));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}

int is_empty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int x, int y) {
    Node *temp = create_node(x, y);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* dequeue(Queue *q) {
    if (q->front == NULL) {
        return NULL;
    }
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return temp;
}

int bfs(int start_x, int start_y, int end_x, int end_y) {
    Queue *q = create_queue();
    enqueue(q, start_x, start_y);
    int visited[ROWS][COLS] = {0};
    visited[start_x][start_y] = 1;
    int distance[ROWS][COLS] = {0};
    Node *current_node = NULL;
    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};
    while (!is_empty(q)) {
        current_node = dequeue(q);
        if (current_node->x == end_x && current_node->y == end_y) {
            return distance[current_node->x][current_node->y];
        }
        for (int i = 0; i < 4; i++) {
            int new_x = current_node->x + row[i];
            int new_y = current_node->y + col[i];
            if (new_x >= 0 && new_x < ROWS && new_y >= 0 && new_y < COLS
                && !visited[new_x][new_y] && graph[new_x][new_y] != 1) {
                visited[new_x][new_y] = 1;
                enqueue(q, new_x, new_y);
                distance[new_x][new_y] = distance[current_node->x][current_node->y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int start_x = 8;
    int start_y = 8;
    int end_x = 2;
    int end_y = 6;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                graph[i][j] = 1;
            } else {
                graph[i][j] = 0;
            }
        }
    }
    graph[3][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[2][5] = 1;
    int distance = bfs(start_x, start_y, end_x, end_y);
    if (distance != -1) {
        printf("Distance is %d", distance);
    } else {
        printf("Path does not exist.");
    }
    return 0;
}