//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char website[50];
    int interval;

    printf("Enter the URL of the website to monitor: ");
    fgets(website, 50, stdin);
    website[strcspn(website, "\n")] = 0; // remove newline character
    
    printf("Enter the interval (in seconds) to check the website: ");
    scanf("%d", &interval);

    while (1)
    {
        time_t now;
        time(&now);
        printf("Checking website %s at %s", website, ctime(&now));
        int status_code = system(website);
        if (status_code == 0)
        {
            printf("Website is up!\n");
        }
        else
        {
            printf("Website is down!\n");
        }
        printf("==============================================\n");
        sleep(interval);
    }

    return 0;
}