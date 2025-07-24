//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Usage: ./qosmon IP_ADDRESS");
        exit(EXIT_FAILURE);
    }
    
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // Define the IP address and port of the server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(5000);
    
    // Send a test message to the server
    char *message = "Test message";
    int message_length = strlen(message);
    
    int bytes_sent = sendto(sockfd, message, message_length, 0, (struct sockaddr *)&server, sizeof(server));
    if (bytes_sent < 0) {
        perror("Error sending test message");
        exit(EXIT_FAILURE);
    }
    
    // Receive the response from the server
    char buffer[BUFFER_SIZE] = {0};
    int server_address_length = sizeof(server);
    int bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server, &server_address_length);
    if (bytes_received < 0) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    
    // Check the Quality of Service based on the response from the server
    if (strcmp(buffer, "Good QoS") == 0) {
        printf("The network Quality of Service is good\n");
    } else if (strcmp(buffer, "Fair QoS") == 0) {
        printf("The network Quality of Service is fair\n");
    } else if (strcmp(buffer, "Poor QoS") == 0) {
        printf("The network Quality of Service is poor\n");
    } else {
        printf("Unknown Quality of Service\n");
    }
    
    close(sockfd);
    return 0;
}