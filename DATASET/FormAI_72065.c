//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle with given vertices
float area_of_triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// Function to check if two line segments intersect (based on orientation of points)
int do_segments_intersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    int orientation1 = ((y3-y1) * (x2-x1)) - ((x3-x1) * (y2-y1));
    int orientation2 = ((y4-y1) * (x2-x1)) - ((x4-x1) * (y2-y1));
    int orientation3 = ((y1-y3) * (x4-x3)) - ((x1-x3) * (y4-y3));
    int orientation4 = ((y2-y3) * (x4-x3)) - ((x2-x3) * (y4-y3));
    
    if ((orientation1 > 0 && orientation2 < 0) || (orientation1 < 0 && orientation2 > 0)) {
        if ((orientation3 > 0 && orientation4 < 0) || (orientation3 < 0 && orientation4 > 0)) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    float x1, y1, x2, y2, x3, y3, x4, y4;
    printf("Enter the coordinates of the first segment (x1,y1,x2,y2):\n");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    printf("Enter the coordinates of the second segment (x3,y3,x4,y4):\n");
    scanf("%f %f %f %f",&x3,&y3,&x4,&y4);
    
    float area1 = area_of_triangle(x1,y1,x2,y2,x3,y3);
    float area2 = area_of_triangle(x1,y1,x2,y2,x4,y4);
    float area3 = area_of_triangle(x3,y3,x4,y4,x1,y1);
    float area4 = area_of_triangle(x3,y3,x4,y4,x2,y2);
    
    if (do_segments_intersect(x1,y1,x2,y2,x3,y3,x4,y4)) {
        printf("The two line segments intersect!\n");
        return 0;
    }
    
    if (area1+area2+area3+area4 == area_of_triangle(x1,y1,x2,y2,x4,y4)+area_of_triangle(x1,y1,x3,y3,x4,y4)) {
        printf("The two line segments overlap!\n");
    } else {
        printf("The two line segments do not intersect.\n");
    }
    
    return 0;
}