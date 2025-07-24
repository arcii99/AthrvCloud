//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>

// Define a structure to represent a 3D point
struct Point {
    float x, y, z;
};

// Define a structure to represent a 3D vector
struct Vector {
    float x, y, z;
};

// Define a structure to represent a 3D matrix
struct Matrix {
    float m11, m12, m13;
    float m21, m22, m23;
    float m31, m32, m33;
};

// Function to print a Point structure
void printPoint(struct Point p) {
    printf("(%f, %f, %f)\n", p.x, p.y, p.z);
}

// Function to print a Vector structure
void printVector(struct Vector v) {
    printf("<%f, %f, %f>\n", v.x, v.y, v.z);
}

// Function to print a Matrix structure
void printMatrix(struct Matrix m) {
    printf("[[%f, %f, %f]\n", m.m11, m.m12, m.m13);
    printf(" [%f, %f, %f]\n", m.m21, m.m22, m.m23);
    printf(" [%f, %f, %f]]\n", m.m31, m.m32, m.m33);
}

int main() {
    // Create a Point structure and initialize it
    struct Point p = {1.0, 2.0, 3.0};
    printPoint(p);

    // Create a Vector structure and initialize it
    struct Vector v = {4.0, 5.0, 6.0};
    printVector(v);

    // Create a Matrix structure and initialize it
    struct Matrix m = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    printMatrix(m);

    return 0;
}