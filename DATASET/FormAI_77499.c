//FormAI DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // specify server address and port to connect to
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    serv_addr.sin_port = htons(8000);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // send message to server
    char *message = "Hello, server!";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    char buffer[1024] = {0};
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    
    // print response
    printf("Server response: %s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}