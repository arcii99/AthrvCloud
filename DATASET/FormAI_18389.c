//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define N 10 // Size of grid
#define p 0.5 // Probability of site being open

int main() {
    int i, j, x, y, count=0, open_sites=0;
    int site[N][N];
    int neighbor[N][N][4];
    double random;

    // Initializing the site array
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            site[i][j] = 0;
        }
    }

    // Initializing the neighbor array
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(i==0) {
                neighbor[i][j][0] = -1; // Left neighbor
            }
            else {
                neighbor[i][j][0] = i-1;
            }
            if(j==N-1) {
                neighbor[i][j][1] = -1; // Top neighbor
            }
            else {
                neighbor[i][j][1] = j+1;
            }
            if(i==N-1) {
                neighbor[i][j][2] = -1; // Right neighbor
            }
            else {
                neighbor[i][j][2] = i+1;
            }
            if(j==0) {
                neighbor[i][j][3] = -1; // Bottom neighbor
            }
            else {
                neighbor[i][j][3] = j-1;
            }
        }
    }

    // Opening the sites with probability p
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            random = (double) rand() / (RAND_MAX);
            if(random < p) {
                site[i][j] = 1;
                open_sites++;
            }  
        }
    }

    // Checking if top and bottom are connected
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(site[i][j] == 1) {
                count++;
                for(x=0; x<4; x++) {
                    if(neighbor[i][j][x] != -1 && site[neighbor[i][j][x]][j] == 1) {
                        // If the neighbor is open, connect the sites
                        site[neighbor[i][j][x]][j] = 2;
                    }
                    if(site[0][j] == 2 && site[N-1][j] == 2) {
                        // If top and bottom are connected, print the grid and exit
                        printf("Grid Connected!\n\n");
                        for(x=0; x<N; x++) {
                            for(y=0; y<N; y++) {
                                if(site[x][y] == 0) {
                                    printf("  ");
                                }
                                else if(site[x][y] == 1) {
                                    printf(". ");
                                }
                                else {
                                    printf("# ");
                                }
                            }
                            printf("\n");
                        }
                        return 0;
                    }
                }
            }
        }
    }

    // If top and bottom are not connected, print the grid and exit
    printf("Grid Not Connected!\n\n");
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(site[i][j] == 0) {
                printf("  ");
            }
            else if(site[i][j] == 1) {
                printf(". ");
            }
            else {
                printf("# ");
            }
        }
        printf("\n");
    }

    return 0;
}