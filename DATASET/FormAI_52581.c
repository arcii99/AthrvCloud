//FormAI DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct firewall_rule {
    char protocol[10];
    char source_address[20];
    char destination_address[20];
    int source_port;
    int destination_port;
};

struct firewall_rule rules[100];
int num_rules = 0;

void add_rule(char * protocol, char * source_address, char * destination_address,
              int source_port, int destination_port) {
    if (num_rules < 100) {
        strcpy(rules[num_rules].protocol, protocol);
        strcpy(rules[num_rules].source_address, source_address);
        strcpy(rules[num_rules].destination_address, destination_address);
        rules[num_rules].source_port = source_port;
        rules[num_rules].destination_port = destination_port;
        num_rules++;
        printf("Rule added successfully.\n");
    } else {
        printf("Error: Maximum number of rules exceeded.\n");
    }
}

int check_rule(char * protocol, char * source_address, char * destination_address,
               int source_port, int destination_port) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].protocol, protocol) == 0 &&
            strcmp(rules[i].source_address, source_address) == 0 &&
            strcmp(rules[i].destination_address, destination_address) == 0 &&
            rules[i].source_port == source_port &&
            rules[i].destination_port == destination_port) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char input[100];
    char protocol[10];
    char source_address[20];
    char destination_address[20];
    int source_port;
    int destination_port;
    
    printf("Welcome to my C firewall example program.\n");
    printf("You can add firewall rules and check if a packet matches a rule.\n");
    
    while (1) {
        printf("Enter 'add' to add a rule or 'check' to check a packet: ");
        fgets(input, sizeof(input), stdin);
        
        if (strcmp(input, "add\n") == 0) {
            printf("Enter protocol (tcp/udp): ");
            fgets(protocol, sizeof(protocol), stdin);
            protocol[strlen(protocol)-1] = '\0';
            
            printf("Enter source address: ");
            fgets(source_address, sizeof(source_address), stdin);
            source_address[strlen(source_address)-1] = '\0';
            
            printf("Enter destination address: ");
            fgets(destination_address, sizeof(destination_address), stdin);
            destination_address[strlen(destination_address)-1] = '\0';
            
            printf("Enter source port: ");
            scanf("%d", &source_port);
            
            printf("Enter destination port: ");
            scanf("%d", &destination_port);
            
            getchar(); // consume newline character
            
            add_rule(protocol, source_address, destination_address, source_port, destination_port);
        } else if (strcmp(input, "check\n") == 0) {
            printf("Enter protocol (tcp/udp): ");
            fgets(protocol, sizeof(protocol), stdin);
            protocol[strlen(protocol)-1] = '\0';
            
            printf("Enter source address: ");
            fgets(source_address, sizeof(source_address), stdin);
            source_address[strlen(source_address)-1] = '\0';
            
            printf("Enter destination address: ");
            fgets(destination_address, sizeof(destination_address), stdin);
            destination_address[strlen(destination_address)-1] = '\0';
            
            printf("Enter source port: ");
            scanf("%d", &source_port);
            
            printf("Enter destination port: ");
            scanf("%d", &destination_port);
            
            getchar(); // consume newline character
            
            if (check_rule(protocol, source_address, destination_address, source_port, destination_port)) {
                printf("Packet matches a rule.\n");
            } else {
                printf("Packet does not match any rule.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    }
    
    return 0;
}