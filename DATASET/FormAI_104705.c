//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: all-encompassing
#include<stdio.h>
#include<math.h>

// Calculate the distance between two points in 2D space
float calculateDistance(float x1, float y1, float x2, float y2){
    float distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    return distance;
}

// Determine if three points form a counter-clockwise orientation
int isCCW(float x1, float y1, float x2, float y2, float x3, float y3){
    float crossProduct = (y3-y1)*(x2-x1) - (x3-x1)*(y2-y1);
    if(crossProduct >0){
        return 1; // Points are in a counter-clockwise orientation
    }
    else{
        return 0; // Points are either in a clockwise orientation or colinear
    }
}

// Calculate the area of a triangle given its three points
float calculateTriangleArea(float x1, float y1, float x2, float y2, float x3, float y3){
    float area = 0.5 * ((x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1));
    return area;
}

int main(){
    float x1, y1, x2, y2, x3, y3;
    float distance, area;
    int ccw;

    printf("Enter the three points as x1,y1 x2,y2 x3,y3: ");
    scanf("%f,%f %f,%f %f,%f",&x1,&y1,&x2,&y2,&x3,&y3);

    // Calculate the distance between two points (x1,y1) and (x2,y2)
    distance = calculateDistance(x1, y1, x2, y2);
    printf("The distance between point (%.2f,%.2f) and point (%.2f,%.2f) is %.2f\n\n",x1,y1,x2,y2,distance);

    // Determine if three points are in a counter-clockwise orientation
    ccw = isCCW(x1, y1, x2, y2, x3, y3);
    if(ccw){
        printf("The three points (%.2f,%.2f), (%.2f,%.2f), and (%.2f,%.2f) are in a counter-clockwise orientation.\n\n",x1,y1,x2,y2,x3,y3);
    }
    else{
        printf("The three points (%.2f,%.2f), (%.2f,%.2f), and (%.2f,%.2f) are either in a clockwise orientation or colinear.\n\n",x1,y1,x2,y2,x3,y3);
    }

    // Calculate the area of a triangle given its three points
    area = calculateTriangleArea(x1, y1, x2, y2, x3, y3);
    printf("The area of the triangle with vertices (%.2f,%.2f), (%.2f,%.2f), and (%.2f,%.2f) is %.2f.\n",x1,y1,x2,y2,x3,y3,area);

    return 0;
}