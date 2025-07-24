//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

//function to calculate the distance between two points
float calculate_distance(float x1, float y1, float x2, float y2){
    float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance;
}

int main(){
    float x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x1,y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point (x2,y2): ");
    scanf("%f %f", &x2, &y2);
    
    float distance = calculate_distance(x1, y1, x2, y2);
    printf("The distance between (%.2f,%.2f) and (%.2f,%.2f) is %.2f\n", x1, y1, x2, y2, distance);
}