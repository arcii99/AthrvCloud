//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>

float probability(float, int);

int main() {
    float distance;
    int days;

    printf("Enter the distance from Earth (in light years): ");
    scanf("%f", &distance);
    printf("Enter the number of days to estimate probability: ");
    scanf("%d", &days);

    printf("\nProbability of Alien Invasion: %.2f%%\n", probability(distance, days));

    return 0;
}

float probability(float distance, int days) {
    if (distance <= 0 || days <= 0) {
        return 0;
    } else if (distance <= 4) {
        return days * 0.5;
    } else if (distance <= 10) {
        return probability(distance - 4, days - 1) * 0.8 + days * 0.3;
    } else {
        return probability(distance - 10, days - 1) * 0.6 + days * 0.2;
    }
}