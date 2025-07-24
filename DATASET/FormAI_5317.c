//FormAI DATASET v1.0 Category: Physics simulation ; Style: complete
#include<stdio.h>
#include<math.h>

#define GRAVITY 9.81
#define PI 3.14159

float calculateDistance(float initialVelocity, float angle)
{
    float radian = angle * (PI / 180);
    float distance = pow(initialVelocity, 2) * sin(2 * radian) / GRAVITY;
    return distance;
}

void simulateProjectileMotion(float initialVelocity, float angle, float timeIncrement)
{
    float x, y, time = 0;

    while (y >= 0)
    {
        x = initialVelocity * cos(angle * PI / 180) * time;
        y = initialVelocity * sin(angle * PI / 180) * time - 0.5 * GRAVITY * pow(time, 2);
        printf("Time: %.2f s \t Distance: %.2f m \t Height: %.2f m\n", time, x, y);
        time += timeIncrement;
    }
}

int main()
{
    float initialVelocity, angle, timeIncrement;
    printf("\nEnter initial velocity (m/s): ");
    scanf("%f", &initialVelocity);
    printf("\nEnter angle of projection (degrees): ");
    scanf("%f", &angle);
    printf("\nEnter time increment (s): ");
    scanf("%f", &timeIncrement);
    float distance = calculateDistance(initialVelocity, angle);
    printf("\nProjectile will travel %.2f meters.\n", distance);
    printf("Projectile motion simulation beginning...\n\n");
    simulateProjectileMotion(initialVelocity, angle, timeIncrement);
    return 0;
}