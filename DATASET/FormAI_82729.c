//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include<stdio.h>
#include<math.h>

//Defining the structure for a point
struct Point {
    int x, y;
};

//Function to find distance between two points
float distance(struct Point p1, struct Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

//Function to find the area of a triangle
float triangle_area(struct Point p1, struct Point p2, struct Point p3) {
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    float s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

//Main function
int main() {
    struct Point p1, p2, p3;
    printf("Enter the coordinates of Point 1: ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Enter the coordinates of Point 2: ");
    scanf("%d %d", &p2.x, &p2.y);
    printf("Enter the coordinates of Point 3: ");
    scanf("%d %d", &p3.x, &p3.y);
    float area = triangle_area(p1, p2, p3);
    printf("The area of the triangle formed by (%d,%d), (%d,%d), (%d,%d) is %.2f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, area);
    return 0;
}