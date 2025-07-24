//FormAI DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_RULES 100

typedef struct {
    char *ip;
    int port;
} Rule;

void block(Rule *rules, int rule_count, char *ip, int port) {
    for(int i = 0; i < rule_count; i++) {
        if(strcmp(rules[i].ip, ip) == 0 && rules[i].port == port) {
            printf("Access Denied! This IP and port combination is blocked.\n");
            exit(0);
        }
    }
}

int main() {
    Rule rules[MAX_RULES];
    char ip[MAX_IP_LENGTH];
    int port, rule_count = 0;

    //Adding rules
    rules[rule_count].ip = "192.168.0.1";
    rules[rule_count++].port = 80;
    rules[rule_count].ip = "172.16.0.1";
    rules[rule_count++].port = 22;
    rules[rule_count].ip = "10.0.0.1";
    rules[rule_count++].port = 443;

    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter port number: ");
    scanf("%d", &port);

    block(rules, rule_count, ip, port);

    printf("Access granted! You may proceed.\n");

    return 0;
}