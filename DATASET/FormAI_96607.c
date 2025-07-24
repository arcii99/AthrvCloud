//FormAI DATASET v1.0 Category: Graph representation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void print_graph(char graph[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", graph[i][j]);
        }
        printf("\n");
    }
}

void generate_random_graph(char graph[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % 2;
            if (r == 0) {
                graph[i][j] = '-';
            } else {
                graph[i][j] = 'X';
            }
        }
    }
}

void add_lines(char graph[ROWS][COLS], int num_lines) {
    for (int k = 0; k < num_lines; k++) {
        int i1 = rand() % ROWS;
        int j1 = rand() % COLS;
        int i2 = rand() % ROWS;
        int j2 = rand() % COLS;

        while (graph[i1][j1] == 'X' || graph[i2][j2] == 'X') {
            i1 = rand() % ROWS;
            j1 = rand() % COLS;
            i2 = rand() % ROWS;
            j2 = rand() % COLS;
        }

        if (i1 == i2) {
            for (int j = j1; j <= j2; j++) {
                graph[i1][j] = 'X';
            }
        } else if (j1 == j2) {
            for (int i = i1; i <= i2; i++) {
                graph[i][j1] = 'X';
            }
        } else {
            printf("Invalid line coordinates\n");
        }
    }
}

int main() {
    srand(0xFACE113);

    char graph[ROWS][COLS];
    generate_random_graph(graph);
    print_graph(graph);
    printf("\n");

    int num_lines = 5;
    add_lines(graph, num_lines);
    print_graph(graph);
}