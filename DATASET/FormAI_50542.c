//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {

    printf("Welcome to the Surreal Website Uptime Monitor!\n");
    printf("Please enter the website you want to monitor: ");

    char website[100];
    scanf("%s", website);

    srand(time(0));
    int uptime = (rand() % 100) + 1;

    while (1) {
        printf("Checking website %s...\n", website);
        if (uptime > 50) {
            printf("Website %s is up with %d%% uptime.\n", website, uptime);
        }
        else {
            printf("The universe has shifted and website %s is down with %d%% uptime.\n", website, uptime);
        }
        sleep(10);
        uptime = (rand() % 100) + 1;
    }

    return 0;
}