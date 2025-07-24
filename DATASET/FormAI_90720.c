//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_IP_LENGTH 16

struct FirewallRule {
    char ip[MAX_IP_LENGTH];
    int port;
    bool allowed;
};

struct Firewall {
    int numRules;
    struct FirewallRule rules[MAX_RULES];
};

struct Firewall createFirewall() {
    struct Firewall firewall;
    firewall.numRules = 0;
    return firewall;
}

void addRule(struct Firewall* firewall, char* ip, int port, bool allowed) {
    if (firewall->numRules >= MAX_RULES) {
        printf("Sorry, the maximum number of rules has been reached.\n");
        return;
    }
    
    strcpy(firewall->rules[firewall->numRules].ip, ip);
    firewall->rules[firewall->numRules].port = port;
    firewall->rules[firewall->numRules].allowed = allowed;
    firewall->numRules++;
    
    printf("Hooray! Rule added successfully.\n");
}

bool checkFirewall(struct Firewall* firewall, char* ip, int port) {
    for (int i = 0; i < firewall->numRules; i++) {
        if (strcmp(firewall->rules[i].ip, ip) == 0 && firewall->rules[i].port == port) {
            if (firewall->rules[i].allowed) {
                printf("Access granted! Woohoo!\n");
                return true;
            } else {
                printf("Access denied! Boo!\n");
                return false;
            }
        }
    }
    
    // No rule found
    printf("No matching rule found in the firewall. Access denied!\n");
    return false;
}

int main() {
    struct Firewall myFirewall = createFirewall();
    
    addRule(&myFirewall, "192.168.1.1", 80, true);
    addRule(&myFirewall, "10.0.0.1", 443, false);
    addRule(&myFirewall, "172.16.0.1", 22, true);
    
    checkFirewall(&myFirewall, "192.168.1.1", 80);
    checkFirewall(&myFirewall, "10.0.0.1", 443);
    checkFirewall(&myFirewall, "172.16.0.2", 22);
    
    return 0;
}