//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shocked
#include <stdio.h> 
    
void main() 
{ 
    int x1, x2, x3, y1, y2, y3; 
    
    printf("Enter the values of x1, y1: "); 
    scanf("%d %d",&x1,&y1); 
    
    printf("Enter the values of x2, y2: "); 
    scanf("%d %d",&x2,&y2); 
    
    printf("Enter the values of x3, y3: "); 
    scanf("%d %d",&x3,&y3); 
    
    float a = ((y2 - y1)*x3 + (x1 - x2)*y3 + (x2*y1 - x1*y2)); 
    float b = ((y2 - y1)*x3 + (x1 - x2)*y3 + (x2*y1 - x1*y2)); 
    float c = ((y2 - y1)*x3 + (x1 - x2)*y3 + (x2*y1 - x1*y2)); 
    
    if (a == 0 || b == 0 || c == 0) 
    { 
        printf("The points are collinear\n"); 
    } 
    
    else if (((x2 - x1) / (x3 - x1)) == ((y2 - y1) / (y3 - y1))) 
    { 
        printf("The points are collinear\n"); 
    } 
    
    else if (a > 0 && b > 0 && c > 0) 
    { 
        printf("The points are inside the triangle\n"); 
    } 
    
    else if (a < 0 || b < 0 || c < 0) 
    { 
        printf("The points are outside the triangle\n"); 
    } 
    
    else 
    { 
        printf("The points are on the boundaries of the triangle\n"); 
    } 
    
}