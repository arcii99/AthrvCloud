//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
// A statistical example program to simulate a client-server TCP/IP connection

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: could not create socket\n");
        return 1;
    }

    // Prepare server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to server address
    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: could not bind socket to address\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        printf("Error: could not start listening\n");
        return 1;
    }

    // Accept incoming connection
    struct sockaddr_in client_address;
    socklen_t addr_len = sizeof(client_address);
    int client_sock = accept(sock, (struct sockaddr *)&client_address, &addr_len);

    // Send welcome message to client
    char message[] = "Welcome to the server!";
    send(client_sock, message, strlen(message), 0);

    // Receive message from client and display statistics
    char buffer[1024] = {0};
    int read_val;
    double sum = 0;
    int count = 0;
    int max_val = 0;
    int min_val = 1000;
    while ((read_val = read(client_sock, buffer, 1024)) > 0) {
        int value = atoi(buffer);
        sum += value;
        count++;
        if (value > max_val) {
            max_val = value;
        }
        if (value < min_val) {
            min_val = value;
        }
        memset(buffer, 0, 1024);
    }
    printf("Received %d values from client\n", count);
    printf("Maximum value received: %d\n", max_val);
    printf("Minimum value received: %d\n", min_val);
    printf("Sum of values received: %g\n", sum);
    printf("Average value received: %g\n", sum/count);

    // Close connections
    close(sock);
    close(client_sock);
    return 0;
}