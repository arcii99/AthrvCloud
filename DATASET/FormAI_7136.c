//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate distance between two points in a 2D plane
float distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Set up random seed
    srand(time(NULL));
    
    // Initialize variables for the dimensions of the 2D plane
    int width = 100;
    int height = 100;
    
    // Initialize an array to represent the 2D plane
    char plane[height][width];
    
    // Fill the array with random obstacles represented as 'x'
    int num_obs = 100;
    for(int i=0; i<num_obs; i++) {
        int obs_x = rand() % width;
        int obs_y = rand() % height;
        plane[obs_y][obs_x] = 'x';
    }
    
    // Initialize starting and ending coordinates for a path
    int start_x = rand() % width;
    int start_y = rand() % height;
    int end_x = rand() % width;
    int end_y = rand() % height;
    
    // Calculate the straight line distance between the start and end points
    float straight_dist = distance(start_x, start_y, end_x, end_y);
    
    // Use a simple algorithm to find the optimal path through the obstacles
    char path = '.';
    float min_dist = straight_dist;
    int curr_x = start_x;
    int curr_y = start_y;
    
    while(min_dist > 0.0) {
        // Calculate distances to all nearby points
        float dists[3][3];
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                int x = curr_x + i;
                int y = curr_y + j;
                if(x >= 0 && x < width && y >= 0 && y < height) {
                    float dist = distance(x, y, end_x, end_y);
                    if(plane[y][x] != 'x' && dist < min_dist) {
                        dists[i+1][j+1] = dist;
                    } else {
                        dists[i+1][j+1] = INFINITY;
                    }
                } else {
                    dists[i+1][j+1] = INFINITY;
                }
            }
        }
        
        // Find the minimum distance and move to that point
        int min_i, min_j;
        float min_val = INFINITY;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(dists[i][j] < min_val) {
                    min_i = i;
                    min_j = j;
                    min_val = dists[i][j];
                }
            }
        }
        curr_x += min_i-1;
        curr_y += min_j-1;
        
        // Update the minimum distance and draw the path
        min_dist = distance(curr_x, curr_y, end_x, end_y);
        if(plane[curr_y][curr_x] != 'x') {
            plane[curr_y][curr_x] = path;
        }
    }
    
    // Print the final path on the 2D plane
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%c ", plane[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}