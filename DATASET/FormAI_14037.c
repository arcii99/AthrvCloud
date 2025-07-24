//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include<stdio.h>

// Defining global variables
#define ROW 10
#define COL 10
#define INF 2147483647
int startX = 0, startY = 0; // Starting point coordinates
int endX = 9, endY = 9; // Ending point coordinates
int shortestPath[ROW*COL][2]; // Array to store the shortest path

// Function to find the shortest path using Dijkstra's algorithm
void findShortestPath(int graph[][COL], int dist[][COL], int visited[][COL], int parent[][COL], int x, int y, int destX, int destY, int weight) {
    if(x == destX && y == destY) {
        return;
    }
    
    visited[x][y] = 1; // Marking the current node as visited
    
    // Checking the neighbours of the current node
    if(x - 1 >= 0 && !visited[x-1][y] && dist[x-1][y] > weight + graph[x-1][y]) {
        dist[x-1][y] = weight + graph[x-1][y];
        parent[x-1][y] = x*COL + y;
        findShortestPath(graph, dist, visited, parent, x-1, y, destX, destY, dist[x-1][y]);
    }
    
    if(x + 1 < ROW && !visited[x+1][y] && dist[x+1][y] > weight + graph[x+1][y]) {
        dist[x+1][y] = weight + graph[x+1][y];
        parent[x+1][y] = x*COL + y;
        findShortestPath(graph, dist, visited, parent, x+1, y, destX, destY, dist[x+1][y]);
    }
    
    if(y - 1 >= 0 && !visited[x][y-1] && dist[x][y-1] > weight + graph[x][y-1]) {
        dist[x][y-1] = weight + graph[x][y-1];
        parent[x][y-1] = x*COL + y;
        findShortestPath(graph, dist, visited, parent, x, y-1, destX, destY, dist[x][y-1]);
    }
    
    if(y + 1 < COL && !visited[x][y+1] && dist[x][y+1] > weight + graph[x][y+1]) {
        dist[x][y+1] = weight + graph[x][y+1];
        parent[x][y+1] = x*COL + y;
        findShortestPath(graph, dist, visited, parent, x, y+1, destX, destY, dist[x][y+1]);
    }
}

int main() {
    int graph[ROW][COL] = {  // Defining the graph
        {3, 4, 2, 1, 6, 7, 8, 9, 3, 2},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 1},
        {2, 3, 4, 1, 6, 7, 9, 8, 5, 4},
        {5, 4, 2, 1, 3, 6, 7, 8, 9, 6},
        {8, 3, 1, 2, 7, 6, 5, 4, 9, 2},
        {9, 2, 4, 5, 1, 3, 6, 7, 8, 1},
        {7, 3, 2, 6, 8, 9, 1, 5, 4, 9},
        {1, 4, 6, 7, 2, 5, 3, 8, 9, 2},
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 1}
    };
    
    int dist[ROW][COL], visited[ROW][COL], parent[ROW][COL];
    for(int i = 0; i < ROW; i++) {   // Initializing the distance, visited and parent arrays
        for(int j = 0; j < COL; j++) {
            dist[i][j] = INF;
            visited[i][j] = 0;
            parent[i][j] = -1;
        }
    }
    dist[startX][startY] = 0;   // Setting the distance of the starting point to 0
    
    findShortestPath(graph, dist, visited, parent, startX, startY, endX, endY, 0); // Finding the shortest path
    
    int shortestPathLength = 0;
    int currentX = endX, currentY = endY;
    shortestPath[shortestPathLength][0] = endX*COL + endY;
    shortestPath[shortestPathLength][1] = 0;
    while(parent[currentX][currentY] != -1) { // Storing the shortest path in the shortestPath array
        shortestPathLength++;
        int parentX = parent[currentX][currentY] / COL;
        int parentY = parent[currentX][currentY] % COL;
        shortestPath[shortestPathLength][0] = parentX*COL + parentY;
        shortestPath[shortestPathLength][1] = dist[parentX][parentY];
        currentX = parentX;
        currentY = parentY;
    }
    shortestPathLength++;
    shortestPath[shortestPathLength][0] = startX*COL + startY;
    shortestPath[shortestPathLength][1] = dist[startX][startY];
    
    for(int i = shortestPathLength; i > 0; i--) { // Printing the shortest path
        printf("(%d, %d) -> ", shortestPath[i][0] / COL, shortestPath[i][0] % COL);
    }
    printf("(%d, %d)\n", endX, endY);
    
    return 0;
}