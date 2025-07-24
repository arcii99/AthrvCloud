//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_COLORS 10

int count = 0;

int graph[][10] = {
    {0,1,0,1,1,0,0,0,0,0},
    {1,0,1,0,0,1,0,0,0,0},
    {0,1,0,1,0,0,1,0,0,0},
    {1,0,1,0,1,0,0,1,0,0},
    {1,0,0,1,0,1,0,0,1,0},
    {0,1,0,0,1,0,1,0,0,1},
    {0,0,1,0,0,1,0,1,0,0},
    {0,0,0,1,0,0,1,0,1,0},
    {0,0,0,0,1,0,0,1,0,1},
    {0,0,0,0,0,1,0,0,1,0}
};

void print_colors(int colors[], int n) {
    printf("Possible coloring for the graph is : \n");
    for (int i=0; i<n; i++) {
        printf(" %d ", colors[i]);
    }
    printf("\n");
}

bool is_safe(int v, int colors[], int c, int n) {
    for(int i=0;i<n;i++) {
        if(graph[v][i] == 1 && colors[i] == c)
            return false; // color c is already assigned to a neighbor 
    }
    return true;
}

bool graph_color(int colors[], int v, int n) {
    if(v == n) {
        count++;
        print_colors(colors, n);
        return true;
    }
    for(int c=1;c<=MAX_COLORS;c++) {
        if(is_safe(v, colors, c, n)) {
            colors[v] = c;

            if(graph_color(colors, v+1, n) == true) {
                return true;
            }

            colors[v] = 0; // backtrack and unassign the color
        }
    }
    return false;
}

int main() {
    int n = 10; 
    int colors[n];

    for(int i=0; i<n; i++) {
        colors[i] = 0; // Initializing with 0
    }

    if(graph_color(colors, 0, n) == false) {
        printf("No possible coloring for the given graph\n");
    } else {
        printf("Total Possible colorings : %d\n", count);
    }
    return 0;
}