//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 15

char maze[ROWS][COLUMNS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '.', '#', '.', '#', '#', '#', '.', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', 'E', '#', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '.', '.', '#', '.', '#', '#', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

struct Position {
    int x;
    int y;
};

struct Node {
    struct Position pos;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};

void init(struct Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool isEmpty(struct Queue *q) {
    return q->head == NULL;
}

void enqueue(struct Queue *q, struct Position pos) {
    struct Node *node = malloc(sizeof(struct Node));
    node->pos = pos;
    node->next = NULL;
    
    if (isEmpty(q)) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
}

struct Position dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        struct Position result = {-1, -1};
        return result;
    }
    
    struct Position result = q->head->pos;
    struct Node *temp = q->head;
    q->head = q->head->next;
    free(temp);
    
    return result;
}

bool isValid(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLUMNS) {
        return false;
    }
    
    if (maze[x][y] == '#') {
        return false;
    }
    
    return true;
}

void printPath(int prev[ROWS][COLUMNS], struct Position start, struct Position end) {
    struct Position current = end;
    struct Position path[ROWS*COLUMNS];
    int count = 0;
    
    while (current.x != start.x || current.y != start.y) {
        path[count] = current;
        current = (struct Position){prev[current.x][current.y]/COLUMNS, prev[current.x][current.y]%COLUMNS};
        count++;
    }
    
    path[count] = start;
    
    for (int i = count; i >= 0; i--) {
        printf("(%d,%d)  ", path[i].x, path[i].y);
    }
    
    printf("\n");
}

void bfs(struct Position start, struct Position end) {
    int prev[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            prev[i][j] = -1;
        }
    }
    
    struct Queue q;
    init(&q);
    enqueue(&q, start);
    
    while (!isEmpty(&q)) {
        struct Position current = dequeue(&q);
        
        if (current.x == end.x && current.y == end.y) {
            printPath(prev, start, end);
            return;
        }
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            if (!isValid(nx, ny) || prev[nx][ny] != -1) {
                continue;
            }
            
            prev[nx][ny] = current.x*COLUMNS + current.y;
            enqueue(&q, (struct Position){nx, ny});
        }
    }
}

int main() {
    struct Position start = {1, 1};
    struct Position end = {4, 1};
    
    bfs(start, end);
    
    return 0;
}