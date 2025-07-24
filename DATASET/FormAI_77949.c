//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
//This unique pathfinding algorithm program is inspired by Ada Lovelace's pioneering work in computer programming.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ROW 5
#define COL 5

//Struct to represent a point
struct Point {
    int x,y;
};

//Function to check if a given point is valid or not
bool isValid(int row,int col,int maze[][COL]){
    if(row < 0 || row >= ROW || col < 0 || col >= COL || maze[row][col] == 0){
        return false;
    }
    return true;
}

//Function to check if the given point is destination or not
bool isDestination(int row,int col,struct Point dest){
    if(row == dest.x && col == dest.y){
        return true;
    }
    return false;
}

//Function to find the shortest path from source to destination
void findShortestPath(int maze[][COL],struct Point source,struct Point dest){
    //Array to keep track of visited points
    bool visited[ROW][COL];

    //Initialize all points as not visited
    for(int i = 0;i < ROW;i++){
        for(int j = 0;j < COL;j++){
            visited[i][j] = false;
        }
    }

    //Create a queue for BFS
    struct Point queue[ROW * COL];

    //Initialize front and rear in the queue
    int front = 0, rear = 0;

    //Mark the source point as visited and enqueue it
    visited[source.x][source.y] = true;
    queue[rear++] = source;

    //Parent array to store the path
    struct Point parent[ROW][COL];

    //Initialize parent array
    for(int i = 0;i < ROW;i++){
        for(int j = 0;j < COL;j++){
            parent[i][j].x = -1;
            parent[i][j].y = -1;
        }
    }

    //BFS
    while(front < rear){
        struct Point curr = queue[front++];
        int row = curr.x;
        int col = curr.y;

        //If destination is reached, break out of loop
        if(isDestination(row,col,dest)){
            break;
        }

        //Check for all 4 adjacent points and enqueue them if they are valid
        if(isValid(row-1,col,maze) && !visited[row-1][col]){
            visited[row-1][col] = true;
            parent[row-1][col] = curr;
            queue[rear++] = (struct Point){row-1,col};
        }

        if(isValid(row+1,col,maze) && !visited[row+1][col]){
            visited[row+1][col] = true;
            parent[row+1][col] = curr;
            queue[rear++] = (struct Point){row+1,col};
        }

        if(isValid(row,col-1,maze) && !visited[row][col-1]){
            visited[row][col-1] = true;
            parent[row][col-1] = curr;
            queue[rear++] = (struct Point){row,col-1};
        }

        if(isValid(row,col+1,maze) && !visited[row][col+1]){
            visited[row][col+1] = true;
            parent[row][col+1] = curr;
            queue[rear++] = (struct Point){row,col+1};
        }
    }

    //If destination is not reachable
    if(!visited[dest.x][dest.y]){
        printf("Destination is not reachable\n");
    } else {
        //Traverse the parent array to find the path
        printf("Shortest path from source to destination is:\n");
        struct Point curr = dest;
        while(parent[curr.x][curr.y].x != -1 && parent[curr.x][curr.y].y != -1){
            printf("(%d,%d) ",curr.x,curr.y);
            curr = parent[curr.x][curr.y];
        }
        printf("(%d,%d)\n",curr.x,curr.y);
    }
}

int main(){
    int maze[ROW][COL] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };

    struct Point source = {0,0};
    struct Point dest = {4,4};

    findShortestPath(maze,source,dest);
    return 0;
}