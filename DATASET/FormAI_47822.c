//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Vector;

Vector vectorAdd(Vector a, Vector b)
{
    Vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

Vector vectorSubtract(Vector a, Vector b)
{
    Vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vector vectorScale(Vector a, double scalar)
{
    Vector result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    result.z = a.z * scalar;
    return result;
}

double vectorMagnitude(Vector a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

Vector vectorNormalize(Vector a)
{
    double magnitude = vectorMagnitude(a);
    Vector result;
    result.x = a.x / magnitude;
    result.y = a.y / magnitude;
    result.z = a.z / magnitude; 
    return result;
}

Vector vectorCrossProduct(Vector a, Vector b)
{
    Vector result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

double vectorDotProduct(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector vectorProject(Vector a, Vector b)
{
    double dotProduct = vectorDotProduct(a, b);
    Vector normalizedB = vectorNormalize(b);
    Vector result = vectorScale(normalizedB, dotProduct);
    return result;
}

int main()
{
    Vector a = {1, 2, 3};
    Vector b = {4, 5, 6};
    Vector c = vectorCrossProduct(a, b);
    printf("Cross product of a and b: (%f, %f, %f)\n", c.x, c.y, c.z);
    printf("Magnitude of a: %f\n", vectorMagnitude(a));
    Vector normalizedA = vectorNormalize(a);
    printf("Normalized a: (%f, %f, %f)\n", normalizedA.x, normalizedA.y, normalizedA.z);
    Vector projectedA = vectorProject(a, b);
    printf("Projection of a onto b: (%f, %f, %f)\n", projectedA.x, projectedA.y, projectedA.z);
    return 0;
}