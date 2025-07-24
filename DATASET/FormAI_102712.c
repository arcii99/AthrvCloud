//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants
#define SERVER_PORT 1234
#define MAX_CONNECTIONS 10
#define MESSAGE_SIZE 1024

// Struct to hold QoS data
typedef struct {
    float latency;
    float bandwidth;
    float packetLossRate;
} QoSData;

// Function to generate random QoS data
QoSData generateRandomQoS() {
    QoSData data;
    data.latency = ((float)rand()/(float)(RAND_MAX)) * 100;
    data.bandwidth = ((float)rand()/(float)(RAND_MAX)) * 100;
    data.packetLossRate = ((float)rand()/(float)(RAND_MAX)) * 100;
    return data;
}

// Function to send QoS data to a client
void sendQoSData(int clientSocket, QoSData data) {
    char message[MESSAGE_SIZE];
    snprintf(message, MESSAGE_SIZE, "QoS Data:\nLatency: %.2f ms\nBandwidth: %.2f Mbps\nPacket Loss Rate: %.2f%%\n", data.latency, data.bandwidth, data.packetLossRate);
    send(clientSocket, message, strlen(message), 0);
}

// Main function
int main(int argc, char *argv[]) {
    int serverSocket, clientSocket, opt = 1;
    struct sockaddr_in address;
    int addressLength = sizeof(address);
    QoSData currentQoS;

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt");
        exit(EXIT_FAILURE);
    }

    // Configure address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);

    // Bind socket to address
    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(serverSocket, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("QoS monitor is running on port %d\n", SERVER_PORT);

    // Accept and handle incoming connections
    while (true) {
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t *)&addressLength)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Generate random QoS data and send to client
        currentQoS = generateRandomQoS();
        sendQoSData(clientSocket, currentQoS);

        // Close connection with client
        close(clientSocket);
    }

    // Close server socket
    close(serverSocket);

    return 0;
}