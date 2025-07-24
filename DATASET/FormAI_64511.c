//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: expert-level
// This program calculates the area of a polygon using the Shoelace Formula
// The program assumes that the input is a convex polygon given in counter-clockwise order
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the area of the polygon
double computeArea(double x[], double y[], int n) {
    double area = 0.0;
    int i;
    for (i = 0; i < n - 1; i++) {
        area += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
    }
    area += (x[n - 1] * y[0]) - (x[0] * y[n - 1]);
    return fabs(area) / 2.0;
}

// Function to read the coordinates of the polygon vertices from a file
void readInput(double x[], double y[], int n) {
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }
    int i;
    for (i = 0; i < n; i++) {
        fscanf(fp, "%lf %lf", &x[i], &y[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &n);
    double *x, *y;
    x = (double *) malloc(n * sizeof(double));
    y = (double *) malloc(n * sizeof(double));
    readInput(x, y, n);
    double area = computeArea(x, y, n);
    printf("The area of the polygon is %lf square units\n", area);
    free(x);
    free(y);
    return 0;
}