//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

    int a, b;
    float c, d, e, f, g, h;

    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    c = sqrt(a*a + b*b);
    printf("The hypotenuse of the right triangle is %.2f\n", c);

    d = acos(a/c);
    printf("The angle opposite to the side 'a' in degrees is %.2f\n", d*180/M_PI);

    e = acos(b/c);
    printf("The angle opposite to the side 'b' in degrees is %.2f\n", e*180/M_PI);

    f = tan(d);
    printf("The tangent of the angle opposite to the side 'a' is %.2f\n", f);

    g = tan(e);
    printf("The tangent of the angle opposite to the side 'b' is %.2f\n", g);

    h = (f*g)/(f+g);
    printf("The harmonic mean of the tangents of the two angles opposite to the sides 'a' and 'b' is %.2f\n", h);

    return 0;
}