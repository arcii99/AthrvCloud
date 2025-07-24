//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

/* Define the data structure */
typedef struct {
    float x;
    float y;
    float z;
} Vector3D;

/* Define functions to perform operations on the Vector3D data structure */
Vector3D add(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;

    return result;
}

Vector3D subtract(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;

    return result;
}

Vector3D scalarMultiply(Vector3D v, float scalar) {
    Vector3D result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;

    return result;
}

float dotProduct(Vector3D v1, Vector3D v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector3D crossProduct(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = (v1.y * v2.z) - (v1.z * v2.y);
    result.y = (v1.z * v2.x) - (v1.x * v2.z);
    result.z = (v1.x * v2.y) - (v1.y * v2.x);

    return result;
}

float magnitude(Vector3D v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

/* Define the main function to test the Vector3D data structure and functions */
int main() {
    /* Create two vectors */
    Vector3D v1 = {1.0f, 2.0f, 3.0f};
    Vector3D v2 = {4.0f, 5.0f, 6.0f};

    /* Compute the sum of the two vectors */
    Vector3D sum = add(v1, v2);

    /* Compute the difference of the two vectors */
    Vector3D difference = subtract(v1, v2);

    /* Compute the scalar product of one vector */
    Vector3D scalarProduct = scalarMultiply(v1, 2.0f);

    /* Compute the dot product of the two vectors */
    float dot = dotProduct(v1, v2);

    /* Compute the cross product of the two vectors */
    Vector3D cross = crossProduct(v1, v2);

    /* Compute the magnitude of one vector */
    float mag = magnitude(v1);

    /* Print the results */
    printf("v1 = (%.2f, %.2f, %.2f)\n", v1.x, v1.y, v1.z);
    printf("v2 = (%.2f, %.2f, %.2f)\n", v2.x, v2.y, v2.z);
    printf("v1 + v2 = (%.2f, %.2f, %.2f)\n", sum.x, sum.y, sum.z);
    printf("v1 - v2 = (%.2f, %.2f, %.2f)\n", difference.x, difference.y, difference.z);
    printf("2 * v1 = (%.2f, %.2f, %.2f)\n", scalarProduct.x, scalarProduct.y, scalarProduct.z);
    printf("v1 . v2 = %.2f\n", dot);
    printf("v1 x v2 = (%.2f, %.2f, %.2f)\n", cross.x, cross.y, cross.z);
    printf("|v1| = %.2f\n", mag);

    return 0;
}