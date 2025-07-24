//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include<stdio.h>

//Function to find the area of a triangle given the coordinates of its vertices
int triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
    //Calculating the area using the shoelace formula
    int area = abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2);
    return area;
}

//Main function
int main() {
    //Taking the coordinates of the vertices from the user
    printf("Enter the coordinates of vertex 1 (x1,y1): ");
    int x1, y1;
    scanf("%d,%d", &x1, &y1);

    printf("Enter the coordinates of vertex 2 (x2,y2): ");
    int x2, y2;
    scanf("%d,%d", &x2, &y2);

    printf("Enter the coordinates of vertex 3 (x3,y3): ");
    int x3, y3;
    scanf("%d,%d", &x3, &y3);

    //Finding the area of the triangle
    int area = triangle_area(x1, y1, x2, y2, x3, y3);

    //Printing the result
    printf("The area of the triangle with vertices (%d,%d), (%d,%d), and (%d,%d) is %d units squared\n", x1,y1,x2,y2,x3,y3,area);

    return 0;
}