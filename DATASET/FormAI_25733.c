//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define PORT 8080 // port number to be used for communication
#define MAX_BUFFER_SIZE 1024 // maximum buffer size for data transmission

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to the given IP and port
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Print server details
    printf("Server running on IP: %s Port: %d\n", inet_ntoa(address.sin_addr), PORT);

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address,
                             (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Set QoS monitor values
    int low_bw = 524288; // in bytes per second
    int high_lat = 300; // in milliseconds

    // Start communication
    while (true) {
        memset(buffer, 0, MAX_BUFFER_SIZE);

        // Receive data and calculate round trip time
        clock_t start = clock();
        valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
        clock_t end = clock();
        double rtt = ((double) (end - start)) / CLOCKS_PER_SEC * 1000; // in milliseconds

        // Calculate bandwidth and latency
        int bytes_recv = strlen(buffer);
        double bw = (double) bytes_recv / rtt * 1000; // in bytes per second
        double lat = rtt / 2;

        // Evaluate QoS
        if (bw < low_bw && lat > high_lat) {
            printf("QoS Alert: Bandwidth is low and latency is high\n");
        } else if (bw < low_bw) {
            printf("QoS Alert: Bandwidth is low\n");
        } else if (lat > high_lat) {
            printf("QoS Alert: Latency is high\n");
        } else {
            printf("QoS is good\n");
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}