//FormAI DATASET v1.0 Category: Graph representation ; Style: medieval
/*
* Medieval Castle Graph Representation
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add_edge(int i, int j);
void create_castle();
void print_castle();

// Graph variables
#define N 10
int graph[N][N] = {0};
char castle[N][N];

void add_edge(int i, int j) {
    graph[i][j] = 1;
    graph[j][i] = 1;
}

void create_castle() {
    // build the castle walls
    for (int i = 0; i < N - 2; i++) {
        add_edge(i, i+1);
    }
    add_edge(N-1, 0);
    add_edge(N-1, N-2);

    // add a drawbridge
    add_edge(N/2-1, N/2+2);
    add_edge(N/2, N/2+2);
    add_edge(N/2+1, N/2+2);
    add_edge(N/2+2, N/2+2);

    // add a tower
    for (int i = N/2-1; i <= N/2+2; i++) {
        add_edge(N-3, i);
        add_edge(i, N-3);
    }

    // add a keep
    for (int i = N/2-2; i <= N/2+2; i++) {
        add_edge(N-5, i);
        add_edge(i, N-5);
    }
}

void print_castle() {
    // set up the castle map
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            castle[i][j] = ' ';
        }
    }
    
    // draw the walls
    for (int i = 0; i < N - 2; i++) {
        castle[i][0] = '|';
        castle[i][N-1] = '|';
    }
    for (int j = 0; j < N; j++) {
        castle[0][j] = '-';
        castle[N-3][j] = '-';
        castle[N-1][j] = '-';
    }
    for (int j = N/2-1; j <= N/2+2; j++) {
        castle[N-3][j] = '|';
    }

    // draw the drawbridge
    castle[N/2+2][N/2+2] = '_';
    for (int i = N/2-1; i <= N/2+1; i++) {
        castle[i][N/2+2] = '|';
    }

    // draw the tower
    for (int i = N/2-1; i <= N/2+2; i++) {
        castle[N-3][i] = '_';
    }
    castle[N-4][N/2-1] = '|';
    castle[N-5][N/2-1] = '|';
    castle[N-4][N/2+2] = '|';
    castle[N-5][N/2+2] = '|';

    // draw the keep
    for (int i = N/2-2; i <= N/2+2; i++) {
        castle[N-5][i] = '_';
    }
    for (int i = N/2-1; i <= N/2+1; i++) {
        castle[N-7][i] = '-';
        castle[N-6][i] = '.';
        castle[N-4][i] = '.';
        castle[N-3][i] = '-';
    }
    castle[N-5][N/2-2] = '|';
    castle[N-5][N/2+2] = '|';

    // print the castle map
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", castle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    create_castle();
    print_castle();
    return 0;
}