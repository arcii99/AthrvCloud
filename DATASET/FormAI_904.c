//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int openSites[ROW][COL];
int topSite = 0;
int bottomSite = ROW * COL + 1;
int virtualTop;
int virtualBottom;
int source;
int destination;
int numOfSites = ROW * COL;
int parent[ROW * COL + 2];
int size[ROW * COL + 2];
int isOpen(int i, int j);
void percolate(int);
void connect(int, int);
int find(int);
void initUF();
void printSites();

int main() {
    virtualTop = topSite + 1;
    virtualBottom = bottomSite - 1;
    initUF();
    printSites();
    percolate(topSite);
    if (isOpen(10, 10)){
        printf("System Percolated!\n");
    } else {
        printf("System did not Percolate!\n");
    }
    return 0;
}

int isOpen(int i, int j) {
    if (openSites[i - 1][j - 1] == 1) {
        return 1;
    } else {
        return 0;
    }
}

void percolate(int site) {
    for (int j = 1; j <= COL; j++) {
        if (isOpen(1, j)) {
            connect(topSite, getIndex(1, j));
        }
        if (isOpen(ROW, j)) {
            connect(bottomSite, getIndex(ROW, j));
        }
    }
    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= COL; j++) {
            int siteIndex = getIndex(i, j);
            if (isOpen(i, j)) {
                if (i < ROW && isOpen(i + 1, j)) {
                    connect(siteIndex, getIndex(i + 1, j));
                }
                if (j < COL && isOpen(i, j + 1)) {
                    connect(siteIndex, getIndex(i, j + 1));
                }
                if (i > 1 && isOpen(i - 1, j)) {
                    connect(siteIndex, getIndex(i - 1, j));
                }
                if (j > 1 && isOpen(i, j - 1)) {
                    connect(siteIndex, getIndex(i, j - 1));
                }
            }
        }
    }
}

void connect(int site1, int site2) {
    int root1 = find(site1);
    int root2 = find(site2);
    if (root1 == root2) {
        return;
    }
    if (size[root1] < size[root2]) {
        parent[root1] = root2;
        size[root2] += size[root1];
    } else {
        parent[root2] = root1;
        size[root1] += size[root2];
    }
}

int find(int site) {
    while (site != parent[site]) {
        parent[site] = parent[parent[site]];
        site = parent[site];
    }
    return site;
}

void initUF() {
    for (int i = 1; i <= numOfSites; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    parent[topSite] = topSite;
    parent[bottomSite] = bottomSite;
    size[topSite] = 1;
    size[bottomSite] = 1;
    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= COL; j++) {
            openSites[i - 1][j - 1] = rand() % 2;
        }
    }
    printf("Randomized Sites: \n");
    printSites();
    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= COL; j++) {
            if (isOpen(i, j)) {
                int siteIndex = getIndex(i, j);
                if (i == 1) {
                    connect(topSite, siteIndex);
                }
                if (i == ROW) {
                    connect(bottomSite, siteIndex);
                }
                if (i < ROW && isOpen(i + 1, j)) {
                    connect(siteIndex, getIndex(i + 1, j));
                }
                if (j < COL && isOpen(i, j + 1)) {
                    connect(siteIndex, getIndex(i, j + 1));
                }
            }
        }
    }
    printf("Opened Sites: \n");
    printSites();
}

int getIndex(int i, int j) {
    return (i - 1) * COL + j;
}

void printSites() {
    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= COL; j++) {
            if (isOpen(i, j)) {
                printf("O ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}