//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define constants
#define MAX_ALLOWED_IPS 5
#define MAX_IP_ADDRESS_LENGTH 15
#define MAX_PACKET_LENGTH 1024

//Structures to hold IP addresses and packets
typedef struct {
    char ip_address[MAX_IP_ADDRESS_LENGTH];
} IpAddress;

typedef struct {
    char packet[MAX_PACKET_LENGTH];
} Packet;

//Declare global variables
IpAddress allowed_ips[MAX_ALLOWED_IPS];
int num_allowed_ips = 0;

//Function to add allowed IP addresses to the firewall
void add_allowed_ip(char* ip) {
    if (num_allowed_ips < MAX_ALLOWED_IPS) {
        strcpy(allowed_ips[num_allowed_ips].ip_address, ip);
        num_allowed_ips++;
        printf("New IP address added to allowed list: %s\n", ip);
    } else {
        printf("Max number of allowed IPs reached, cannot add new IP.\n");
    }
}

//Function to check if an IP is allowed or not
int is_ip_allowed(char* ip) {
    for (int i = 0; i < num_allowed_ips; i++) {
        if (strcmp(allowed_ips[i].ip_address, ip) == 0) {
            return 1;
        }
    }
    return 0;
}

//Function to process packets and decide whether to allow or block
void process_packet(Packet p) {
    if (is_ip_allowed(p.packet)) {
        printf("Packet allowed: %s\n", p.packet);
    } else {
        printf("Packet blocked: %s\n", p.packet);
    }
}

//Main function to test the firewall
int main() {
    add_allowed_ip("192.168.1.100");
    add_allowed_ip("192.168.1.101");
    add_allowed_ip("192.168.1.102");
    add_allowed_ip("10.0.0.1");
    add_allowed_ip("10.0.0.2");
    add_allowed_ip("10.0.0.3");
    
    Packet p;
    strcpy(p.packet, "192.168.1.101: GET /index.html HTTP/1.1");
    process_packet(p);
    
    strcpy(p.packet, "10.0.0.4: POST /login.php HTTP/1.1");
    process_packet(p);
    
    strcpy(p.packet, "192.168.1.103: DELETE /important_file.txt HTTP/1.1");
    process_packet(p);
    
    return 0;
}