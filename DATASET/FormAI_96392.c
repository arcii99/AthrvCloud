//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates of the three points (x1,y1), (x2,y2) and (x3,y3):\n");
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

    int area = abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2);
    printf("Area of triangle formed by the given coordinates is: %d \n", area);

    int c = ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
    if (c == 0) {
        printf("The given points are collinear. \n");
    } else {
        printf("The given points are not collinear. \n");
    }

    int maxX = x1, maxY = y1, minX = x1, minY = y1;
    if (x2 > maxX) maxX = x2;
    if (x3 > maxX) maxX = x3;
    if (y2 > maxY) maxY = y2;
    if (y3 > maxY) maxY = y3;
    if (x2 < minX) minX = x2;
    if (x3 < minX) minX = x3;
    if (y2 < minY) minY = y2;
    if (y3 < minY) minY = y3;

    printf("The bounding box for the given points is: \n(%d,%d) - (%d,%d) \n", minX, minY, maxX, maxY);

    return 0;
}