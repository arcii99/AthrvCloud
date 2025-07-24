//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
// Asynchronous C Geometric Algorithms Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Define a point struct
typedef struct {
    float x;
    float y;
} Point;

// Define a square struct with a center point and side length
typedef struct {
    Point center;
    float side_length;
} Square;

// A synchronous function to check if a point is inside a square
int point_inside_square(Point p, Square s) {
    float half_side_length = s.side_length / 2.0;
    float x_diff = abs(p.x - s.center.x);
    float y_diff = abs(p.y - s.center.y);
    return (x_diff <= half_side_length) && (y_diff <= half_side_length);
}

// An asynchronous function to generate random points and check if they are inside a square
void* check_points(void* square_ptr) {
    Square* s = (Square*) square_ptr;
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < 10; i++) { // Check 10 points asynchronously
        Point p = {rand() % 10 + 1, rand() % 10 + 1}; // Generate random point
        printf("Checking point (%.2f, %.2f)...\n", p.x, p.y);
        if (point_inside_square(p, *s)) {
            printf("Point is inside the square!\n");
        } else {
            printf("Point is not inside the square.\n");
        }
        sleep(1); // Wait 1 second before checking the next point
    }
    pthread_exit(NULL); // End thread execution
}

int main() {
    Square s = {{5, 5}, 5}; // Create square with center at (5, 5) and side length 5

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, check_points, &s); // Create a new thread to check points asynchronously

    printf("Square center: (%.2f, %.2f)\n", s.center.x, s.center.y);
    printf("Square side length: %.2f\n", s.side_length);
    pthread_join(thread_id, NULL); // Wait for thread to finish
    printf("Finished checking points.\n");

    return 0;
}