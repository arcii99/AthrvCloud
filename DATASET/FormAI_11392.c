//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLUMNS 7

char maze[ROWS][COLUMNS] = {
    {'#','#','#','#','#','#','#'},
    {'#',' ','#',' ','#',' ','#'},
    {'#',' ','#',' ',' ',' ','#'},
    {'#',' ','#','#','#',' ','#'},
    {'#',' ',' ',' ','#',' ','#'},
};

struct Position {
    int x;
    int y;
};

struct Node {
    struct Position position;
    struct Node *parent;
};

struct Queue {
    int head;
    int tail;
    struct Node *data[ROWS*COLUMNS];
};

void init_queue(struct Queue *q) {
    q->head = 0;
    q->tail = 0;
}

bool is_queue_empty(struct Queue *q) {
    return q->head == q->tail;
}

bool is_queue_full(struct Queue *q) {
    return q->tail == ROWS*COLUMNS;
}

void enqueue(struct Queue *q, struct Node *node) {
    if (is_queue_full(q)) {
        printf("Error: queue is full\n");
        return;
    }
    q->data[q->tail] = node;
    q->tail++;
}

struct Node *dequeue(struct Queue *q) {
    if (is_queue_empty(q)) {
        printf("Error: queue is empty\n");
        return NULL;
    }
    struct Node *result = q->data[q->head];
    q->head++;
    return result;
}

bool is_valid_position(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLUMNS && maze[x][y] == ' ';
}

bool is_end_position(int x, int y) {
    return x == 4 && y == 5;
}

bool is_start_position(int x, int y) {
    return x == 1 && y == 1;
}

void print_path(struct Node *node) {
    if (node == NULL) {
        return;
    }
    print_path(node->parent);
    printf("(%d,%d)\n", node->position.x, node->position.y);
}

void find_path() {
    struct Queue q;
    init_queue(&q);

    struct Node *start_node = malloc(sizeof(struct Node));
    start_node->position.x = 1;
    start_node->position.y = 1;
    start_node->parent = NULL;

    enqueue(&q, start_node);

    while (!is_queue_empty(&q)) {
        struct Node *current_node = dequeue(&q);

        if (is_end_position(current_node->position.x, current_node->position.y)) {
            print_path(current_node);
            return;
        }

        // add adjacent nodes to queue
        if (is_valid_position(current_node->position.x, current_node->position.y-1)) {
            struct Node *node = malloc(sizeof(struct Node));
            node->position.x = current_node->position.x;
            node->position.y = current_node->position.y-1;
            node->parent = current_node;
            enqueue(&q, node);
        }
        if (is_valid_position(current_node->position.x, current_node->position.y+1)) {
            struct Node *node = malloc(sizeof(struct Node));
            node->position.x = current_node->position.x;
            node->position.y = current_node->position.y+1;
            node->parent = current_node;
            enqueue(&q, node);
        }
        if (is_valid_position(current_node->position.x-1, current_node->position.y)) {
            struct Node *node = malloc(sizeof(struct Node));
            node->position.x = current_node->position.x-1;
            node->position.y = current_node->position.y;
            node->parent = current_node;
            enqueue(&q, node);
        }
        if (is_valid_position(current_node->position.x+1, current_node->position.y)) {
            struct Node *node = malloc(sizeof(struct Node));
            node->position.x = current_node->position.x+1;
            node->position.y = current_node->position.y;
            node->parent = current_node;
            enqueue(&q, node);
        }
    }

    printf("No path found!\n");
}

int main() {
    printf("Starting maze solver!\n");
    find_path();
    return 0;
}