//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Starting website uptime monitor...\n");
    printf("Enter the website URL you want to monitor: ");
    char url[100];
    scanf("%s", url);
    printf("Monitoring website: %s\n", url);

    while (1) {
        // Ping website to check if it is up
        int res = system("ping -c 1 google.com > /dev/null");
        if (res == 0) {
            printf("Website is up!\n");
        } else {
            printf("Website is down!\n");
        }

        // Wait for 10 seconds
        printf("Waiting for 10 seconds...\n");
        sleep(10);
    }

    return 0;
}