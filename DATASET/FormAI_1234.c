//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main() {
    int downtime = 0;
    int uptime = 0;
    int i;
    time_t t;
    srand((unsigned) time(&t));

    for(i = 0; i < 24; i++) {
        int random_num = rand() % 10;
        if(random_num > 7) {
            printf("Website is down at %d:00!\n", i);
            downtime++;
        } else {
            printf("Website is up at %d:00!\n", i);
            uptime++;
        }
    }

    printf("\n\nThe website was down for %d hours and up for %d hours.", downtime, uptime);

    return 0;
}