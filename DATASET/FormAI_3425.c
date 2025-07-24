//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PACKET_SIZE 2000
#define PORT 8888
#define IP "127.0.0.1"

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_PACKET_SIZE];
    socklen_t addr_size;
    
    // Create socket for receiving packets
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // Set server address and port
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_port = htons(PORT);
    
    // Bind socket to server address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error binding socket to server");
        exit(EXIT_FAILURE);
    }
    
    // Receive packets and perform intrusion detection
    while (true) {
        struct sockaddr_in client;
        int recv_len;
        addr_size = sizeof(client);
        memset(buffer, 0, MAX_PACKET_SIZE);
        
        // Receive packet
        recv_len = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&client, &addr_size);
        if (recv_len < 0) {
            perror("Error receiving packet");
            exit(EXIT_FAILURE);
        }
        
        // Perform intrusion detection
        if (strstr(buffer, "Unauthorized Access Attempt") != NULL) {
            // Send alert message to central monitoring system
            int central_sock;
            struct sockaddr_in central_server;
            char alert[] = "INTRUSION DETECTED: Unauthorized Access Attempt";
            
            // Create socket for sending alert message to central monitoring system
            central_sock = socket(AF_INET, SOCK_DGRAM, 0);
            if (central_sock < 0) {
                perror("Error creating central socket");
                exit(EXIT_FAILURE);
            }
            
            // Set central monitoring system address and port
            central_server.sin_family = AF_INET;
            central_server.sin_addr.s_addr = inet_addr("192.168.1.100");
            central_server.sin_port = htons(8888);
            
            // Send alert message to central monitoring system
            if (sendto(central_sock, alert, strlen(alert), 0, (struct sockaddr *)&central_server, sizeof(central_server)) < 0) {
                perror("Error sending alert message");
                exit(EXIT_FAILURE);
            }
            
            // Close central monitoring system socket
            close(central_sock);
            
            // Log intrusion detection
            printf("Intrusion detected: Unauthorized Access Attempt from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        }
    }
    
    // Close receiving socket
    close(sock);
    
    return 0;
}