//FormAI DATASET v1.0 Category: Scientific ; Style: funny
#include <stdio.h>
#include <math.h>

/* A program to calculate the volume of a sphere using funny inputs */

int main() {
    float radius;
    printf("Hey there! I heard you want to find the volume of a sphere. Let's get started! \n");
    printf("First things first, what's the radius of your sphere? \n");
    scanf("%f", &radius);

    if(radius <= 0) {
        printf("Oh dear, it seems your sphere has collapsed into a singularity. Let's try that again with a different input! \n");
        main();
        return 0;
    }

    printf("Great! Now I need to know what units you're measuring in. \n");

    char units[10];
    scanf("%s", units);

    printf("Excellent! I am now processing the volume of your sphere in %s. \n", units);
    float volume = (4.0/3.0) * M_PI * pow(radius, 3);
    printf("The volume of your sphere is %.2f %s³. \n", volume, units);

    printf("I hope you found this experience spherical-ly enjoyable. Thanks for playing! \n");

    return 0;
}