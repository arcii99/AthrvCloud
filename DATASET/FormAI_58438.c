//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

bool is_up() {
    srand(time(NULL));
    return rand() % 2 == 0;
}

int main() {
    int uptime, downtime;
    uptime = downtime = 0;
    printf("Welcome to the Surreal Website Uptime Monitor!\n");

    while (true) {
        if (is_up()) {
            uptime++;
            printf("The website is up! Uptime: %d seconds | Downtime: %d seconds\n", uptime, downtime);
        } else {
            downtime++;
            printf("The website is down. Uptime: %d seconds | Downtime: %d seconds\n", uptime, downtime);
        }
        sleep(2);
    }

    return 0;
}