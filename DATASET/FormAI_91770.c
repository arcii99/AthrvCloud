//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to our geometric algorithm calculator!\n");
    printf("Let's find the area and perimeter of a circle.\n");

    const float PI = 3.14159;
    float radius, area, perimeter;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area = PI * radius * radius;
    perimeter = 2 * PI * radius;

    printf("The area of the circle is %.2f.\n", area);
    printf("The perimeter of the circle is %.2f.\n", perimeter);

    printf("Now, let's find the area and perimeter of a rectangle.\n");

    float length, width, rect_area, rect_perimeter;

    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);

    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);

    rect_area = length * width;
    rect_perimeter = 2 * (length + width);

    printf("The area of the rectangle is %.2f.\n", rect_area);
    printf("The perimeter of the rectangle is %.2f.\n", rect_perimeter);

    printf("Great job! Thanks for using our calculator.\n");

    return 0;
}