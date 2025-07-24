//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: immersive
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    struct sockaddr_in server_addr, client_addr;
    int server_socket, client_socket, addrlen = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Waiting for incoming connections...\n");

        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        int recv_byte_count, sent_byte_count;
        char buffer[1024] = {0};

        while ((recv_byte_count = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received %d bytes from client\n", recv_byte_count);
            printf("Data: %s\n", buffer);

            if ((sent_byte_count = send(client_socket, buffer, recv_byte_count, 0)) < 0) {
                perror("send failed");
                exit(EXIT_FAILURE);
            }

            if (sent_byte_count != recv_byte_count) {
                printf("Only sent %d out of %d bytes back to client\n", sent_byte_count, recv_byte_count);
            } else {
                printf("Sent %d bytes back to client\n", sent_byte_count);
            }
        }

        if (recv_byte_count == 0) {
            printf("Client closed the connection\n");
        } else if (recv_byte_count < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        close(client_socket);
    }

    return 0;
}