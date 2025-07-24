//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    printf("Hey there! Welcome to my unique C Firewall example program\n");
    printf("This program will ask for a IP address and then block it if it is on the blacklisted IP's list\n");

    char *blacklist_ips[] = {"10.0.0.1", "192.168.0.1", "172.16.0.1", "0.0.0.0"};

    char ip[16];
    printf("Enter an IP address: ");
    fgets(ip, 16, stdin);
    strtok(ip, "\n");

    int i;
    for(i = 0; i < 4; i++)
    {
        char *token = strtok(blacklist_ips[i], ".");
        int ips[4];
        int j = 0;

        while(token != NULL)
        {
            ips[j] = atoi(token);
            j++;
            token = strtok(NULL, ".");
        }

        if(ips[0] == atoi(strtok(ip, ".")) && ips[1] == atoi(strtok(NULL, ".")) && ips[2] == atoi(strtok(NULL, ".")) && ips[3] == atoi(strtok(NULL, ".")))
        {
            printf("IP address %s is on the blacklist. Firewall will block this IP address.\n", ip);
            return 0;
        }
    }

    printf("IP address %s is not on the blacklist. Firewall will allow this IP address.\n", ip);
    return 0;
}