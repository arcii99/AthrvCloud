//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* STRUCTURE DECLARATION */
typedef struct site {
    int row;
    int col;
    int status;
    struct site* parent;
} Site;

/* FUNCTION DECLARATION */
int connected(Site* s1, Site* s2);
Site* findRoot(Site* s);
void unite(Site* s1, Site* s2);
void generateRandomPath(int rows, int cols, Site* path[]);
void percolate(int rows, int cols, int percolationThreshold);

/* MAIN FUNCTION */
int main() {
    /* SET UP */
    srand((unsigned int) time(NULL)); // set seed for random number generation
    int rows, cols, percolationThreshold;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("Enter percolation threshold (0-100): ");
    scanf("%d", &percolationThreshold);

    /* PERCOLATE */
    percolate(rows, cols, percolationThreshold);
}

/* FUNCTION DEFINITIONS */

// check if two sites are connected
int connected(Site* s1, Site* s2) {
    return (findRoot(s1) == findRoot(s2));
}

// find root of a site
Site* findRoot(Site* s) {
    if (s->parent == s) {
        return s;
    }
    s->parent = findRoot(s->parent); // path compression
    return s->parent;
}

// unite two sites
void unite(Site* s1, Site* s2) {
    Site* root1 = findRoot(s1);
    Site* root2 = findRoot(s2);
    if (root1 == root2) {
        return;
    }
    root1->parent = root2;
}

// generate a random path through the grid
void generateRandomPath(int rows, int cols, Site* path[]) {
    // starting site
    int startRow = rows;
    int startCol = rand() % cols;
    Site* currentSite = path[0] = (Site*) malloc(sizeof(Site));
    currentSite->row = startRow;
    currentSite->col = startCol;
    currentSite->status = 1;
    currentSite->parent = currentSite;

    // randomly pick next site to add to path
    for (int i = 1; i < cols; i++) {
        currentSite = path[i] = (Site*) malloc(sizeof(Site));
        currentSite->row = rows - i;
        int possibleNextCols[2];
        int numPossibleNextCols = 0;
        if (startCol > 0) {
            possibleNextCols[numPossibleNextCols++] = startCol - 1;
        }
        if (startCol < cols - 1) {
            possibleNextCols[numPossibleNextCols++] = startCol + 1;
        }
        int nextCol = possibleNextCols[rand() % numPossibleNextCols];
        startCol = currentSite->col = nextCol;
        currentSite->status = 1;
        currentSite->parent = currentSite;
    }
}

// percolate through the grid
void percolate(int rows, int cols, int percolationThreshold) {
    Site* grid[rows][cols]; // 2D array of sites
    Site* topSites[cols]; // array of top row sites
    Site* bottomSites[cols]; // array of bottom row sites
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            grid[row][col] = (Site*) malloc(sizeof(Site));
            grid[row][col]->row = row;
            grid[row][col]->col = col;
            grid[row][col]->status = 0;
            grid[row][col]->parent = grid[row][col];
        }
    }
    int numOpen = 0;
    while (1) {
        // generate random path through grid
        Site* path[cols];
        generateRandomPath(rows, cols, path);

        // open sites and check if matrix percolated
        for (int i = 0; i < cols; i++) {
            if (!path[i]->status) {
                path[i]->status = 1;
                numOpen++;
                if (path[i]->row == 0) {
                    topSites[i] = path[i];
                }
                if (path[i]->row == rows - 1) {
                    bottomSites[i] = path[i];
                }
                if (numOpen >= rows * cols * percolationThreshold / 100) {
                    // check if top and bottom rows are connected
                    int topBottomConnected = 0;
                    for (int i = 0; i < cols; i++) {
                        if (topSites[i] && bottomSites[i] && connected(topSites[i], bottomSites[i])) {
                            topBottomConnected = 1;
                            break;
                        }
                    }
                    if (topBottomConnected) {
                        printf("Matrix percolated with percolation threshold %d%%\n", percolationThreshold);
                        return;
                    } else {
                        printf("Matrix did not percolate with percolation threshold %d%%\n", percolationThreshold);
                        return;
                    }
                }
            }
        }

        // unite adjacent open sites in the path
        for (int i = 1; i < cols; i++) {
            if (path[i]->status) {
                if (path[i - 1]->status) {
                    unite(path[i], path[i - 1]);
                }
            }
        }
    }
}