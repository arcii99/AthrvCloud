//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 20

int cost[ROW][COL];
int dist[ROW][COL];
bool visited[ROW][COL];

// Function to initialize the arrays
void init_arrays() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            cost[i][j] = 1;
            dist[i][j] = ROW*COL;
            visited[i][j] = false;
        }
    }
}

// Function to print the arrays
void print_arrays() {
    printf("Cost matrix:\n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
    printf("Distance matrix:\n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    printf("Visited matrix:\n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

// Function to find the minimum distance vertex
int min_distance() {
    int min_dist = ROW*COL;
    int min_i = -1;
    int min_j = -1;
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(!visited[i][j] && dist[i][j] < min_dist) {
                min_dist = dist[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }
    return min_i*COL+min_j;
}

// Function to calculate the shortest path using Dijkstra's algorithm
void dijkstra_algorithm(int source_row, int source_col) {
    for(int i = 0; i < ROW*COL; i++) {
        int current_vertex = min_distance();
        int current_row = current_vertex/COL;
        int current_col = current_vertex%COL;
        visited[current_row][current_col] = true;
        if(current_row-1 >= 0 && !visited[current_row-1][current_col] && dist[current_row][current_col]+cost[current_row-1][current_col] < dist[current_row-1][current_col]) {
            dist[current_row-1][current_col] = dist[current_row][current_col]+cost[current_row-1][current_col];
        }
        if(current_col+1 < COL && !visited[current_row][current_col+1] && dist[current_row][current_col]+cost[current_row][current_col+1] < dist[current_row][current_col+1]) {
            dist[current_row][current_col+1] = dist[current_row][current_col]+cost[current_row][current_col+1];
        }
        if(current_row+1 < ROW && !visited[current_row+1][current_col] && dist[current_row][current_col]+cost[current_row+1][current_col] < dist[current_row+1][current_col]) {
            dist[current_row+1][current_col] = dist[current_row][current_col]+cost[current_row+1][current_col];
        }
        if(current_col-1 >= 0 && !visited[current_row][current_col-1] && dist[current_row][current_col]+cost[current_row][current_col-1] < dist[current_row][current_col-1]) {
            dist[current_row][current_col-1] = dist[current_row][current_col]+cost[current_row][current_col-1];
        }
        if(current_row == source_row && current_col == source_col) {
            return;
        }
    }
}

int main() {
    init_arrays();
    dist[0][0] = 0;
    dijkstra_algorithm(0, 0);
    print_arrays();
    return 0;
}