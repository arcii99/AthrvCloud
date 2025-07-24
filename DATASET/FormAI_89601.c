//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include<stdio.h>

int main(){
    printf("Welcome to the world of Geometric Algorithms!\n");
    printf("Today, we will learn how to calculate the area of a triangle using the Shoelace Formula.\n");
    printf("Are you excited? Of course, you are! Let's get started!\n\n");

    int n;
    printf("Enter the number of vertices in the triangle: ");
    scanf("%d",&n);

    float x[n], y[n];
    printf("Enter the coordinates of the vertices in clockwise or counterclockwise order:\n");
    for(int i=0;i<n;i++){
        scanf("%f",&x[i]);
        scanf("%f",&y[i]);
    }

    float area = 0.0;

    for(int i=0;i<n-1;i++){
        area += x[i]*y[i+1] - x[i+1]*y[i];
    }

    area += x[n-1]*y[0] - x[0]*y[n-1];
    area = (area<0)?-area:area;
    area /= 2.0;

    printf("\nThe area of the triangle is: %.2f\n",area);
    printf("Wow! You did it! You just learned a new Geometric Algorithm - The Shoelace Formula!\n");

    return 0;
}