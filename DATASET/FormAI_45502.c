//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool connected = false;

void checkWebsiteStatus() {
    // Here we would write the code to check if the website is up or not.
    // However, since this is just a mockup,
    // we will simply randomly set the website status as connected or disconnected.
    srand(time(NULL));
    int r = rand() % 2;
    connected = r == 1 ? true : false;
}

int main() {
    char websiteURL[100];
    int countdown = 30;
    
    printf("Enter the URL of the website you want to monitor: ");
    scanf("%s", websiteURL);
    printf("\nMonitoring %s\n", websiteURL);
    
    while (countdown > 0) {
        checkWebsiteStatus();
        if (connected) {
            printf("Website is up and running!\n");
        } else {
            printf("Oh no! Website is down!\n");
        }
        printf("Next check in 10 seconds...\n");
        countdown--;
        sleep(10);
    }
    
    printf("\nMonitoring session has ended.\n");

    return 0;
}