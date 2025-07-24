//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    int current_hour, current_minute, uptime_hour, uptime_minute, downtime_hour, downtime_minute;
    srand(time(NULL));
    current_hour = rand() % 24;
    current_minute = rand() % 60;

    uptime_hour = current_hour - 1;
    uptime_minute = current_minute + 30;

    if (uptime_minute >= 60) {
        uptime_hour++;
        uptime_minute -= 60;
    }

    downtime_hour = current_hour + 2;
    downtime_minute = current_minute - 45;

    if (downtime_minute < 0) {
        downtime_hour--;
        downtime_minute += 60;
    }

    printf("Current time: %02d:%02d\n", current_hour, current_minute);
    printf("Uptime: %02d:%02d - %02d:%02d\n", uptime_hour, uptime_minute, current_hour, current_minute);
    delay(5);
    printf("Downtime: %02d:%02d - %02d:%02d\n", current_hour, current_minute, downtime_hour, downtime_minute);
    delay(5);
    printf("Uptime has been restored!\n");

    return 0;
}