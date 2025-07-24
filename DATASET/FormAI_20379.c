//FormAI DATASET v1.0 Category: Scientific ; Style: creative
/* 
 * This program calculates the area and circumference of a circle 
 * based on the radius provided by the user. 
 * 
 * Created by [Your Name] 
 */ 
 
#include <stdio.h> 
#define PI 3.14159265359 // define pi as a constant 
 
int main() { 
    double radius, area, circumference; // declare variables 
 
    printf("Please enter the radius of the circle: ");
    scanf("%lf", &radius); // get radius from user 

    // calculate the area and circumference 
    area = PI * radius * radius; 
    circumference = 2 * PI * radius; 

    // print the results 
    printf("The area of the circle is: %lf\n", area); 
    printf("The circumference of the circle is: %lf\n", circumference); 

    return 0; 
} 

/*
 * Output:
 * Please enter the radius of the circle: 4
 * The area of the circle is: 50.265482
 * The circumference of the circle is: 25.132741
 */