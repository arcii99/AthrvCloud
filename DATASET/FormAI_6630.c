//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

bool check_website_status(char* url) {
    char command[500];
    strcpy(command, "curl --max-time 5 --silent --fail --output /dev/null ");
    strcat(command, url);

    int status = system(command);

    if (status == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    char* website_url = "https://example.com";
    int sleep_time = 60; // in seconds

    printf("Website Uptime Monitor\n");
    printf("Checking %s every %d seconds...\n\n", website_url, sleep_time);

    while (true) {
        if (check_website_status(website_url)) {
            printf("%s is UP!\n", website_url);
        }
        else {
            printf("%s is DOWN!\n", website_url);
        }

        sleep(sleep_time);
    }

    return 0;
}