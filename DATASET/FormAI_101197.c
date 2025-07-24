//FormAI DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, connfd, n;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFER_SIZE];
  
    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        return 0;
    }
    else
        printf("Socket successfully created..\n");

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding socket to an IP address and port number
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        return 0;
    }
    else
        printf("Socket successfully bound..\n");

    // Listen for incoming connections
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        return 0;
    }
    else
        printf("Server listening..\n");

    socklen_t len = sizeof(cliaddr);

    // Accept the data packets from client and printing it on server terminal
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd < 0) {
        printf("server acccept failed...\n");
        return 0;
    }
    else
        printf("server acccept the client...\n");

    // Wait for data packets and send back an acknowledgement
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = read(connfd, buffer, sizeof(buffer));
        if (n <= 0) {
            printf("Read error\n");
            break;
        }

        printf("Client: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Server Exit...\n");
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
    
        n = write(connfd, buffer, sizeof(buffer));
        if (n <= 0) {
            printf("Write error\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}