//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} Point;

typedef struct segment {
    Point start;
    Point end;
} Segment;

double euclidean_distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double segment_length(Segment s) {
    return euclidean_distance(s.start, s.end);
}

double angle(Segment a, Segment b) {
    double dot_product = (a.end.x - a.start.x) * (b.end.x - b.start.x) + (a.end.y - a.start.y) * (b.end.y - b.start.y);
    double mag_a = euclidean_distance(a.start, a.end);
    double mag_b = euclidean_distance(b.start, b.end);
    return acos(dot_product / (mag_a * mag_b));
}

int main() {
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Segment s1 = {p1, p2};
    printf("Length of segment s1: %f\n", segment_length(s1));
    
    Point p3 = {5, 6};
    Point p4 = {7, 8};
    Segment s2 = {p3, p4};
    printf("Angle between s1 and s2: %f radians\n", angle(s1, s2));
    
    return 0;
}