//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include<stdio.h>
#include<math.h>

struct Point {
    int x;
    int y;
};

// Function to calculate distance between two points
double distance(struct Point a, struct Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to check if 3 points are collinear
int checkCollinear(struct Point p1, struct Point p2, struct Point p3) {
    int a = p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y);
    if(a == 0)
        return 1;
    else
        return 0;
}

int main() {
    struct Point p1 = {1, 1};
    struct Point p2 = {2, 2};
    struct Point p3 = {3, 3};
    struct Point p4 = {4, 4};

    double d = distance(p1, p3);
    printf("Distance between p1 and p3: %.2f\n", d); // Output: Distance between p1 and p3: 2.83

    if(checkCollinear(p1, p2, p3))
        printf("p1, p2 and p3 are collinear\n");
    else
        printf("p1, p2 and p3 are not collinear\n"); // Output: p1, p2 and p3 are collinear

    if(checkCollinear(p1, p2, p4))
        printf("p1, p2 and p4 are collinear\n");
    else
        printf("p1, p2 and p4 are not collinear\n"); // Output: p1, p2 and p4 are not collinear

    return 0;
}