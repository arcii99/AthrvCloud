//FormAI DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {  
    // Check arguments
    if (argc < 2) {
        printf("Please provide a valid IP address!\n");
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket!\n");
        return -1;
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    // Convert IP address string to binary form
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address!\n");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection error!\n");
        return -1;
    }

    // Display success message
    printf("Port 80 is open on %s!\n", argv[1]);
    close(sockfd);
    return 0;
}