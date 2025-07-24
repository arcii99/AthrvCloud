//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256
#define MAX_ALERT_THRESHOLD 5

int main()
{
    int alert_count = 0;

    while(1)
    {
        char input[MAX_INPUT_LENGTH];

        // read input from user
        printf("Enter command: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // check for intrusion attempts

        // detect port scanning
        if(strncmp(input, "nmap", 4) == 0)
        {
            printf("Port scanning attempt detected!\n");
            alert_count++;
        }

        // detect brute force attacks
        if(strncmp(input, "ssh", 3) == 0)
        {
            printf("SSH connection attempt detected!\n");
            alert_count++;
        }

        // check if alert threshold has been reached
        if(alert_count >= MAX_ALERT_THRESHOLD)
        {
            printf("Intrusion detected. Taking action...\n");
            // action taken here, such as emailing sysadmin
            exit(1);
        }
    }

    return 0;
}