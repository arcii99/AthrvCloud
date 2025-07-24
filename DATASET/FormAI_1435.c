//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include<stdio.h>

//Define the maze
int maze[5][5] = {
    {1, 1, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 1, 1}
};

int pos[2] = {0, 0}; //Starting position
int end[2] = {4, 4}; //End position
int visited[5][5] = {0}; //Visited array to keep track of where we've been

void printPath(int path[][5]){
    //Prints the path found through the maze
    printf("The path found through the maze is: ");
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(path[i][j] == 1){
                printf("(%d, %d) --> ", i, j);
            }
        }
    }
    printf("End\n");
}

void findPath(int curr_pos[], int path[][5]){
    //Base case: if we've reached the end
    if(curr_pos[0] == end[0] && curr_pos[1] == end[1]){
        printPath(path);
        return;
    }

    //Mark current position as visited
    visited[curr_pos[0]][curr_pos[1]] = 1;

    //Move right
    if(curr_pos[1] < 4 && maze[curr_pos[0]][curr_pos[1]+1] == 1 && visited[curr_pos[0]][curr_pos[1]+1] == 0){
        path[curr_pos[0]][curr_pos[1]+1] = 1;
        int new_pos[] = {curr_pos[0], curr_pos[1]+1};
        findPath(new_pos, path);
        path[curr_pos[0]][curr_pos[1]+1] = 0; //Reset path
    }

    //Move down
    if(curr_pos[0] < 4 && maze[curr_pos[0]+1][curr_pos[1]] == 1 && visited[curr_pos[0]+1][curr_pos[1]] == 0){
        path[curr_pos[0]+1][curr_pos[1]] = 1;
        int new_pos[] = {curr_pos[0]+1, curr_pos[1]};
        findPath(new_pos, path);
        path[curr_pos[0]+1][curr_pos[1]] = 0; //Reset path
    }

    //Move left
    if(curr_pos[1] > 0 && maze[curr_pos[0]][curr_pos[1]-1] == 1 && visited[curr_pos[0]][curr_pos[1]-1] == 0){
        path[curr_pos[0]][curr_pos[1]-1] = 1;
        int new_pos[] = {curr_pos[0], curr_pos[1]-1};
        findPath(new_pos, path);
        path[curr_pos[0]][curr_pos[1]-1] = 0; //Reset path
    }

    //Move up
    if(curr_pos[0] > 0 && maze[curr_pos[0]-1][curr_pos[1]] == 1 && visited[curr_pos[0]-1][curr_pos[1]] == 0){
        path[curr_pos[0]-1][curr_pos[1]] = 1;
        int new_pos[] = {curr_pos[0]-1, curr_pos[1]};
        findPath(new_pos, path);
        path[curr_pos[0]-1][curr_pos[1]] = 0; //Reset path
    }

    //Mark current position as unvisited
    visited[curr_pos[0]][curr_pos[1]] = 0;
}

int main(){
    int path[5][5] = {0}; //Initialize path to all zeros

    //Mark starting position as visited
    visited[pos[0]][pos[1]] = 1;

    //Mark starting position in path
    path[pos[0]][pos[1]] = 1;

    printf("Finding path in maze...\n");
    findPath(pos, path);
    return 0;
}