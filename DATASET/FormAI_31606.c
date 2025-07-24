//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include<stdio.h>

//function to calculate area of a triangle
float triangle_area(float base, float height){
    return (0.5 * base * height);
}

//function to calculate area of a circle
float circle_area(float radius){
    return (3.14 * radius * radius);
}

int main(){
    float base, height, radius;
    printf("\nWelcome to the Geometric Algorithm Program!\n\n");
    
    printf("Enter the base of the triangle: ");
    scanf("%f", &base);
    printf("Enter the height of the triangle: ");
    scanf("%f", &height);
    printf("The area of the triangle is: %.2f sq units\n\n", triangle_area(base, height));
    
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    printf("The area of the circle is: %.2f sq units\n\n", circle_area(radius));
    
    printf("Thanks for using our program, have a nice day!\n");
    return 0;
}