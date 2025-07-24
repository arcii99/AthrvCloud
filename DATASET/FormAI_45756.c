//FormAI DATASET v1.0 Category: Networking ; Style: irregular
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Specify the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    int connect_status = connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address));
    if(connect_status < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Send a message to the server
    char message[1024] = "Hello, I am the client!";
    int send_status = send(sockfd, message, sizeof(message), 0);
    if(send_status < 0) {
        perror("Error sending message");
        return 1;
    }
    printf("Sent message to server: %s\n", message);

    // Receive a message from the server
    char server_response[1024];
    int recv_status = recv(sockfd, server_response, sizeof(server_response), 0);
    if(recv_status < 0) {
        perror("Error receiving message");
        return 1;
    }
    printf("Received message from server: %s\n", server_response);

    // Close the socket
    close(sockfd);

    return 0;
}