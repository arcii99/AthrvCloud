//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Website Uptime Monitor!\n");
    char website[50];
    printf("Enter the website you want to monitor: ");
    scanf("%s", website);
    while(1) {
        int status = system("ping -c 1 google.com"); // replace google.com with website variable
        if (status != 0) {
            printf("Website is down!\n");
        } else {
            printf("Website is up!\n");
        }
        sleep(60); // sleep for 60 seconds before checking again
    }
    return 0;
}