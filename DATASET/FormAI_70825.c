//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MBPS_UNIT "Mbps"
#define KBPS_UNIT "Kbps"
#define MINIMUM_SPEED 0.1f
#define MAXIMUM_SPEED 10000.f
#define NANO_TO_SECOND 1000000000L

float measure_speed() {
    float speed = ((float) rand() / (float) RAND_MAX) * (MAXIMUM_SPEED - MINIMUM_SPEED) + MINIMUM_SPEED;
    return speed;
}

char *get_speed_unit(float speed) {
    char *unit = MBPS_UNIT;
    if (speed <= 1.f) {
        unit = KBPS_UNIT;
        speed *= 1000.f;
    }
    return unit;
}

void print_speed(float speed, char *unit) {
    printf("Your internet speed is: %.2f %s\n", speed, unit);
}

int main() {
    srand(time(NULL));
    float speed = measure_speed();
    char *unit = get_speed_unit(speed);
    print_speed(speed, unit);
    return 0;
}