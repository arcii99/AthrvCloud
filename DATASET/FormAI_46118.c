//FormAI DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to check if the IP address is valid */
int isValidIP(char *ip) {
    int num, dots = 0;
    char *ptr;
    if (ip == NULL) {
        return 0;
    }
    ptr = strtok(ip, ".");
    if (ptr == NULL) {
        return 0;
    }
    while (ptr) {
        if (!isdigit(*ptr)) {
            return 0;
        }
        num = atoi(ptr);
        if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, ".");
            if (ptr != NULL) {
                dots++;
            }
        } else {
            return 0;
        }
    }
    if (dots != 3) {
        return 0;
    }
    return 1;
}

/* Function to check if the port number is valid */
int isValidPort(char *port) {
    int num;
    char *ptr;
    if (port == NULL) {
        return 0;
    }
    ptr = strtok(port, "-");
    if (ptr == NULL) {
        return 0;
    }
    while (ptr) {
        if (!isdigit(*ptr)) {
            return 0;
        }
        num = atoi(ptr);
        if (num >= 0 && num <= 65535) {
            ptr = strtok(NULL, "-");
            if (ptr != NULL) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

/* Function to add a rule to the firewall */
void addRule(char *rule) {
    FILE *fp;
    fp = fopen("firewall_rules.txt", "a");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }
    fprintf(fp, "%s\n", rule);
    fclose(fp);
    printf("Rule added successfully\n");
}

/* Main function to input and validate the firewall rules */
int main() {
    char input[100];
    char *ptr;
    char *protocol;
    char *srcIP;
    char *dstIP;
    char *ports;
    printf("Please input the rule in the format: protocol,source IP,destination IP,ports\n");
    printf("e.g. tcp,192.168.1.1,192.168.1.2,80-81\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    ptr = strtok(input, ",");
    if (ptr == NULL) {
        printf("Error: Invalid input\n");
        return 1;
    }
    protocol = ptr;
    ptr = strtok(NULL, ",");
    if (ptr == NULL) {
        printf("Error: Invalid input\n");
        return 1;
    }
    srcIP = ptr;
    ptr = strtok(NULL, ",");
    if (ptr == NULL) {
        printf("Error: Invalid input\n");
        return 1;
    }
    dstIP = ptr;
    ptr = strtok(NULL, ",");
    if (ptr == NULL) {
        printf("Error: Invalid input\n");
        return 1;
    }
    ports = ptr;
    if (!isValidIP(srcIP)) {
        printf("Error: Invalid source IP address\n");
        return 1;
    }
    if (!isValidIP(dstIP)) {
        printf("Error: Invalid destination IP address\n");
        return 1;
    }
    if (!isValidPort(ports)) {
        printf("Error: Invalid ports format\n");
        return 1;
    }
    addRule(input);
    return 0;
}