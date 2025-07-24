//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10  //Size of the grid
#define P 0.6 //Probability of a site being open

int grid[N][N]; //2D array to represent grid
int connected[N*N]; //1D array to store connected sites
int group_size[N*N]; //1D array to store size of each group
int current_group = 0; //Counter for current group

//Function to initialize the grid with closed sites
void initialize_grid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            grid[i][j] = 0;
        }
    }
}

//Function to randomly open sites on the grid based on probability P
void open_random_sites() {
    srand(time(NULL)); //Seed the random number generator
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            double r = (double)rand() / RAND_MAX;
            if(r < P) {
                grid[i][j] = 1;
            }
        }
    }
}

//Function to check if two sites are connected
int is_connected(int x1, int y1, int x2, int y2) {
    if(x1 == x2 && y1 == y2) { //Two identical sites are always connected
        return 1;
    }
    if(!grid[x1][y1] || !grid[x2][y2]) { //Sites that are not open cannot be connected
        return 0;
    }
    if(abs(x2-x1) + abs(y2-y1) != 1) { //Two sites must be adjacent to be connected
        return 0;
    }
    int site1 = x1*N+y1;
    int site2 = x2*N+y2;
    return connected[site1] == connected[site2]; //Check if the two sites belong to the same group
}

//Function to connect two sites
void connect(int x1, int y1, int x2, int y2) {
    if(x1 == x2 && y1 == y2) { //Two identical sites do not need to be connected
        return;
    }
    if(!grid[x1][y1] || !grid[x2][y2]) { //Sites that are not open cannot be connected
        return;
    }
    if(abs(x2-x1) + abs(y2-y1) != 1) { //Two sites must be adjacent to be connected
        return;
    }
    int site1 = x1*N+y1;
    int site2 = x2*N+y2;
    int group1 = connected[site1];
    int group2 = connected[site2];
    if(group1 == group2) { //Sites already belong to the same group
        return;
    }
    //Merge the two groups
    int new_group = current_group++;
    for(int i=0; i<N*N; i++) {
        if(connected[i] == group1 || connected[i] == group2) {
            connected[i] = new_group;
        }
    }
    group_size[new_group] = group_size[group1] + group_size[group2];
}

//Function to print the grid
void print_grid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!grid[i][j]) { //Closed site
                printf("  ");
            } else if(!group_size[connected[i*N+j]]) { //Open site that is not part of a group
                printf("* ");
            } else { //Open site that is part of a group
                printf("%d ", connected[i*N+j]);
            }
        }
        printf("\n");
    }
}

int main() {
    initialize_grid(); //Set all sites to closed
    open_random_sites(); //Open sites randomly based on probability P
    //Initialize groups
    for(int i=0; i<N*N; i++) {
        connected[i] = i;
        group_size[i] = 0;
    }
    //Connect adjacent open sites
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j]) { //Open site
                if(i > 0 && grid[i-1][j]) { //North site is open
                    connect(i,j,i-1,j);
                }
                if(j < N-1 && grid[i][j+1]) { //East site is open
                    connect(i,j,i,j+1);
                }
                if(i < N-1 && grid[i+1][j]) { //South site is open
                    connect(i,j,i+1,j);
                }
                if(j > 0 && grid[i][j-1]) { //West site is open
                    connect(i,j,i,j-1);
                }
            }
        }
    }
    printf("\n");
    print_grid();
    printf("\n");
    printf("Number of open sites: %d\n", current_group);
    printf("Largest group size: %d\n", group_size[0]);
    for(int i=1; i<current_group; i++) {
        if(group_size[i] > group_size[0]) {
            group_size[0] = group_size[i];
        }
    }
    printf("Second largest group size: %d\n", group_size[0]);
    return 0;
}