//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <math.h>

typedef struct {
   float x;
   float y;
} Point;

/* Calculate the distance between two points */
float distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

/* Check if three points are collinear */
int collinear(Point p1, Point p2, Point p3) { 
    float a = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
    if (a == 0) {
        return 1;
    } else { 
        return 0;
    }
}

/* Calculate the slope of a line formed by two points */
float slope(Point p1, Point p2) {
    if (p2.x == p1.x) {
        return NAN;
    } else {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }
}

int main() {
    Point p1, p2, p3;
    
    printf("Enter x and y coordinates of Point 1: ");
    scanf("%f %f", &p1.x, &p1.y);
    
    printf("Enter x and y coordinates of Point 2: ");
    scanf("%f %f", &p2.x, &p2.y);
    
    printf("Enter x and y coordinates of Point 3: ");
    scanf("%f %f", &p3.x, &p3.y);
    
    printf("Distance between Point 1 and Point 2: %.4f", distance(p1, p2));
    printf("\nDistance between Point 2 and Point 3: %.4f", distance(p2, p3));
    printf("\nDistance between Point 3 and Point 1: %.4f", distance(p3, p1));
    
    int isCollinear = collinear(p1, p2, p3);
    if (isCollinear) {
        printf("\nThe three points are collinear.");
    } else {
        printf("\nThe three points are not collinear.");
    }
    
    float m1 = slope(p1, p2);
    float m2 = slope(p2, p3);
    
    if (isnan(m1) || isnan(m2)) {
        printf("\nThe slope of the line cannot be calculated.");
    } else if (m1 == m2) {
        printf("\nThe three points lie on the same line and have the same slope."); 
    } else {
        printf("\nThe three points do not lie on the same line and have different slopes.");   
    }
    
    return 0;
}