//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

int checkWebsite(char* url) {
    int response = system(url);
    if (response) {
        printf("%s is down.\n", url);
        return 0;
    } else {
        printf("%s is up!\n", url);
        return 1;
    }
}

void monitorWebsite(char* url, int interval) {
    int status = checkWebsite(url);
    wait(interval);
    if (!status) {
        monitorWebsite(url, interval);
    }
}

int main() {
    char url[100];
    int interval;

    printf("Enter website URL: ");
    scanf("%s", url);

    printf("Enter interval (in seconds): ");
    scanf("%d", &interval);

    monitorWebsite(url, interval);

    return 0;
}