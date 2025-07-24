//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20 //Size of the grid

int stack[N*N][2], top = -1; //Stack for DFS and its top
int grid[N][N], visited[N][N] = {0}; //Grid to simulate percolation and the array to track visited nodes
int components = 0; //Number of components in the grid
int count = 0; //Total number of nodes visited during percolation

void push(int x, int y){
    top++;
    stack[top][0] = x;
    stack[top][1] = y;
}

void pop(){
    top--;
}

int isFull(int x, int y){
    //A node is full, if it is connected to the top row of the grid
    if(visited[x][y] == 1 && x == 0){
        return 1;
    }
    return 0;
}

void DFS(){
    while(top != -1){
        int x = stack[top][0];
        int y = stack[top][1];
        pop();

        if(visited[x][y] == 1){
            continue;
        }

        visited[x][y] = 1;
        count++;

        //Checking if the adjacent nodes are open or not
        if(x > 0 && grid[x-1][y] == 1){
            push(x-1, y);
        }
        if(x < N-1 && grid[x+1][y] == 1){
            push(x+1, y);
        }
        if(y > 0 && grid[x][y-1] == 1){
            push(x, y-1);
        }
        if(y < N-1 && grid[x][y+1] == 1){
            push(x, y+1);
        }
    }
}

int main(){
    srand(time(0)); //Seeding the random number generator with current time
    
    //Initializing the grid with random nodes
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            float r = (float) rand()/(float) RAND_MAX;
            if(r < 0.5){
                grid[i][j] = 0; //Node is blocked
            }
            else{
                grid[i][j] = 1; //Node is open
            }
        }
    }

    //Printing the initial grid
    printf("Initial Grid:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    //Performing percolation
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0 && grid[i][j] == 1){ //If node is not already visited and is open
                components++; //New component found
                push(i, j); //Adding node to stack for DFS
                DFS(); //Performing DFS on this component

                if(isFull(i, j)){ //If the component is full
                    printf("\nPercolation achieved after visiting %d nodes!\n", count);
                    printf("Final Grid:\n");

                    //Printing the final grid with all connected nodes labeled as '@'
                    for(int k=0; k<N; k++){
                        for(int l=0; l<N; l++){
                            if(visited[k][l] == 1){
                                printf("@ ");
                            }
                            else{
                                printf("%d ", grid[k][l]);
                            }
                        }
                        printf("\n");
                    }
                    return 0;
                }
            }
        }
    }

    //Printing the final grid if percolation is not achieved
    printf("\nPercolation not achieved!\nFinal Grid:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 1){
                printf("@ ");
            }
            else{
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}