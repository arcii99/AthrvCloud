//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LENGTH 100
#define MAX_STATUS_LENGTH 20

typedef struct Monitor {
    char url[MAX_URL_LENGTH];
    time_t last_check;
    char status[MAX_STATUS_LENGTH];
} Monitor;

int main() {
    int num_monitors;
    printf("Enter the number of monitors: ");
    scanf("%d", &num_monitors);

    Monitor monitors[num_monitors];

    // Add monitors
    for (int i = 0; i < num_monitors; i++) {
        printf("Enter monitor URL #%d: ", i+1);
        scanf("%s", monitors[i].url);
        strcpy(monitors[i].status, "UNKNOWN");
    }

    while (1) {
        // Check monitors
        for (int i = 0; i < num_monitors; i++) {
            time_t current_time = time(NULL);
            double elapsed_time = (double)difftime(current_time, monitors[i].last_check);
            if (elapsed_time > 10) {
                monitors[i].last_check = current_time;
                // Check URL status
                // ... code to check URL status ...
                // Set monitor status
                strcpy(monitors[i].status, "UP");
                printf("Monitor #%d status: UP\n", i+1);
            }
        }

        // Print monitor statuses
        printf("Monitor statuses:\n");
        for (int i = 0; i < num_monitors; i++) {
            printf("%s: %s\n", monitors[i].url, monitors[i].status);
        }

        // Sleep for 10 seconds before checking again
        sleep(10);
    }

    return 0;
}