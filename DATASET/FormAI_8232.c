//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

int maze[ROWS][COLS];
int visited[ROWS][COLS];

int directions[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

Node* path = NULL;

void push(Node** head_ref, int x, int y) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void pop(Node** head_ref) {
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

int is_empty(Node* head) {
    return head == NULL;
}

void print_path() {
    Node* current = path;
    while(current != NULL) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }
    printf("\n");
}

void generate_maze() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2;
        }   
    }
}

void print_maze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int x, int y) {
    if(x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0 && visited[x][y] == 0) {
        return 1;
    }
    return 0;
}

int is_exit(int x, int y) {
    if(x == ROWS - 1 || x == 0 || y == COLS - 1 || y == 0) {
        return 1;
    }
    return 0;
}

void dfs(int x, int y) {
    visited[x][y] = 1;
    if(is_exit(x, y)) {
        push(&path, x, y);
        print_path();
        pop(&path);
        visited[x][y] = 0;
        return;
    }
    push(&path, x, y);
    for(int i = 0; i < 4; i++) {
        int next_x = x + directions[i][0];
        int next_y = y + directions[i][1];
        if(is_valid(next_x, next_y)) {
            dfs(next_x, next_y);
        }
    }
    pop(&path);
    visited[x][y] = 0;
}

int main() {
    generate_maze();
    print_maze();
    printf("Possible paths:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 0) {
                dfs(i, j);
            }
        }
    }
    return 0;
}