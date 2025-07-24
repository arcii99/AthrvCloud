//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int uptime = 0;
    srand(time(NULL));
    printf("Starting website uptime monitor...\n\n");
    while(1)
    {
        int is_up = rand() % 2;
        if(is_up)
        {
            printf("[%d seconds] Website is up and running enthusiastically.\n", uptime);
        }
        else
        {
            printf("[%d seconds] Ouch! The website is taking a nap, please wake it up, will you?\n", uptime);
        }
        int random_sleep = rand() % 10 + 1;
        printf("Sleeping for %d seconds before checking again...\n\n", random_sleep);
        sleep(random_sleep);
        uptime += random_sleep;
    }
    return 0;
}