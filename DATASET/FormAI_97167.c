//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: random
#include<stdio.h>
#include<math.h>

float distance(float x1, float y1, float x2, float y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main(){
    int choice;
    printf("Choose an option\n1. Find distance between two points\n2. Find area of triangle\n3. Find perimeter of a rectangle\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            float x1,y1,x2,y2;
            printf("Enter coordinates of point 1 (x1 y1): ");
            scanf("%f %f",&x1,&y1);
            printf("Enter coordinates of point 2 (x2 y2): ");
            scanf("%f %f",&x2,&y2);
            printf("The distance between the two points is : %0.2f\n",distance(x1,y1,x2,y2));
            break;
        case 2:
            float a,b,c,s,area;
            printf("Enter the length of sides of the triangle (a b c): ");
            scanf("%f %f %f",&a,&b,&c);
            s = (a+b+c)/2; // semiperimeter
            area = sqrt(s*(s-a)*(s-b)*(s-c)); // Heron's formula
            printf("The area of the triangle is : %0.2f\n",area);
            break;
        case 3:
            float length,width,perimeter;
            printf("Enter the length and width of the rectangle (length width): ");
            scanf("%f %f",&length,&width);
            perimeter = 2*(length+width);
            printf("The perimeter of the rectangle is : %0.2f\n",perimeter);
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}