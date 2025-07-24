//FormAI DATASET v1.0 Category: Physics simulation ; Style: Romeo and Juliet
#include <stdio.h>

float calculate_velocity(float u, float a, float t) {
    float v = u + (a * t);
    return v;
}

float calculate_displacement(float u, float a, float t) {
    float s = (u * t) + (0.5 * a * t * t);
    return s;
}

int main() {
    float u, a, t;
    printf("Enter the initial velocity of the object: ");
    scanf("%f", &u);
    printf("Enter the acceleration of the object: ");
    scanf("%f", &a);
    printf("Enter the time elapsed: ");
    scanf("%f", &t);

    float v = calculate_velocity(u, a, t);
    float s = calculate_displacement(u, a, t);

    printf("Final velocity of the object = %.2f m/s\n", v);
    printf("Displacement of the object = %.2f m\n", s);
    return 0;
}