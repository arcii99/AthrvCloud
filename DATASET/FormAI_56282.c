//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>

int isWebsiteUp() {
    // code to check website status here
    // return 1 if website is up, 0 if down
}

int main() {
    printf("Welcome to the Happy Website Uptime Monitor!\n");
    printf("We'll check your website every minute to make sure everything's running smoothly.\n");

    // set up some variables for tracking uptime
    int totalUptime = 0;
    int consecutiveDowntime = 0;
    int maxConsecutiveDowntime = 0;

    // loop indefinitely, checking website status once a minute
    while (1) {
        int websiteUp = isWebsiteUp();

        if (websiteUp) {
            printf("Your website is up and running!\n");
            totalUptime++;
            consecutiveDowntime = 0;
        } else {
            printf("Uh oh, your website is down!\n");
            consecutiveDowntime++;
            if (consecutiveDowntime > maxConsecutiveDowntime) {
                maxConsecutiveDowntime = consecutiveDowntime;
            }
        }

        printf("Total uptime: %d minutes\n", totalUptime);
        printf("Current consecutive downtime: %d minutes\n", consecutiveDowntime);
        printf("Max consecutive downtime: %d minutes\n", maxConsecutiveDowntime);

        printf("We'll check again in 1 minute, keep smiling and stay happy!\n\n");
        sleep(60); // wait 1 minute before checking again
    }
    return 0;
}