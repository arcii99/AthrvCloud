//FormAI DATASET v1.0 Category: Physics simulation ; Style: careful
#include<stdio.h>
#include<math.h>

float calculate_position(float u, float a, float t, float s0) {
    return s0 + (u * t) + (0.5 * a * pow(t, 2));
}

int main() {
    float u, a, s0, s1, s2, t;
    printf("Enter the initial velocity (m/s): ");
    scanf("%f", &u);
    printf("Enter the acceleration (m/s^2): ");
    scanf("%f", &a);
    printf("Enter the initial position (m): ");
    scanf("%f", &s0);
    printf("Enter the time interval (s): ");
    scanf("%f", &t);
    
    s1 = calculate_position(u, a, t, s0);
    printf("Position after %f seconds: %f\n", t, s1);
    
    t *= 2;
    s2 = calculate_position(u, a, t, s0);
    printf("Position after %f seconds: %f\n", t, s2);
    
    printf("Displacement during time interval: %f\n", s2 - s1);
    
    return 0;
}