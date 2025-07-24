//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include<stdio.h>
#include<math.h>

// Function to find the area of a circle
float area_of_circle(float radius){
    return M_PI * pow(radius, 2);
}

// Function to find the area of a rectangle
float area_of_rectangle(float length, float breadth){
    return length * breadth;
}

// Function to find the area of a triangle
float area_of_triangle(float base, float height){
    return 0.5 * base * height;
}

int main(){
    int choice;
    float radius, length, breadth, base, height, area;
    
    printf("Enter your choice: \n");
    printf("1. Calculate the area of a circle\n");
    printf("2. Calculate the area of a rectangle\n");
    printf("3. Calculate the area of a triangle\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            area = area_of_circle(radius);
            printf("The area of the circle is %.2f", area);
            break;
        case 2:
            printf("Enter the length and breadth of the rectangle: ");
            scanf("%f %f", &length, &breadth);
            area = area_of_rectangle(length, breadth);
            printf("The area of the rectangle is %.2f", area);
            break;
        case 3:
            printf("Enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            area = area_of_triangle(base, height);
            printf("The area of the triangle is %.2f", area);
            break;
        default:
            printf("Invalid choice!");
    }
    
    return 0;
}