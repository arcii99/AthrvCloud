//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: romantic
#include <stdio.h>
#include <math.h>

struct Point {
    double x, y;
};

double distance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    printf("****Calculating the distance between two points****\n\n");
    
    struct Point p1, p2;
    
    printf("Enter coordinates of Point 1 (x y): ");
    scanf("%lf %lf", &p1.x, &p1.y);
    
    printf("\nEnter coordinates of Point 2 (x y): ");
    scanf("%lf %lf", &p2.x, &p2.y);
    
    double dist = distance(p1, p2);
    
    printf("\nThe distance between Point 1 and Point 2 is %.2lf\n", dist);
    printf("\nThank you for calculating it for me my love!\n");

    return 0;
}