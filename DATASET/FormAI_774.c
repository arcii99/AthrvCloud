//FormAI DATASET v1.0 Category: Firewall ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct FirewallRule
{
    char *sourceIP;
    char *destinationIP;
    int sourcePort;
    int destinationPort;
};

struct FirewallRule firewall[1000];
int totalFirewallRules = 0;

bool isPacketPermitted(char *sourceIP, char *destinationIP, int sourcePort, int destinationPort)
{
    for(int i=0;i<totalFirewallRules;i++)
    {
        if(strcmp(firewall[i].sourceIP, sourceIP) != 0 && strcmp(firewall[i].sourceIP, "*") != 0)
        {
            continue;
        }
        
        if(strcmp(firewall[i].destinationIP, destinationIP) != 0 && strcmp(firewall[i].destinationIP, "*") != 0)
        {
            continue;
        }
        
        if(firewall[i].sourcePort != sourcePort && firewall[i].sourcePort != -1)
        {
            continue;
        }
        
        if(firewall[i].destinationPort != destinationPort && firewall[i].destinationPort != -1)
        {
            continue;
        }
        
        return true; // Packet is permitted
    }
    
    return false; // Packet is not permitted
}

int main()
{
    // Add some rules to the firewall
    firewall[0].sourceIP = "192.168.0.1";
    firewall[0].destinationIP = "*";
    firewall[0].sourcePort = -1;
    firewall[0].destinationPort = 80;
    totalFirewallRules++;
    
    firewall[1].sourceIP = "*";
    firewall[1].destinationIP = "192.168.0.1";
    firewall[1].sourcePort = 1234;
    firewall[1].destinationPort = -1;
    totalFirewallRules++;
    
    char *sourceIP = "192.168.0.2";
    char *destinationIP = "192.168.0.1";
    int sourcePort = 1234;
    int destinationPort = 80;
    
    if(isPacketPermitted(sourceIP, destinationIP, sourcePort, destinationPort))
    {
        printf("Packet is permitted\n");
    }
    else
    {
        printf("Packet is not permitted\n");
    }
    
    return 0;
}