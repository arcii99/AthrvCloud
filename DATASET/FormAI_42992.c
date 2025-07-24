//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#define BUF_SIZE 1024
#define PORT_NUM 8888
#define MAX_CONN 10

int main(void) {
    int server_fd, new_socket, opt = 1;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    char buffer[BUF_SIZE] = {0};
    char resp[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>QoS Monitor</h1><p>Monitoring network Quality of Service...</p></body></html>\r\n";

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUM);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONN) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("QoS Monitor listening on port %d\n", PORT_NUM);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Send welcome message
        send(new_socket, resp, strlen(resp), 0);

        printf("New connection accepted from %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

        // Receive data
        while (1) {
            int bytes = read(new_socket, buffer, BUF_SIZE);

            if (bytes < 0) {
                perror("read failed");
                exit(EXIT_FAILURE);
            }

            if (bytes == 0) {
                printf("Connection closed by %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
                break;
            }

            printf("Received %d bytes from %s:%d\n", bytes, inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
            printf("Data: %s\n", buffer);

            // Analyze the data and monitor QoS
            // ...

            // Send acknowledgment
            char ack[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><p>QoS monitored successfully!</p></body></html>\r\n";
            send(new_socket, ack, strlen(ack), 0);
        }

        close(new_socket);
    }

    return 0;
}