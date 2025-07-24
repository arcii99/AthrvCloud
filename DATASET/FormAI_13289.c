//FormAI DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 5000

int main(int argc, char *argv[]) {
    int server_socket, client_socket, result, len;
    struct sockaddr_in server_address, client_address;
    char buffer[1024];
    float data[100];
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("ERROR: Could not create socket");
        exit(1);
    }
    
    // Set server structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
    
    // Bind socket
    result = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (result < 0) {
        perror("ERROR: Could not bind socket");
        exit(1);
    }
    
    // Listen for connections
    result = listen(server_socket, 5);
    if (result < 0) {
        perror("ERROR: Could not listen for connections");
        exit(1);
    }
    
    // Accept connection from client
    len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &len);
    if (client_socket < 0) {
        perror("ERROR: Could not accept connection from client");
        exit(1);
    }
    
    // Receive data from client
    memset(buffer, 0, sizeof(buffer));
    result = recv(client_socket, buffer, sizeof(buffer), 0);
    if (result < 0) {
        perror("ERROR: Could not receive data from client");
        exit(1);
    }
    
    // Convert data from buffer to float array
    char *pch = strtok(buffer, ",");
    int i = 0;
    while (pch != NULL) {
        data[i] = atof(pch);
        pch = strtok(NULL, ",");
        i++;
    }
    
    // Calculate and send statistical information
    float sum = 0, mean, variance = 0, std_deviation;
    int n = i;
    
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    mean = sum / n;
    
    for (i = 0; i < n; i++) {
        variance += pow((data[i] - mean), 2);
    }
    variance /= n;
    std_deviation = sqrt(variance);
    
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "Mean = %f\nVariance = %f\nStandard Deviation = %f\n", mean, variance, std_deviation);
    result = send(client_socket, buffer, strlen(buffer), 0);
    if (result < 0) {
        perror("ERROR: Could not send data to client");
        exit(1);
    }
    
    // Close sockets
    close(client_socket);
    close(server_socket);
    
    return 0;
}