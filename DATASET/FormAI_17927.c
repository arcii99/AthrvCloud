//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// website URL to monitor
#define WEBSITE_URL "https://google.com"

// ping interval in seconds
#define PING_INTERVAL 5

// max number of consecutive failed pings
#define MAX_FAILED_PINGS 3

// function to ping website
bool ping_website() {
    // ping website and return true if successful, false otherwise
    return system("ping -c 1 -w 1 " WEBSITE_URL " &>/dev/null") == 0;
}

// function to send notification
void send_notification(bool is_up) {
    // send notification to a user or system, depending on implementation
    if (is_up) {
        printf("Website is up!\n");
    } else {
        printf("Website is down!\n");
    }
}

int main() {
    // initialize variables
    bool is_up = false;
    int num_failed_pings = 0;

    // infinite loop to monitor website
    while (true) {
        // ping website
        bool ping_success = ping_website();

        if (ping_success) {
            // website is up
            if (!is_up) {
                // website just came back up after being down
                printf("Website is up!\n");
            }
            is_up = true;
            num_failed_pings = 0;
        } else {
            // website is down
            num_failed_pings++;
            if (num_failed_pings >= MAX_FAILED_PINGS) {
                // website has been down for too long
                if (is_up) {
                    printf("Website is down!\n");
                    send_notification(false);
                }
                is_up = false;
            }
        }

        // wait for ping interval before pinging again
        sleep(PING_INTERVAL);
    }

    return 0;
}