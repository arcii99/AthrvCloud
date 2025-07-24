//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: grateful
// Welcome to my delightful C Percolation Simulator. 
// This program is designed to simulate the process of percolation 
// on a rectangular grid of sites. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 10; // size of grid
    float p = 0.6; // probability of site being open
    int site[n][n]; // matrix to represent grid
    srand(time(NULL));

    // initialize all sites to be closed (0)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            site[i][j] = 0;
        }
    }

    // randomly open sites based on probability
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            float r = (float)rand()/(float)RAND_MAX;
            if(r < p) {
                site[i][j] = 1;
            }
        }
    }

    // print out resulting grid
    printf("The resulting grid is:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", site[i][j]);
        }
        printf("\n");
    }

    // check if a path can be formed from top to bottom
    int top[n], bottom[n], count = 0;
    for(int i = 0; i < n; i++) {
        if(site[0][i] == 1) {
            top[count] = i;
            count++;
        }
        if(site[n-1][i] == 1) {
            bottom[count] = i;
            count++;
        }
    }

    int connected = 0;
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count; j++) {
            if(top[i] == bottom[j]) {
                connected = 1;
                break;
            }
        }
    }

    if(connected == 1) {
        printf("The grid percolates!\n");
    }
    else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}