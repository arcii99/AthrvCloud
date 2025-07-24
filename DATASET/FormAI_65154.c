//FormAI DATASET v1.0 Category: Firewall ; Style: irregular
/*Welcome to the fantastic world of C Firewall*/
/*Do you want to block incoming requests?*/
/*Or maybe filter outgoing packets?*/
/*We have it all and more!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Start by defining the IP addresses you want to block*/
char *blocked_ips[] = {"192.168.0.1", "10.0.0.1", "172.16.0.1"};

/*Define a function that allows you to add more blocked IPs*/
void add_blocked_ip(char *ip) {
    int num_ips = sizeof(blocked_ips)/sizeof(blocked_ips[0]);
    blocked_ips[num_ips] = ip;
}

/*Now let's define the actual firewall function*/
void firewall(char *ip, char *packet_type) {
    int block = 0;
    int num_ips = sizeof(blocked_ips)/sizeof(blocked_ips[0]);
    
    /*Check if the IP is in the blocked list*/
    for (int i = 0; i < num_ips; i++) {
        if (strcmp(ip, blocked_ips[i]) == 0) {
            block = 1;
            break;
        }
    }
    
    /*Block the packet if necessary*/
    if (block) {
        printf("Packet blocked: %s, %s\n", ip, packet_type);
        exit(1);
    } else {
        printf("Packet allowed: %s, %s\n", ip, packet_type);
    }
}

int main() {
    /*Test the firewall function*/
    firewall("192.168.0.1", "TCP");
    firewall("10.0.0.2", "UDP");
    add_blocked_ip("172.16.0.1");
    firewall("172.16.0.1", "ICMP");
    
    return 0;
}

/*Now you have a simple but effective firewall program to protect your network*/
/*Don't forget to update the blocked_ips array when necessary*/