//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: medieval
#include <stdio.h>

#define G 9.81   // gravitational constant

int main() {

    float t, v, h;
    int i;

    printf("Enter the initial velocity, height and time of fall, respectively:\n");
    scanf("%f %f %f", &v, &h, &t);

    for(i=0; i<=t; i++) {

        float s = h + v * i - 0.5 * G * i * i;

        if(s<=0) break;

        printf("At %.2f seconds, the height is %.2f meters\n", i, s);
    }

    printf("The ball hits the ground after %.2f seconds\n", i-1);

    return 0;
}