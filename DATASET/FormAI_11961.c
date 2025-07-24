//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
// A program to find area and perimeter of a rectangle
#include<stdio.h>
#include<stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

int area(struct Rectangle r) {
    return r.length * r.breadth;
}

int perimeter(struct Rectangle r) {
    return 2 * (r.length + r.breadth);
}

int main() {
    struct Rectangle r;
    printf("Enter the length and breadth of the rectangle: ");
    scanf("%d%d", &r.length, &r.breadth);
    printf("Area of the rectangle is %d\n", area(r));
    printf("Perimeter of the rectangle is %d\n", perimeter(r));
    return 0;
}