//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX 1024 // Maximum size of messages
#define PORT 8080 // Port number
#define SA struct sockaddr

// Function to print error message and exit program
void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to create socket and establish connection with server
int connect_to_server(char* server_address, struct sockaddr_in *servaddr) {
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Failed to create socket");
    }

    bzero(servaddr, sizeof(*servaddr));
    servaddr->sin_family = AF_INET;
    servaddr->sin_port = htons(PORT);

    if (inet_pton(AF_INET, server_address, &servaddr->sin_addr) <= 0) {
        error("Invalid server address");
    }

    if (connect(sockfd, (SA*)servaddr, sizeof(*servaddr)) != 0) {
        error("Connection Failed");
    }

    printf("Connected to server\n");
    return sockfd;
}

// Function to send message to server
void send_to_server(int sockfd, char* message) {
    send(sockfd, message, strlen(message), 0);
}

// Function to receive message from server
void receive_from_server(int sockfd, char* buffer) {
    bzero(buffer, MAX);
    read(sockfd, buffer, sizeof(buffer));
}

int main() {
    int sockfd, n;
    char buffer[MAX];
    char message[MAX];
    struct sockaddr_in servaddr;

    // Prompt user to enter IP address of server
    printf("Enter IP address of server: ");
    char server_address[16];
    fgets(server_address, 16, stdin);

    // Connect to server
    sockfd = connect_to_server(server_address, &servaddr);

    // Prompt user to enter network address to map
    printf("Enter network address to map: ");
    char network_address[16];
    fgets(network_address, 16, stdin);

    // Send network address to server
    send_to_server(sockfd, network_address);

    // Receive response from server
    receive_from_server(sockfd, buffer);

    // Print network topology
    printf("Network Topology:\n");
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}