//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <math.h>

int main() {
    float radius;

    printf("I'm going to calculate the area and circumference of your favorite circle! Just give me the radius. ");
    scanf("%f", &radius);

    printf("Awesome! Watch me do some math now.\n");

    float area = M_PI*pow(radius,2);
    printf("The area of the circle is: %f\n", area);

    float circumference = 2*M_PI*radius;
    printf("The circumference of the circle is: %f\n", circumference);

    printf("Wow, that was fun! Want to calculate another circle?\n");

    printf("Type Y for yes or N for no: ");
    char answer;
    scanf(" %c", &answer);

    if(answer == 'Y' || answer == 'y') {
        printf("Great - let's go!\n");
        main();
    } else {
        printf("Oh well, I'll miss you. Come back soon!\n");
    }

    return 0;
}