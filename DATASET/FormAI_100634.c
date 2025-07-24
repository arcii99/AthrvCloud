//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

/*
 * This program scans for wireless networks in paranoid style. 
 * It does this in a unique way by randomly changing its MAC address
 * for every new network it detects.
 */

// Function to generate random MAC address
void generate_mac_address(char* mac) {
    srand(time(NULL));
    sprintf(mac, "%02x:%02x:%02x:%02x:%02x:%02x", (rand() % 256), (rand() % 256), (rand() % 256), (rand() % 256), (rand() % 256), (rand() % 256));
} 

int main() {
    char mac_address[18];
    generate_mac_address(mac_address);
    printf("Current MAC address: %s\n", mac_address);

    // Create socket
    int sock_fd;
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation error");
        return 1;
    }

    // Set socket options to change MAC address
    if (setsockopt(sock_fd, SOL_SOCKET, SO_BINDTODEVICE, "wlan0", strlen("wlan0")) < 0) {
        perror("setsockopt error");
        return 1;
    }

    // Create broadcast address
    struct sockaddr_in broadcast_addr;
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(3000);
    inet_pton(AF_INET, "255.255.255.255", &broadcast_addr.sin_addr);

    // Send broadcast message to detect nearby networks
    char* message = "Who's there?";
    if (sendto(sock_fd, message, strlen(message), 0, (struct sockaddr*)&broadcast_addr, sizeof(broadcast_addr)) < 0) {
        perror("sendto error");
        close(sock_fd);
        return 1;
    }

    // Listen for responses
    struct sockaddr_in sender_addr;
    socklen_t sender_addr_len = sizeof(sender_addr);
    char buffer[MAX_BUF_SIZE];
    int num_bytes;
    while ((num_bytes = recvfrom(sock_fd, buffer, MAX_BUF_SIZE, 0, (struct sockaddr*)&sender_addr, &sender_addr_len)) > 0) {
        // Change MAC address for every new network detected
        generate_mac_address(mac_address);
        printf("Detected network: %s\n", buffer);
        printf("Changed MAC address to: %s\n", mac_address);
        if (setsockopt(sock_fd, SOL_SOCKET, SO_BINDTODEVICE, "wlan0", strlen("wlan0")) < 0) {
            perror("setsockopt error");
            close(sock_fd);
            return 1;
        }
    }

    if (num_bytes < 0) {
        perror("recvfrom error");
        close(sock_fd);
        return 1;
    }

    close(sock_fd);
    return 0;
}