//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

int map[ROWS][COLUMNS];
bool visited[ROWS][COLUMNS];

// define player structures
typedef struct {
    int x; // x-coordinate
    int y; // y-coordinate
} Player;

Player players[2]; // an array of two players    

int bfs(int startX, int startY, int endX, int endY) {
    
    // create queue structure
    typedef struct {
        int x;
        int y;
        int distance;
    } Node;
    Node queue[ROWS*COLUMNS];
    int front = 0, rear = 0;
    
    // add the starting point to the queue
    Node start = {startX, startY, 0};
    queue[rear++] = start;
    
    // mark the starting point as visited
    visited[startX][startY] = true;
    
    // perform BFS
    while (front != rear) {
        Node current = queue[front++];
        int x = current.x;
        int y = current.y;
        int distance = current.distance;
        
        // check if we have reached the end point
        if (x == endX && y == endY)
            return distance;
        
        // try moving up
        if (x > 0 && !visited[x-1][y] && map[x-1][y] == 0) {
            Node next = {x-1, y, distance+1};
            queue[rear++] = next;
            visited[x-1][y] = true;
        }
        
        // try moving down
        if (x < ROWS-1 && !visited[x+1][y] && map[x+1][y] == 0) {
            Node next = {x+1, y, distance+1};
            queue[rear++] = next;
            visited[x+1][y] = true;
        }
        
        // try moving left
        if (y > 0 && !visited[x][y-1] && map[x][y-1] == 0) {
            Node next = {x, y-1, distance+1};
            queue[rear++] = next;
            visited[x][y-1] = true;
        }
        
        // try moving right
        if (y < COLUMNS-1 && !visited[x][y+1] && map[x][y+1] == 0) {
            Node next = {x, y+1, distance+1};
            queue[rear++] = next;
            visited[x][y+1] = true;
        }
    }
    
    // there is no path to the end point
    return -1;
}

int main() {
    
    // fill the map with obstacles
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            map[i][j] = rand() % 2;
        }
    }
    
    // create two players with random positions
    for (int i = 0; i < 2; i++) {
        players[i].x = rand() % ROWS;
        players[i].y = rand() % COLUMNS;
    }
    
    // print the map and the players' positions
    printf("Map and Players:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (i == players[0].x && j == players[0].y)
                printf("P1 ");
            else if (i == players[1].x && j == players[1].y)
                printf("P2 ");
            else if (map[i][j] == 1)
                printf("X  ");
            else
                printf("-  ");
        }
        printf("\n");
    }
    printf("\n");
    
    // calculate the shortest path for each player
    int pathLength[2];
    for (int i = 0; i < 2; i++) {
        int startX = players[i].x;
        int startY = players[i].y;
        int endX = players[(i+1)%2].x;
        int endY = players[(i+1)%2].y;
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLUMNS; k++) {
                visited[j][k] = false;
            }
        }
        pathLength[i] = bfs(startX, startY, endX, endY);
    }
    
    // print the shortest path for each player
    printf("Shortest Paths:\n");
    printf("P1 to P2: %d\n", pathLength[0]);
    printf("P2 to P1: %d\n", pathLength[1]);
    
    return 0;
}