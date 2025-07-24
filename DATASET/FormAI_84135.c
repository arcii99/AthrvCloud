//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAP_SIZE 20

// Define a structure to hold a point in the map
typedef struct point {
    int x;
    int y;
} Point;

// Define a structure to hold a player's position and path
typedef struct player {
    Point position;
    Point path[MAP_SIZE*MAP_SIZE];
    int path_length;
} Player;

// Declare the map as a 2D array of integers
int map[MAP_SIZE][MAP_SIZE];

// Declare the player array and the number of players
Player players[2];
int num_players = 2;

// The main function
int main() {
    // Initialize the map to all zeros (no obstacles)
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0;
        }
    }

    // Set some obstacles in the map
    map[4][4] = 1;
    map[4][5] = 1;
    map[4][6] = 1;
    map[4][7] = 1;

    // Initialize the players' positions and paths
    players[0].position.x = 0;
    players[0].position.y = 0;
    players[1].position.x = MAP_SIZE-1;
    players[1].position.y = MAP_SIZE-1;

    for (int i = 0; i < num_players; i++) {
        // Use the A* pathfinding algorithm to find a path from the player's position to the goal
        Point start = players[i].position;
        Point goal;
        if (i == 0) {
            goal.x = MAP_SIZE-1;
            goal.y = MAP_SIZE-1;
        } else {
            goal.x = 0;
            goal.y = 0;
        }

        // Initialize the open and closed sets
        Point open_set[MAP_SIZE*MAP_SIZE];
        int open_set_length = 0;
        bool closed_set[MAP_SIZE][MAP_SIZE];
        for (int j = 0; j < MAP_SIZE; j++) {
            for (int k = 0; k < MAP_SIZE; k++) {
                closed_set[j][k] = false;
            }
        }

        // Add the starting point to the open set
        open_set[open_set_length++] = start;

        // Initialize the g and f scores for each point
        int g_score[MAP_SIZE][MAP_SIZE];
        int f_score[MAP_SIZE][MAP_SIZE];
        for (int j = 0; j < MAP_SIZE; j++) {
            for (int k = 0; k < MAP_SIZE; k++) {
                g_score[j][k] = MAP_SIZE*MAP_SIZE;
                f_score[j][k] = MAP_SIZE*MAP_SIZE;
            }
        }
        g_score[start.x][start.y] = 0;
        f_score[start.x][start.y] = heuristic(start, goal);

        // The A* algorithm loop
        while (open_set_length > 0) {
            // Find the point in the open set with the lowest f score
            int lowest_f_score_index = 0;
            for (int j = 0; j < open_set_length; j++) {
                if (f_score[open_set[j].x][open_set[j].y] < f_score[open_set[lowest_f_score_index].x][open_set[lowest_f_score_index].y]) {
                    lowest_f_score_index = j;
                }
            }
            Point current = open_set[lowest_f_score_index];

            // If we have reached the goal, reconstruct the path and store it in the player's path variable
            if (current.x == goal.x && current.y == goal.y) {
                players[i].path[players[i].path_length++] = current;
                Point parent = current;
                while (parent.x != start.x || parent.y != start.y) {
                    for (int j = 0; j < players[i].path_length; j++) {
                        if (players[i].path[j].x == parent.x && players[i].path[j].y == parent.y) {
                            parent = players[i].path[j-1];
                            players[i].path[players[i].path_length++] = parent;
                            break;
                        }
                    }
                }
                break;
            }

            // Remove the current point from the open set and add it to the closed set
            open_set[lowest_f_score_index] = open_set[--open_set_length];
            closed_set[current.x][current.y] = true;

            // Loop through the current point's neighbors
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (j == 0 && k == 0) {
                        continue;
                    }
                    int neighbor_x = current.x + j;
                    int neighbor_y = current.y + k;
                    if (neighbor_x < 0 || neighbor_x >= MAP_SIZE || neighbor_y < 0 || neighbor_y >= MAP_SIZE || map[neighbor_x][neighbor_y] == 1 || closed_set[neighbor_x][neighbor_y]) {
                        continue;
                    }
                    int tentative_g_score = g_score[current.x][current.y] + 1;
                    if (tentative_g_score >= g_score[neighbor_x][neighbor_y]) {
                        continue;
                    }
                    players[i].path[players[i].path_length++] = current;
                    g_score[neighbor_x][neighbor_y] = tentative_g_score;
                    f_score[neighbor_x][neighbor_y] = tentative_g_score + heuristic((Point){neighbor_x, neighbor_y}, goal);
                    bool in_open_set = false;
                    for (int l = 0; l < open_set_length; l++) {
                        if (open_set[l].x == neighbor_x && open_set[l].y == neighbor_y) {
                            in_open_set = true;
                            break;
                        }
                    }
                    if (!in_open_set) {
                        open_set[open_set_length++] = (Point){neighbor_x, neighbor_y};
                    }
                }
            }
        }
    }

    // Print the path for each player
    for (int i = 0; i < num_players; i++) {
        printf("Player %d's path:\n", i);
        for (int j = players[i].path_length-1; j >= 0; j--) {
            printf("(%d, %d)\n", players[i].path[j].x, players[i].path[j].y);
        }
    }

    return 0;
}

// The heuristic function calculates the Manhattan distance between two points
int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}