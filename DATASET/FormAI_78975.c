//FormAI DATASET v1.0 Category: Firewall ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
    char ip[MAX_SIZE];
    printf("Enter IP address to block: ");
    scanf("%s", ip);
    
    FILE *fp;
    fp = fopen("/etc/firewall.conf", "a");
    
    fprintf(fp, "#Block IP address\n");
    fprintf(fp, "iptables -A INPUT -s %s -j DROP\n", ip);
    
    fclose(fp);
    printf("IP address %s is blocked by the firewall.\n", ip);
    
    return 0;
}