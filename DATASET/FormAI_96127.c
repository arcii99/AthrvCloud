//FormAI DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 10000000

// Define a set of shapes
enum Shape {
    CIRCLE,
    SQUARE,
    TRIANGLE
};

// A shape struct
typedef struct {
    enum Shape shape;
    float size;
} Shape;

// Get a random shape
Shape get_random_shape() {
    Shape s;
    s.size = (float)rand() / RAND_MAX * 100.0f;
    s.shape = rand() % 3;
    return s;
}

// Calculate the area of a circle
float circle_area(float radius) {
    return 3.14159f * radius * radius;
}

// Calculate the area of a square
float square_area(float width) {
    return width * width;
}

// Calculate the area of a triangle
float triangle_area(float base, float height) {
    return 0.5f * base * height;
}

int main() {
    // Set up random seed
    srand(time(NULL));

    // Variable to keep track of CPU time
    clock_t start, end;

    // Calculate areas using if statements
    start = clock();
    float total_area_if = 0.0f;
    for (int i = 0; i < ITERATIONS; i++) {
        Shape s = get_random_shape();
        if (s.shape == CIRCLE) {
            total_area_if += circle_area(s.size);
        } else if (s.shape == SQUARE) {
            total_area_if += square_area(s.size);
        } else if (s.shape == TRIANGLE) {
            total_area_if += triangle_area(s.size, s.size);
        }
    }
    end = clock();
    printf("(if) Total area: %f\n", total_area_if);
    printf("(if) Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calculate areas using function pointers
    start = clock();
    typedef float (*area_func_ptr)(float);
    area_func_ptr area_functions[3] = {&circle_area, &square_area, &triangle_area};
    float total_area_ptr = 0.0f;
    for (int i = 0; i < ITERATIONS; i++) {
        Shape s = get_random_shape();
        total_area_ptr += area_functions[s.shape](s.size);
    }
    end = clock();
    printf("(ptr) Total area: %f\n", total_area_ptr);
    printf("(ptr) Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calculate areas using switch statement
    start = clock();
    float total_area_switch = 0.0f;
    for (int i = 0; i < ITERATIONS; i++) {
        Shape s = get_random_shape();
        switch (s.shape) {
            case CIRCLE:
                total_area_switch += circle_area(s.size);
                break;
            case SQUARE:
                total_area_switch += square_area(s.size);
                break;
            case TRIANGLE:
                total_area_switch += triangle_area(s.size, s.size);
                break;
        }
    }
    end = clock();
    printf("(switch) Total area: %f\n", total_area_switch);
    printf("(switch) Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}