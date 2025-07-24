//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include<stdio.h>
#include<math.h>

//function to calculate the area of a triangle given its sides
float area_triangle(float a, float b, float c){
    float s = (a+b+c)/2; //calculate the semi-perimeter
    float area = sqrt(s*(s-a)*(s-b)*(s-c)); //use Heron's formula to calculate area
    return area;
}

int main(){
    float a, b, c;
    printf("Enter the three sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    //check whether triangle is valid
    if(a >= b+c || b >= a+c || c >= a+b){
        printf("Triangle is not valid.\n");
    }
    else{
        float area = area_triangle(a, b, c);
        printf("The area of the triangle is: %0.2f\n", area);
    }
    return 0;
}