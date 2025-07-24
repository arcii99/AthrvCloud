//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct{
    int x;
    int y;
} Point;

Point goal = {9, 9};

// Calculate the Manhattan distance between two points
float manhattan_distance(Point a, Point b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Implementation of the A* algorithm
void a_star(int map[ROWS][COLS], Point start){
    Point current = start;
    float f_score = manhattan_distance(current, goal);
    float g_score = 0;
    float h_score = f_score;

    while(current.x != goal.x || current.y != goal.y){
        printf("Current Position: (%d, %d) \n", current.x, current.y);

        // Test each adjacent tile for movement
        Point adjacent[4] = {{current.x - 1, current.y}, {current.x + 1, current.y}, {current.x, current.y - 1}, {current.x, current.y + 1}};

        // Loop over the adjacent tiles
        for(int i = 0; i < 4; i++){
            Point neighbor = adjacent[i];

            // Check if the neighbor is a valid position on the map
            if(neighbor.x < 0 || neighbor.y < 0 || neighbor.x >= ROWS || neighbor.y >= COLS){
                continue;
            }

            if(map[neighbor.x][neighbor.y] != 0){
                continue;
            }

            float neighbor_g_score = g_score + 1;
            float neighbor_h_score = manhattan_distance(neighbor, goal);
            float neighbor_f_score = neighbor_g_score + neighbor_h_score;

            printf("Tile: (%d, %d), f-score: %.1f, g-score: %.1f, h-score: %.1f\n", neighbor.x, neighbor.y, neighbor_f_score, neighbor_g_score, neighbor_h_score);

            if(neighbor_f_score < f_score){
                current = neighbor;
                f_score = neighbor_f_score;
                g_score = neighbor_g_score;
                h_score = neighbor_h_score;
                break;
            }
        }
    }
}

int main(){
    int map[ROWS][COLS] = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    };
    Point start = {0, 0};
    a_star(map, start);
    return 0;
}