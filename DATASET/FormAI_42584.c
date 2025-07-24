//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 //size of grid

int grid[N][N]; //2D array representing the grid
int openSites = 0; //number of open sites in the grid

//function to initialize the grid
void initGrid() {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            grid[i][j] = 0; //0 represents blocked site
        }
    }
}

//function to randomly open a site in the grid
void openSite() {
    int i, j;
    do {
        i = rand() % N;
        j = rand() % N;
    } while(grid[i][j] != 0); //keep selecting a random site until it is not blocked
    grid[i][j] = 1; //1 represents open site
    openSites++;
}

//function to check if site (i, j) is open
int isOpen(int i, int j) {
    if(i < 0 || j < 0 || i >= N || j >= N) { //if site is out of bounds
        return 0; //consider it as blocked
    }
    return grid[i][j] == 1; //return 1 if site is open, else return 0
}

//function to check if site (i, j) is connected to the top row
int isFull(int i, int j) {
    if(!isOpen(i, j)) { //if site is blocked
        return 0; //consider it as not connected to the top row
    }
    if(i == 0) { //if site is in the top row
        return 1; //consider it as connected to the top row
    }
    return isFull(i-1, j) || isFull(i, j-1) || isFull(i, j+1); //recursively check if any of the neighboring sites are connected to the top row
}

//function to simulate percolation
void simulatePercolation() {
    while(1) {
        openSite(); //open a random site
        if(isFull(N-1, 0)) { //if the bottom left site is connected to the top row
            break; //percolation has occurred, exit the loop
        }
    }
}

//function to display the percolation simulation result
void displayResult() {
    int i, j;
    printf("Percolation simulation result:\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%c ", (grid[i][j] == 0) ? '#' : '.'); //'#' represents blocked site, '.' represents open site
        }
        printf("\n");
    }
    printf("Number of open sites: %d\n", openSites);
    printf("Percolates: %s\n", (isFull(N-1, 0)) ? "Yes" : "No");
}

int main() {
    srand(time(NULL)); //seed the random number generator with current time
    initGrid(); //initialize the grid
    simulatePercolation(); //simulate percolation
    displayResult(); //display the percolation simulation result
    return 0;
}