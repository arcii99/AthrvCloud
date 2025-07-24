//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include <stdio.h>
#include <math.h>

/*Function to calculate the area of a circle*/
float circle_area(float radius){
    return M_PI * pow(radius, 2);
}

/*Function to calculate the area of a rectangle*/
float rectangle_area(float length, float width){
    return length * width;
}

/*Function to calculate the area of a triangle*/
float triangle_area(float base, float height){
    return (base * height) / 2;
}

int main(){
    int choice;
    float radius, length, width, base, height, area;
    printf("Geometry Calculator\n");
    printf("1. Calculate the Area of a Circle\n");
    printf("2. Calculate the Area of a Rectangle\n");
    printf("3. Calculate the Area of a Triangle\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            area = circle_area(radius);
            printf("The area of the circle with radius %.2f is %.2f", radius, area);
            break;
        case 2:
            printf("Enter the length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            area = rectangle_area(length, width);
            printf("The area of the rectangle with length %.2f and width %.2f is %.2f", length, width, area);
            break;
        case 3:
            printf("Enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            area = triangle_area(base, height);
            printf("The area of the triangle with base %.2f and height %.2f is %.2f", base, height, area);
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice, please enter a number between 1 and 4");
            break;
    }
    return 0;
}