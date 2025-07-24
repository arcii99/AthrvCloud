//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int websiteStatus = 1; // website is up
    int uptime = rand() % 101; // random uptime between 0 and 100
    int count = 0; // number of times website is checked

    printf("Welcome to the surrealist website uptime monitor!\n");

    while (1) {
        printf("\nChecking website status... ");

        if (websiteStatus == 1) {
            printf("Website is up! (Uptime: %d%%)\n", uptime);
            
            if (uptime >= 75) {
                printf("The website is feeling particularly surreal today...\n");
            }
        } else {
            printf("Website is down. (Uptime: 0%%)\n");
            printf("Something strange is happening... the website seems to be glitching out...\n");
        }

        count++;

        if (count % 10 == 0) {
            printf("\nYou've been staring at this monitor for a while now... don't you have other things to do?");
        }

        printf("\nEnter any key to check the website again, or enter 'q' to quit: ");

        char userInput = getchar();

        if (userInput == 'q') {
            printf("\nQuitting the surrealist website uptime monitor... goodbye!\n");
            break;
        } else {
            websiteStatus = rand() % 2; // randomly change website status
            if (websiteStatus == 1) {
                uptime += rand() % 11; // randomly increase uptime by up to 10%
            } else {
                uptime = 0; // website is down, uptime is 0%
            }
        }
    }

    return 0;
}