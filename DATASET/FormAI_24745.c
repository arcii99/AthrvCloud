//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define SLEEP_TIME 60 // Time in seconds to wait between checks
#define MAX_RETRIES 5 // Maximum number of retries before declaring site as down

bool isSiteUp(const char* url) {
    // Use the "ping" command to check if the site is up
   char command[100];
   sprintf(command, "ping -c 1 %s >/dev/null", url);
   return (system(command) == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [url]\n", argv[0]);
        return 1;
    }

    const char* url = argv[1];
    int retries = 0;

    while (true) {
        if (isSiteUp(url)) {
            printf("%s is up!\n", url);
            retries = 0;
        } else {
            printf("%s is down! (retrying in %d seconds)\n", url, SLEEP_TIME);

            retries++;
            if (retries >= MAX_RETRIES) {
                printf("%s is down for good!\n", url);
                return 1;
            }
        }

        sleep(SLEEP_TIME);
    }

    return 0;
}