//FormAI DATASET v1.0 Category: Educational ; Style: modular
/* A Program to find the area of a rectangle */

#include<stdio.h>

/* Function to calculate the area of a rectangle */
float area_of_rectangle(float length, float breadth)
{
    float area = length * breadth;
    return area;
}

/* Function to take user input and print the area of a rectangle */
void print_area_of_rectangle()
{
    float length, breadth, area;
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &breadth);
    area = area_of_rectangle(length, breadth);
    printf("The area of the rectangle is: %f", area);
}

/* Main function to call the print_area_of_rectangle function */
int main()
{
    print_area_of_rectangle();
    return 0;
}