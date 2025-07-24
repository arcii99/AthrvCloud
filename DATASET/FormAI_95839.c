//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>

struct point {
    int x;
    int y;
};

// Function to calculate the Euclidean distance between two points.
float euclidean_distance(struct point p1, struct point p2)
{
    float x_diff = p1.x - p2.x;
    float y_diff = p1.y - p2.y;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

// Function to find the area of a circle with a given radius.
float circle_area(int radius)
{
    const float pi = 3.14159;   // Define the value of Pi
    return pi * radius * radius;
}

int main()
{
    struct point p1 = {0, 0};
    struct point p2 = {3, 4};

    // Calculate the Euclidean distance between the two points.
    float distance = euclidean_distance(p1, p2);

    // Print the result.
    printf("The distance between point (%d, %d) and point (%d, %d) is %.2f\n",
           p1.x, p1.y, p2.x, p2.y, distance);
    
    // Find the area of a circle with radius 3.
    float circle_area_result = circle_area(3);

    // Print the result.
    printf("The area of a circle with radius 3 is %.2f\n", circle_area_result);

    return 0;
}