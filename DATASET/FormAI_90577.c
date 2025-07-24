//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// function to find the slope of a line given two points
float slope(int x1, int y1, int x2, int y2) {
    if(x2 == x1) {
        printf("Line is vertical, unable to calculate slope\n");
        exit(0);
    }
    return (float)(y2-y1)/(x2-x1);
}

// function to find the y-intercept of a line given two points and the slope of the line
float y_intercept(int x1, int y1, float m) {
    return (float)y1 - (m*x1);
}

// function to find distance between two points
float distance(int x1, int y1, int x2, int y2) {
    return (float)sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

int main() {
    int x1, y1, x2, y2;
    printf("Enter the coordinates of first point (x1, y1): ");
    scanf("%d %d",&x1,&y1);
    printf("Enter the coordinates of second point (x2, y2): ");
    scanf("%d %d",&x2,&y2);

    printf("\nSlope of the line passing through (%d, %d) and (%d, %d) is %.2f\n",x1,y1,x2,y2,slope(x1,y1,x2,y2));
    printf("Y-intercept of the line is %.2f\n\n",y_intercept(x1,y1,slope(x1,y1,x2,y2)));
    printf("Distance between the two points is %.2f\n",distance(x1,y1,x2,y2));

    return 0;
}