//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void checkSiteStatus(char *site) {
    char command[100];
    sprintf(command, "ping -c 1 %s", site);
    system(command);
    printf("\n");

    time_t now = time(NULL);
    char *timeString = ctime(&now);
    timeString[strlen(timeString) - 1] = '\0';

    printf("%s: Checked status of website: %s\n", timeString, site);
}

int main() {
    char site[100];
    int interval;

    printf("Enter website URL: ");
    scanf("%s", site);
    printf("Enter interval time in seconds: ");
    scanf("%d", &interval);

    printf("\n");

    while (1) {
        checkSiteStatus(site);
        sleep(interval);
    }

    return 0;
}