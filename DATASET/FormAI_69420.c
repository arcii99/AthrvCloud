//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 256

int main()
{
    char input[MAX_INPUT_LEN];
    int threshold = 10;
    int count = 0;

    while (1)
    {
        fgets(input, MAX_INPUT_LEN, stdin);

        if (strstr(input, "attack") != NULL)
        {
            count++;

            if (count >= threshold)
            {
                printf("WARNING: Intrusion detected! Attack count: %d\n", count);
                // Execute a system command to block the IP address or take other actions
                system("sudo iptables -A INPUT -s attacker_ip_address -j DROP"); 
                break;
            }
        }
        else
        {
            count = 0;
        }
    }

    return 0;
}