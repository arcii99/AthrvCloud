//FormAI DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>

void turnOnLight(int level) {
    if (level == 0) {
        printf("The light is off.\n");
    } else if (level == 10) {
        printf("The light is on at maximum brightness.\n");
    } else {
        printf("The light is on at level %d.\n", level);
        turnOnLight(level + 1);
    }
}

void setTemperature(double current, double target) {
    if (current == target) {
        printf("The temperature is already set to %g.\n", target);
    } else if (current > target) {
        printf("Decreasing temperature to %g degrees.\n", target);
        setTemperature(current - 1, target);
    } else {
        printf("Increasing temperature to %g degrees.\n", target);
        setTemperature(current + 1, target);
    }
}

void setAlarm(int minutes) {
    if (minutes == 0) {
        printf("The alarm is ringing!\n");
    } else {
        printf("%d minutes left until the alarm rings.\n", minutes);
        setAlarm(minutes - 1);
    }
}

int main() {
    turnOnLight(0);
    printf("\n");
    setTemperature(23, 18);
    printf("\n");
    setAlarm(5);
    return 0;
}