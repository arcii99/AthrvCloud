//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TICKS_PER_SECOND 10
#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_HOUR 60
#define HOURS_IN_DAY 24

// Function declaration
void checkWebsiteStatus();

int main() {
    srand(time(NULL)); // Initialize random seed
    int tick = 0; // Initialize tick
    int uptime = 100; // Initialize uptime
    int downtime = 0; // Initialize downtime
    int days = 0; // Initialize days

    printf("Website Uptime Monitor\n");

    while (uptime > 0) { // Keep checking website status until uptime drops to 0%
        tick++; // Increase tick every loop
        if (tick == TICKS_PER_SECOND * SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY) { // 1 day elapsed
            days++;
            printf("\n%d day(s) have passed.\n", days);
            tick = 0; // Reset tick
        }

        checkWebsiteStatus(); // Check website status

        if (rand() % 100 < 10) { // 10% chance of downtime
            printf("Downtime detected at %d day(s), %d:%02d:%02d.\n", days, tick / (TICKS_PER_SECOND * SECONDS_IN_MINUTE * MINUTES_IN_HOUR), (tick / (TICKS_PER_SECOND * SECONDS_IN_MINUTE)) % MINUTES_IN_HOUR, (tick / TICKS_PER_SECOND) % SECONDS_IN_MINUTE);
            uptime--; // Decrease uptime
            downtime++; // Increase downtime
            printf("Website uptime: %d%%\n", uptime);
            printf("Downtime: %d minutes\n", downtime * (60 / TICKS_PER_SECOND));
            sleep(5); // Wait 5 seconds before checking website status again
        } else {
            printf("Website is up at %d day(s), %d:%02d:%02d.\n", days, tick / (TICKS_PER_SECOND * SECONDS_IN_MINUTE * MINUTES_IN_HOUR), (tick / (TICKS_PER_SECOND * SECONDS_IN_MINUTE)) % MINUTES_IN_HOUR, (tick / TICKS_PER_SECOND) % SECONDS_IN_MINUTE);
            printf("Website uptime: %d%%\n", uptime);
            sleep(1); // Wait 1 second before checking website status again
        }
    }

    printf("Website is down. Service has been interrupted for %d hour(s), %d minute(s).\n", downtime / MINUTES_IN_HOUR, downtime % MINUTES_IN_HOUR);

    return 0;
}

void checkWebsiteStatus() {
    if (rand() % 100 < 90) { // 90% chance that website is up
        return;
    }

    printf("Website is down!\n");
    sleep(5); // Wait 5 seconds before checking website status again
}