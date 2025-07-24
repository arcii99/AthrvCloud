//FormAI DATASET v1.0 Category: Networking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    srand(time(NULL));

    // Open a socket with the following properties
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = rand() % 65535; // Any random port number
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    printf("Surreal Networking Program Initialized\n");
    printf("Socket opened on port %d\n", portno);
    listen(sockfd, 5);

    // Start accepting incoming connections
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    printf("Incoming connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    // Receive data from the connected client
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);

    // Process the received data
    printf("\nReceived data: %s\n", buffer);
    printf("Processing data...\n");
    int i;
    char new_data[256];
    for (i = 0; i < strlen(buffer); i++) {
        int r = rand() % 10;
        if (r < 3) { //Replace each third character with a random character
            new_data[i] = rand() % 256;
        } else {
            new_data[i] = buffer[i];
        }
    }

    // Send the processed data back to the client
    printf("Processed data: %s\n", new_data);
    printf("Sending data back to client...\n");
    n = write(newsockfd, new_data, strlen(new_data));

    // Close the connection
    printf("Closing connection...\n");
    close(newsockfd);
    close(sockfd);
    printf("Connection closed.\n");

    return 0;
}