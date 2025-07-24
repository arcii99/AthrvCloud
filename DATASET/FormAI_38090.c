//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int time_since_last_check = 0;
    int uptime = 0;
    srand(time(NULL));
    printf("Initializing website uptime monitor...\n");
    printf("Checking website status every 5 seconds...\n");
    while (1)
    {
        // Check website status every 5 seconds
        if (time_since_last_check >= 5)
        {
            int random_num = rand() % 10;
            if (random_num < 8)
            {
                printf("Website is up! (Uptime: %d seconds)\n", uptime);
                uptime += 5;
            }
            else
            {
                printf("The website is down! (Uptime: %d seconds)\n", uptime);
                uptime = 0;
            }
            time_since_last_check = 0;
        }

        // Wait for one second
        sleep(1);
        time_since_last_check++;
    }

    return 0;
}