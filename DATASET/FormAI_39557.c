//FormAI DATASET v1.0 Category: Firewall ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LENGTH 15
#define MAX_PORT_LENGTH 5
#define MAX_RULES 10
#define MAX_ATTEMPTS 5

// Struct to hold firewall rule information
struct fw_rule {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    bool allowed;
};

int main() {

    // Initialize firewall rules
    struct fw_rule rules[MAX_RULES];
    int num_rules = 0;

    // Prompt user to add rules
    while (num_rules < MAX_RULES) {
        printf("Enter IP address (or type 'done' to finish): ");
        char ip[MAX_IP_LENGTH];
        fgets(ip, MAX_IP_LENGTH, stdin);
        ip[strcspn(ip, "\n")] = '\0'; // remove trailing newline

        if (strcmp(ip, "done") == 0) {
            break;
        }

        printf("Enter port number: ");
        char port[MAX_PORT_LENGTH];
        fgets(port, MAX_PORT_LENGTH, stdin);
        port[strcspn(port, "\n")] = '\0'; // remove trailing newline

        // Verify that the port number is valid
        char *endptr;
        long int port_num = strtol(port, &endptr, 10);
        if (*endptr != '\0' || port_num < 1 || port_num > 65535) {
            printf("Invalid port number. Please enter a number between 1 and 65535.\n");
            continue;
        }

        char allowed_input[4];
        printf("Should this IP address be allowed? (y/n): ");
        fgets(allowed_input, 4, stdin);
        allowed_input[strcspn(allowed_input, "\n")] = '\0'; // remove trailing newline

        bool allowed;
        if (strcmp(allowed_input, "y") == 0) {
            allowed = true;
        } else if (strcmp(allowed_input, "n") == 0) {
            allowed = false;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            continue;
        }

        // Add rule to array
        strcpy(rules[num_rules].ip, ip);
        strcpy(rules[num_rules].port, port);
        rules[num_rules].allowed = allowed;

        num_rules++;
    }

    // Prompt user for IP address and port of incoming connection
    char incoming_ip[MAX_IP_LENGTH];
    char incoming_port[MAX_PORT_LENGTH];
    printf("Incoming connection...\n");
    printf("IP address: ");
    fgets(incoming_ip, MAX_IP_LENGTH, stdin);
    incoming_ip[strcspn(incoming_ip, "\n")] = '\0'; // remove trailing newline
    printf("Port number: ");
    fgets(incoming_port, MAX_PORT_LENGTH, stdin);
    incoming_port[strcspn(incoming_port, "\n")] = '\0'; // remove trailing newline

    // Check firewall rules
    bool allowed_incoming = false;
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, incoming_ip) == 0 && strcmp(rules[i].port, incoming_port) == 0) {
            allowed_incoming = rules[i].allowed;
            break;
        }
    }

    // Determine action to take based on firewall rules
    if (allowed_incoming) {
        printf("Connection allowed.\n");
    } else {
        printf("Connection blocked.\n");

        // Implement paranoid behavior
        int attempts = 0;
        while (true) {
            printf("Warning: Incoming connection from blocked IP address. Initiating security protocols...\n");

            // Generate random number between 1 and 20
            int random_num = (rand() % 20) + 1;

            if (attempts >= MAX_ATTEMPTS) {
                printf("Security breach detected. Initiating emergency shutdown.\n");
                exit(0);
            } else if (random_num <= 5) {
                printf("Security breach detected. Initiating firewall lockdown for 10 minutes.\n");
                sleep(600);
            } else if (random_num <= 10) {
                printf("Security breach detected. Initiating IP blocking.\n");
                printf("Enter duration of block in minutes: ");
                int block_duration;
                scanf("%d", &block_duration);
                sleep(block_duration * 60); // convert minutes to seconds
                break;
            } else {
                printf("Security breach detected. Initiating system scan.\n");
                printf("Scan complete. No malicious software detected.\n");
                break;
            }

            attempts++;
        }
    }

    return 0;
}