//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <math.h>

//Function to calculate the area of a circle
float area_of_circle(float radius){
    float pi = 3.14159;
    float area = pi * pow(radius, 2);
    return area;
}

//Function to calculate the hypotenuse of a right triangle
float hypotenuse_of_triangle(float side1, float side2){
    float hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2));
    return hypotenuse;
}

int main(){
    printf("Welcome to the geometric calculator!\n");
    printf("Please select an option:\n");
    printf("1. Calculate the area of a circle\n");
    printf("2. Calculate the hypotenuse of a right triangle\n");
    int option;
    scanf("%d", &option);
    if(option == 1){
        printf("Please enter the radius of the circle: ");
        float radius;
        scanf("%f", &radius);
        printf("The area of the circle is %f\n", area_of_circle(radius));
    }
    else if(option == 2){
        printf("Please enter the length of side 1: ");
        float side1;
        scanf("%f", &side1);
        printf("Please enter the length of side 2: ");
        float side2;
        scanf("%f", &side2);
        printf("The length of the hypotenuse is %f\n", hypotenuse_of_triangle(side1, side2));
    }
    else{
        printf("Invalid option.\n");
    }
    return 0;
}