//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>

// Define a struct for storing information about a point in 3D space
typedef struct Point_3D {
    float x;
    float y;
    float z;
} Point_3D;

// Define a function to calculate the Euclidean distance between two points in 3D space
float euclidean_distance(Point_3D p1, Point_3D p2) {
    float delta_x = p2.x - p1.x;
    float delta_y = p2.y - p1.y;
    float delta_z = p2.z - p1.z;
    return sqrt(delta_x*delta_x + delta_y*delta_y + delta_z*delta_z);
}

// Define a function to read in a point from the user
Point_3D read_point() {
    Point_3D p;
    printf("Enter the x coordinate: ");
    scanf("%f", &p.x);
    printf("Enter the y coordinate: ");
    scanf("%f", &p.y);
    printf("Enter the z coordinate: ");
    scanf("%f", &p.z);
    return p;
}

int main() {
    printf("Welcome to the 3D space calculator!\n");

    // Read in two points from the user
    Point_3D p1 = read_point();
    Point_3D p2 = read_point();

    // Calculate and display the Euclidean distance between the two points
    float dist = euclidean_distance(p1, p2);
    printf("The distance between (%.2f, %.2f, %.2f) and (%.2f, %.2f, %.2f) is %.2f\n", 
           p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, dist);
    return 0;
}