//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

struct point {
    int x;
    int y;
};

struct line {
    struct point p1;
    struct point p2;
};

float distance(struct point p1, struct point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

float perimeter(struct line l1, struct line l2, struct line l3) {
    float p1 = distance(l1.p1, l1.p2);
    float p2 = distance(l2.p1, l2.p2);
    float p3 = distance(l3.p1, l3.p2);
    return p1 + p2 + p3;
}

float area(struct line l1, struct line l2, struct line l3) {
    float p = perimeter(l1, l2, l3) / 2;
    float a = distance(l1.p1, l1.p2);
    float b = distance(l2.p1, l2.p2);
    float c = distance(l3.p1, l3.p2);
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

float angle_between_vectors(struct point p1, struct point p2) {
    float dot_product = p1.x * p2.x + p1.y * p2.y;
    float p1_len = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
    float p2_len = sqrt(pow(p2.x, 2) + pow(p2.y, 2));
    return acos(dot_product / (p1_len * p2_len)) * (180 / PI);
}

int main() {
    struct point p1 = {3, 4};
    struct point p2 = {5, 2};
    struct point p3 = {4, 6};

    struct line l1 = {p1, p2};
    struct line l2 = {p2, p3};
    struct line l3 = {p3, p1};

    float perim = perimeter(l1, l2, l3);
    printf("Perimeter of triangle: %f\n", perim);

    float tri_area = area(l1, l2, l3);
    printf("Area of triangle: %f\n", tri_area);

    struct point vec1 = {p2.x - p1.x, p2.y - p1.y};
    struct point vec2 = {p3.x - p1.x, p3.y - p1.y};
    float angle = angle_between_vectors(vec1, vec2);
    printf("Angle between vectors: %f\n", angle);

    return 0;
}