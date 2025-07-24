//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: invasive
#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

// Function to calculate the distance between two points
float distance(struct Point p1, struct Point p2) {
    float x_diff = p2.x - p1.x;
    float y_diff = p2.y - p1.y;
    float dist = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
    return dist;
}

int main() {
    struct Point point1, point2;
    
    printf("Enter the x and y coordinates of Point 1: ");
    scanf("%d %d", &point1.x, &point1.y);
    
    printf("Enter the x and y coordinates of Point 2: ");
    scanf("%d %d", &point2.x, &point2.y);
    
    float dist = distance(point1, point2);
    
    printf("\nDistance between Point 1(%d,%d) and Point 2(%d,%d) is %.2f units", 
           point1.x, point1.y, point2.x, point2.y, dist);
           
    return 0;
}