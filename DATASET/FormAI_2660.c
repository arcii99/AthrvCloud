//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Invalid usage. Please provide the IP address.\n");
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Specify server address
    struct sockaddr_in server_address;
    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5000);
    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) < 0) {
        perror("Invalid server address");
        return 1;
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    // Send request to server
    char buffer[BUFFER_SIZE];
    memset(buffer, '0', sizeof(buffer));
    strcpy(buffer, "REQUEST: TOPOLOGY");
    write(sock, buffer, strlen(buffer));

    // Receive response from server
    memset(buffer, '0', sizeof(buffer));
    int n = read(sock, buffer, sizeof(buffer)-1);
    if(n < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    buffer[n] = '\0';

    // Parse response and display topology
    printf("Network Topology:\n");
    char *token = strtok(buffer, ",");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    // Close socket
    close(sock);

    return 0;
}