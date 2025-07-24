//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

// Function to generate fractal using chaos game algorithm
void chaos_game(int num_points, int max_iterations, double ratio, int vertices[][2])
{
    int x = rand() % 640; // set x to random value between 0 and 640
    int y = rand() % 480; // set y to random value between 0 and 480
    int i = 0;
    double dist;

    FILE *fp;
    fp = fopen("fractal.txt", "w");

    while (i < max_iterations)
    {
        int v = rand() % num_points; // choose a random vertex
        int vx = vertices[v][0];
        int vy = vertices[v][1];
        dist = distance(x, y, vx, vy);

        // calculate new point
        x = ratio * (vx - x) + x;
        y = ratio * (vy - y) + y;

        // write new point to file
        fprintf(fp, "%d %d\n", x, y);

        i++;
    }

    fclose(fp);
}

int main()
{
    int num_points = 3; // number of vertices
    int max_iterations = 100000; // max number of iterations
    double ratio = 0.5; // ratio between old and new points

    int vertices[3][2] = {{100, 100}, {540, 100}, {320, 480}}; // vertices of triangle

    srand(time(NULL)); // seed random number generator

    chaos_game(num_points, max_iterations, ratio, vertices);

    return 0;
}