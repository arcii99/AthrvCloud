//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

struct Node {
    int x;
    int y;
    struct Node* next;
};

typedef struct {
    int x;
    int y;
} Point;

// The maze
int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

// Variables
bool visited[ROWS][COLS];
bool found = false;
struct Node* head = NULL;
struct Node* tail = NULL;
Point start = {1,1};
Point end = {8,8};
int shortest_path_length = 1000;
struct Node* shortest_path = NULL;

// Helper functions
void push(int x, int y) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    
    if(head == NULL) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

void pop() {
    struct Node* temp = head;
    
    if(head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = head->next;
    }
    
    free(temp);
}

// Main functions
void find_path(int x, int y, int path_length) {
    
    // Check if we reached the end point
    if(x == end.x && y == end.y) {
        found = true;
        
        if(path_length < shortest_path_length) {
            shortest_path_length = path_length;
            shortest_path = head;
        }
        
        return;
    }
    
    // Check if current position is valid and not visited
    if(x<0 || x>=ROWS || y<0 || y>=COLS || visited[x][y] || maze[x][y]==1) {
        return;
    }
    
    // Mark current position as visited and push to queue
    visited[x][y] = true;
    push(x, y);
    
    // Recursively find path
    find_path(x+1, y, path_length+1);
    if(found) return;
    
    find_path(x, y+1, path_length+1);
    if(found) return;
    
    find_path(x-1, y, path_length+1);
    if(found) return;
    
    find_path(x, y-1, path_length+1);
    if(found) return;
    
    // Mark current position as not visited and pop from queue
    visited[x][y] = false;
    pop();
}

void print_maze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 1) {
                printf("X");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_path(struct Node* path) {
    while(path != NULL) {
        printf("(%d,%d) ", path->x, path->y);
        path = path->next;
    }
}

int main() {
    clock_t start_time, end_time;
    
    printf("Maze:\n");
    print_maze();
    printf("\n");
    
    start_time = clock();
    find_path(start.x, start.y, 0);
    end_time = clock();
    
    if(found) {
        printf("Shortest path from (%d,%d) to (%d,%d):\n", start.x, start.y, end.x, end.y);
        print_path(shortest_path);
        printf("\n\n");
        printf("Shortest path length: %d\n", shortest_path_length);
        printf("Time taken: %f seconds\n", (double)(end_time-start_time)/CLOCKS_PER_SEC);
    }
    else {
        printf("Path not found\n");
    }
    
    return 0;
}