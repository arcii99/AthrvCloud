//FormAI DATASET v1.0 Category: Firewall ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants for the maximum length of IP addresses and ports */
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

/* Define a structure for a firewall rule */
typedef struct FirewallRule {
    char sourceIP[MAX_IP_LENGTH];
    int sourcePort;
    char destIP[MAX_IP_LENGTH];
    int destPort;
} FirewallRule;

/* Define a function to check if a given IP address matches a rule */
int ipMatch(char* ip, char* ruleIP) {
    /* First, split the IP address on dots */
    char* token = strtok(ip, ".");
    char* ruleToken = strtok(ruleIP, ".");
    
    /* Loop through the parts of the IP address */
    while (token != NULL && ruleToken != NULL) {
        /* If the current part of the IP address matches the rule, move to the next part */
        if (strcmp(token, ruleToken) == 0 || strcmp(ruleToken, "*") == 0) {
            token = strtok(NULL, ".");
            ruleToken = strtok(NULL, ".");
        }
        /* If the current part of the IP address does not match the rule, return 0 */
        else {
            return 0;
        }
    }
    
    /* If we made it through the loop and didn't return 0, the IP address matches the rule */
    return 1;
}

/* Define a function to check if a given port matches a rule */
int portMatch(int port, int rulePort) {
    /* If the rulePort is 0, that means the rule matches all ports */
    if (rulePort == 0) {
        return 1;
    }
    
    /* If the port matches the rule, return 1 */
    if (port == rulePort) {
        return 1;
    }
    
    /* Otherwise, return 0 */
    return 0;
}

/* Define a function to check if a given packet matches a rule */
int packetMatches(FirewallRule rule, char* sourceIP, int sourcePort, char* destIP, int destPort) {
    /* Check if the packet matches the source IP and port */
    if (!ipMatch(sourceIP, rule.sourceIP) || !portMatch(sourcePort, rule.sourcePort)) {
        return 0;
    }
    
    /* Check if the packet matches the destination IP and port */
    if (!ipMatch(destIP, rule.destIP) || !portMatch(destPort, rule.destPort)) {
        return 0;
    }
    
    /* If we made it this far, the packet matches the rule */
    return 1;
}

int main() {
    /* Declare an array of firewall rules and initialize it with some sample data */
    FirewallRule rules[3] = {
        {"192.168.1.*", 80, "10.0.0.*", 443},
        {"10.0.0.2", 0, "192.168.1.2", 8080},
        {"*.google.com", 0, "192.168.1.100", 0}
    };
    
    /* Declare some sample packet data */
    char* sourceIP = "192.168.1.2";
    int sourcePort = 80;
    char* destIP = "10.0.0.5";
    int destPort = 443;
    
    /* Loop through the firewall rules and check if the packet matches each one */
    int i;
    for (i = 0; i < 3; i++) {
        if (packetMatches(rules[i], sourceIP, sourcePort, destIP, destPort)) {
            printf("Packet matched rule %d\n", i + 1);
            break;
        }
    }
    
    /* If we made it through all the rules without a match, print a message */
    if (i == 3) {
        printf("Packet did not match any rules\n");
    }
    
    return 0;
}