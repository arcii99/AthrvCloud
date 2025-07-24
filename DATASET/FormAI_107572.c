//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: thoughtful
#include<stdio.h>
#define ROWS 10
#define COLS 10
#define INF 100000

typedef struct Node {
    int x;
    int y;
} Node;

int maze[ROWS][COLS] = {{0,2,1,1,1,0,1,0,0,0},
                        {1,0,0,1,0,0,1,1,1,0},
                        {1,1,1,0,0,1,1,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0},
                        {0,0,0,0,1,1,1,0,0,0},
                        {0,1,1,0,1,0,1,1,1,0},
                        {0,0,1,0,1,0,0,0,0,0},
                        {0,1,0,0,1,1,1,1,1,0},
                        {1,1,0,0,0,0,1,0,0,0},
                        {0,0,0,1,1,0,0,0,0,0}};

int distance[ROWS][COLS];
int visited[ROWS][COLS];

Node queue[ROWS*COLS];
int front = -1;
int rear = 0;

void BFS(Node start, Node target) {
    queue[0] = start;
    front++;
    
    visited[start.x][start.y] = 1;
    distance[start.x][start.y] = 0;
    
    while (front <= rear) {
        Node current = queue[front];
        front++;
        
        if (current.x == target.x && current.y == target.y) {
            printf("Path Found!\nDistance: %d\n", distance[current.x][current.y]);
            return;
        }
        
        if (current.x + 1 < ROWS && maze[current.x+1][current.y] == 1 && !visited[current.x+1][current.y]) {
            Node next = {current.x+1, current.y};
            queue[++rear] = next;
            visited[current.x+1][current.y] = 1;
            distance[current.x+1][current.y] = distance[current.x][current.y] + 1;
        }
        
        if (current.y + 1 < COLS && maze[current.x][current.y+1] == 1 && !visited[current.x][current.y+1]) {
            Node next = {current.x, current.y+1};
            queue[++rear] = next;
            visited[current.x][current.y+1] = 1;
            distance[current.x][current.y+1] = distance[current.x][current.y] + 1;
        }
        
        if (current.x - 1 >= 0 && maze[current.x-1][current.y] == 1 && !visited[current.x-1][current.y]) {
            Node next = {current.x-1, current.y};
            queue[++rear] = next;
            visited[current.x-1][current.y] = 1;
            distance[current.x-1][current.y] = distance[current.x][current.y] + 1;
        }
        
        if (current.y - 1 >= 0 && maze[current.x][current.y-1] == 1 && !visited[current.x][current.y-1]) {
            Node next = {current.x, current.y-1};
            queue[++rear] = next;
            visited[current.x][current.y-1] = 1;
            distance[current.x][current.y-1] = distance[current.x][current.y] + 1;
        }
    }
    
    printf("Path not found\n");
}

int main() {
    Node start = {0,0};
    Node target = {ROWS-1, COLS-1};
    
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            visited[i][j] = 0;
            distance[i][j] = INF;
        }
    }
    
    BFS(start, target);
    
    return 0;
}