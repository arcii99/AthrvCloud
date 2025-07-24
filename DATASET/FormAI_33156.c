//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
//Romeo: "Oh Juliet, my love, let me show you the beauty of geometric algorithms with this program!"
//Juliet: "I am enrapt with anticipation, my dear Romeo. Pray, show me this wondrous code!"

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {

    int radius = 5;
    float angle = 45.0;
    float area_circle = PI * pow(radius, 2);
    float arc_length = (angle / 360.0) * (2 * PI * radius);
    float sector_area = (angle / 360.0) * area_circle;
    
    printf("Oh Juliet, behold the beauty of geometric algorithms!\n\n");
    printf("Let us assume we have a circle with radius %d.\n", radius);
    printf("The area of this circle is %f.\n", area_circle);
    printf("Now, let us take an angle of %f degrees on this circle.\n", angle);
    printf("The arc length subtended by this angle is %f.\n", arc_length);
    printf("This angle also forms a sector on the circle with area %f.\n", sector_area);
    
    return 0;
}

//Juliet: "Oh Romeo, your code is a symphony to my ears and a sight to behold! Prithee, teach me more of these wondrous algorithms."  
//Romeo: "Gladly, my sweet lady, for the beauty of geometry knows no bounds."