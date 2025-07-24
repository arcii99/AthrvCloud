//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846

int main () {
    float x1,y1,x2,y2,x3,y3;
    float a,b,c,alpha,beta,gamma;
    
    // Taking input
    printf("Enter the coordinates of the first point (x1,y1):\n");
    scanf("%f %f",&x1,&y1); 
    printf("Enter the coordinates of the second point (x2,y2):\n");
    scanf("%f %f",&x2,&y2);
    printf("Enter the coordinates of the third point (x3,y3):\n");
    scanf("%f %f",&x3,&y3); 
    
    // Calculating the lengths of the sides
    a = sqrt(pow((x2-x1),2) + pow((y2-y1),2)); 
    b = sqrt(pow((x3-x1),2) + pow((y3-y1),2)); 
    c = sqrt(pow((x3-x2),2) + pow((y3-y2),2)); 
    
    // Calculating the angles 
    alpha = acos((b*b + c*c - a*a)/(2*b*c)) * 180.0/PI; 
    beta = acos((a*a + c*c - b*b)/(2*a*c)) * 180.0/PI; 
    gamma = 180.0 - alpha - beta;
    
    // Printing the results
    printf("\nLength of the side AB: %.2f\n",a);
    printf("Length of the side AC: %.2f\n",b);
    printf("Length of the side BC: %.2f\n",c);
    printf("Angle at vertex A: %.2f degrees\n",alpha);
    printf("Angle at vertex B: %.2f degrees\n",beta);
    printf("Angle at vertex C: %.2f degrees\n",gamma);
    
    return 0;
}