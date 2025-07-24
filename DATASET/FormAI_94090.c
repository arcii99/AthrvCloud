//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h> 

#define PI 3.14159265358979323846 

int main() 
{ 
    double radius, x_center, y_center, angle; 
    
    printf("Enter the radius of the circle: "); 
    scanf("%lf", &radius); 
    
    printf("Enter the x-coordinate of the center of the circle: "); 
    scanf("%lf", &x_center); 
    
    printf("Enter the y-coordinate of the center of the circle: "); 
    scanf("%lf", &y_center); 
    
    printf("Enter the angle (in degrees) to rotate the circle: "); 
    scanf("%lf", &angle);    
    
    // Convert angle from degrees to radians 
    angle = angle * PI / 180.0; 
    
    double rotated_x, rotated_y; 
    double sine = sin(angle), cosine = cos(angle); 
    
    printf("The transformed coordinates of the circle are: \n"); 
    
    // Iterate through 360 degrees and calculate new coordinates 
    for(int i = 0; i < 360; i++) 
    { 
        double radians = i * PI / 180.0; 
        
        // Rotate the coordinates 
        rotated_x = (radius * cos(radians) * cosine) - (radius * sin(radians) * sine) + x_center; 
        rotated_y = (radius * cos(radians) * sine) + (radius * sin(radians) * cosine) + y_center; 
        
        printf("(%f, %f)\n", rotated_x, rotated_y); 
    } 
    
    return 0; 
}