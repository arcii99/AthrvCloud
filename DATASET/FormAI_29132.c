//FormAI DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 15
#define MAX_PORT_LEN 5
#define MAX_PACKET_LEN 1024

// Function to check if the IP address is valid
int is_valid_ip(char *ip) {
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
        if (num < 0 || num > 255) {
            return 0;
        }
        ptr = strtok(NULL, ".");
        if (ptr != NULL) {
            dots++;
        }
    }
    if (dots != 3) {
        return 0;
    }
    return 1;
}

// Function to check if the port is valid
int is_valid_port(char *port) {
    int port_num = atoi(port);
    if (port_num > 0 && port_num <= 65535) {
        return 1;
    }
    return 0;
}

int main() {
    char src_ip[MAX_IP_LEN];
    char dst_ip[MAX_IP_LEN];
    char src_port[MAX_PORT_LEN];
    char dst_port[MAX_PORT_LEN];
    char packet[MAX_PACKET_LEN];
    int block_flag = 0;

    printf("Enter Source IP address: ");
    fgets(src_ip, MAX_IP_LEN, stdin);
    strtok(src_ip, "\n");

    printf("Enter Destination IP address: ");
    fgets(dst_ip, MAX_IP_LEN, stdin);
    strtok(dst_ip, "\n");

    printf("Enter Source Port number: ");
    fgets(src_port, MAX_PORT_LEN, stdin);
    strtok(src_port, "\n");

    printf("Enter Destination Port number: ");
    fgets(dst_port, MAX_PORT_LEN, stdin);
    strtok(dst_port, "\n");

    printf("Enter Packet: ");
    fgets(packet, MAX_PACKET_LEN, stdin);
    strtok(packet, "\n");

    // Validate input for source IP address, destination IP address, source port and destination port
    if (!is_valid_ip(src_ip)) {
        printf("Invalid Source IP address\n");
        exit(1);
    }

    if (!is_valid_ip(dst_ip)) {
        printf("Invalid Destination IP address\n");
        exit(1);
    }

    if (!is_valid_port(src_port)) {
        printf("Invalid Source Port\n");
        exit(1);
    }

    if (!is_valid_port(dst_port)) {
        printf("Invalid Destination Port\n");
        exit(1);
    }

    // Check if packet is malicious
    if (strstr(packet, "malware") != NULL || strstr(packet, "virus") != NULL) {
        printf("Packet blocked. Reason: Malicious Content.\n");
        block_flag = 1;
    }

    // Check if packet is coming from a blacklisted IP address
    if (strcmp(src_ip, "192.168.1.100") == 0 || strcmp(src_ip, "10.0.0.2") == 0) {
        printf("Packet blocked. Reason: Blacklisted Source IP address.\n");
        block_flag = 1;
    }

    // Check if packet is coming from a known port number associated with malware
    if (strcmp(src_port, "1337") == 0 || strcmp(src_port, "4444") == 0) {
        printf("Packet blocked. Reason: Known Port number used by Malware.\n");
        block_flag = 1;
    }

    // Check if packet is going to a known port number associated with malware
    if (strcmp(dst_port, "31337") == 0 || strcmp(dst_port, "8080") == 0) {
        printf("Packet blocked. Reason: Known Port number used by Malware.\n");
        block_flag = 1;
    }

    // Check if packet is going to a blacklisted IP address
    if (strcmp(dst_ip, "192.168.1.1") == 0 || strcmp(dst_ip, "172.16.0.1") == 0) {
        printf("Packet blocked. Reason: Blacklisted Destination IP address.\n");
        block_flag = 1;
    }

    if (!block_flag) {
        printf("Packet passed.\n");
    }

    return 0;
}