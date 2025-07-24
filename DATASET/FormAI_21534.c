//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
//Romeo and Juliet's Geometric Adventure

#include <stdio.h>
#include <math.h>

int main() {
    
    // Romeo and Juliet's initial coordinates
    int x1 = 0, y1 = 0;
    int x2 = 10, y2 = 10;
    printf("O Romeo, O Romeo! Wherefore art thou Romeo?\n");
    printf("I am here, my love Juliet. At point (%d, %d)\n", x1, y1);
    printf("I see you, my sweet Romeo. At point (%d, %d)\n", x2, y2);
    
    // Finding the distance between the two points
    float distance = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    distance = sqrt(distance);
    printf("My love, the distance between us is %.2f units.\n", distance);
    
    // Finding the slope of the line connecting the two points
    float slope = (float) (y2 - y1) / (x2 - x1);
    printf("My Romeo, the slope of the line connecting us is %.2f.\n", slope);
    
    // Finding the midpoint of the line connecting the two points
    float x_mid = (x1 + x2) / 2;
    float y_mid = (y1 + y2) / 2;
    printf("Dearest Romeo, meet me at the midpoint of our love at (%.2f, %.2f).\n", x_mid, y_mid);
    
    // Finding the equation of the line connecting the two points
    printf("Oh my fair Juliet, the equation of the line connecting us is y = %.2f * x + %.2f.\n", slope, y1 - (slope * x1));
    
    // Calculating the area of the triangle formed by the two points and the origin
    float area = (float) (x1 * (y2 - 0) + x2 * (0 - y1) + 0 * (y1 - y2)) / 2;
    area = fabs(area);
    printf("My heart beats for thee, Juliet! The area of the triangle formed by us and the origin is %.2f units squared.\n", area);
    
    return 0;
}