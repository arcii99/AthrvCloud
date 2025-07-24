//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mind-bending
#include<stdio.h> 
#include<math.h> 

//Defining constants for PI and E 
#define M_PI 3.14159265358979323846 
#define M_E 2.71828182845904523536 

int main() 
{ 
    //Defining variables 
    int n, i; 
    float x1, y1, x2, y2, x3, y3, area, s, a, b, c, r, R; 
    
    //Taking user input for number of vertices 
    printf("Enter the number of vertices of the polygon: "); 
    scanf("%d", &n); 
    
    //Taking user input for the coordinates of the vertices 
    printf("\nEnter the coordinates of the vertices of the polygon:\n"); 
    scanf("%f %f", &x1, &y1); 
    x3 = x1; 
    y3 = y1; 
    
    //Calculating the area of the polygon 
    for(i = 1; i < n; i++) 
    { 
        scanf("%f %f", &x2, &y2); 
        a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); 
        b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2)); 
        c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)); 
        s = (a + b + c) / 2; 
        area += sqrt(s * (s - a) * (s - b) * (s - c)); 
        x3 = x2; 
        y3 = y2; 
    } 

    //Printing the area of the polygon 
    printf("\nThe area of the polygon is %f\n\n", area); 

    //Taking user input for radius of the circle 
    printf("Enter the radius of the circle: "); 
    scanf("%f", &r); 
    
    //Calculating the circumference of the circle 
    printf("\nThe circumference of the circle is %f\n\n", 2 * M_PI * r); 

    //Calculating the area of the circle 
    printf("The area of the circle is %f\n\n", M_PI * pow(r, 2)); 
    
    //Taking user input for radius of the circumcircle 
    printf("Enter the circumradius of the polygon: "); 
    scanf("%f", &R); 
    
    //Calculating the area of the circumcircle 
    printf("\nThe area of the circumcircle is %f\n\n", M_PI * pow(R, 2)); 

    //Taking user input for base and height of the triangle 
    printf("Enter the base and height of the triangle: "); 
    scanf("%f %f", &a, &b); 
    
    //Calculating the area of the triangle 
    printf("\nThe area of the triangle is %f\n\n", 0.5 * a * b); 

    //Taking user input for length of side of regular polygon 
    printf("Enter the number of sides and the length of each side of the regular polygon: "); 
    scanf("%d %f", &n, &a); 
    
    //Calculating the area of the regular polygon 
    printf("\nThe area of the regular polygon is %f\n\n", (n * pow(a, 2)) / (4 * tan(M_PI/n))); 
    
    //Returning 0 to end the program 
    return 0; 
}