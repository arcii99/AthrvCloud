//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>

int main() {
    printf("Hello there! Let's have some fun with geometric algorithms in C!\n");

    int x1, y1, x2, y2;
    printf("Please enter the x and y values for the first point (comma separated): ");
    scanf("%d, %d", &x1, &y1);
    printf("Great! Now please enter the x and y values for the second point (comma separated): ");
    scanf("%d, %d", &x2, &y2);

    printf("Calculating the distance between the two points...\n");
    double distance = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    printf("The distance between (%d, %d) and (%d, %d) is %.2f units.\n", x1, y1, x2, y2, distance);

    printf("Now, let's calculate the area of a triangle given three points.\n");
    int a1, b1, a2, b2, a3, b3;
    printf("Please enter the x and y values for the first point (comma separated): ");
    scanf("%d, %d", &a1, &b1);
    printf("Great! Now please enter the x and y values for the second point (comma separated): ");
    scanf("%d, %d", &a2, &b2);
    printf("Awesome! Finally, please enter the x and y values for the third point (comma separated): ");
    scanf("%d, %d", &a3, &b3);

    double area = abs((a1*(b2-b3)+a2*(b3-b1)+a3*(b1-b2))/2.0);
    printf("The area of the triangle with vertices (%d, %d), (%d, %d), and (%d, %d) is %.2f square units.\n", a1, b1, a2, b2, a3, b3, area);

    printf("Hope you had fun with geometric algorithms in C! See you soon!\n");

    return 0;
}