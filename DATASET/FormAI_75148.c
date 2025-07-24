//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char url[100];
    int response_code = 0;

    // Get the URL from the user
    printf("My love, please enter the URL you want to monitor: ");
    scanf("%s", url);

    // Add some romantic flair
    printf("\nMy dear, I will keep a close watch over %s,\n", url);
    printf("Just as I keep a close watch over your heart.\n");

    // Continually check the website's status
    while (1)
    {
        // Use system() to execute a ping command
        char command[100];
        sprintf(command, "ping -c 1 %s > /dev/null", url);
        response_code = system(command);

        if (response_code == 0)
        {
            // Add some sweetness
            printf("\nMy love, your website %s is up and running,\n", url);
            printf("Just as my heart beats for you, it is unceasing.\n");
        }
        else
        {
            // Add some heartache
            printf("\nMy love, your website %s is down,\n", url);
            printf("Just as my heart would be without your smile.\n");
        }

        // Wait for a bit before checking again
        sleep(10);
    }

    return 0;
}