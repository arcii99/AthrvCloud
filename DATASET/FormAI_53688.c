//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include<stdio.h>
#include<math.h>

int main() {
    printf("Welcome to the Funny Geometry World!\n");

    float radius, area, perimeter;
    printf("Please enter the radius of the circle (in centimeters): ");
    scanf("%f", &radius);

    area = pow(radius, 2) * M_PI;
    perimeter = 2 * radius * M_PI;
    
    printf("Wow! You just gave me the radius of your circle, which is %f centimeters.\n", radius);
    printf("Based on the radius you provided, I calculated that the area is %f square centimeters.\n", area);
    printf("And the perimeter is %f centimeters.\n\n", perimeter);

    printf("Now, let's move on to some triangles!\n");

    float a, b, c;
    printf("Please enter the length of side a: ");
    scanf("%f", &a);
    printf("Please enter the length of side b: ");
    scanf("%f", &b);

    if (a <= 0 || b <= 0) {
        printf("Oops! One of your sides has an invalid length.\n");
        printf("I cannot calculate the hypotenuse for you. Better luck next time!\n\n");
    } else {
        c = sqrt(pow(a, 2) + pow(b, 2));
        printf("Great job! Based on the values you provided, I calculated that the hypotenuse is %f units long.\n\n", c);
    }

    printf("Thanks for using the Funny Geometry World program!\n");
    return 0;
}