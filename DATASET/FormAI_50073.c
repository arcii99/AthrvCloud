//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 512  // Maximum length of buffer
#define PORT 8080   // Port number

int main(void) {

    struct sockaddr_in server_address, client_address;

    int socket_fd, i, slen = sizeof(client_address) , recv_len;

    char buf[BUFLEN];

    // Create a socket
    if ((socket_fd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Clear memory of server_address structure
    memset((char *) &server_address, 0, sizeof(server_address));

    // Set server properties
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket with the server address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Unable to bind socket");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for data...\n");

    while(1) {
        fflush(stdout);
        
        // Clear buffer
        memset(buf, 0, BUFLEN);

        // Receive data from client
        if ((recv_len = recvfrom(socket_fd, buf, BUFLEN, 0, (struct sockaddr *) &client_address, &slen)) == -1) {
            perror("Failed to receive data from client");
            exit(EXIT_FAILURE);
        }
        
        // Print the data received
        printf("Received packet from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        printf("Data: %s\n", buf);

        // Simulate network latency
        int latency = rand() % 100;
        printf("Network latency: %d ms\n", latency);
        sleep(latency / 1000);

        // Simulate packet drop
        if (rand() % 10 == 0) {
            printf("Packet Dropped!\n");
            continue;
        }

        // Send response to client
        if (sendto(socket_fd, buf, recv_len, 0, (struct sockaddr*) &client_address, slen) == -1) {
            perror("Unable to send response to client");
            exit(EXIT_FAILURE);
        }
    }

    close(socket_fd);
    return 0;
}