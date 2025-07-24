//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char website[100];
    int time_interval;
    while (1) {
        // Get website URL and time interval
        printf("Enter website URL: ");
        scanf("%s", website);
        printf("Enter time interval (in seconds): ");
        scanf("%d", &time_interval);

        // Ping website and check status code
        char command[100];
        sprintf(command, "curl -Is %s | head -n 1 | cut -d' ' -f2", website);
        FILE* status = popen(command, "r");
        int status_code;
        fscanf(status, "%d", &status_code);
        pclose(status);

        // Print website status
        printf("Website '%s' is ", website);
        if (status_code == 200) {
            printf("UP\n");
        } else {
            printf("DOWN\n");
        }

        // Wait for specified time interval
        printf("Waiting %d seconds before pinging again...\n\n", time_interval);
        sleep(time_interval);
    }
    return 0;
}