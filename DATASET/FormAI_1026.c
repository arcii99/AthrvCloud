//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char website[256];
    int delay;

    printf("Enter website URL to monitor: ");
    scanf("%s", website);

    printf("Enter delay in seconds between checks: ");
    scanf("%d", &delay);

    while(1) {
        char ping[256];
        sprintf(ping, "ping -c 1 %s >> /dev/null 2>&1", website); //execute ping command

        int result = system(ping); //collect return value

        if(result == 0) {
            printf("%s is up and running!\n", website);
        } else {
            printf("%s seems to be down...\n", website);
        }

        sleep(delay); //wait for specified delay
    }

    return 0;
}