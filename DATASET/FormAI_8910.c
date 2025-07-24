//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_BUFFER 1024

void add_device(char *ip, char *mac, int *num_devices, char devices[][MAX_BUFFER]) {
    char device[MAX_BUFFER];
    snprintf(device, MAX_BUFFER, "Device %d: IP: %s, MAC: %s", *num_devices, ip, mac);
    strcpy(devices[*num_devices], device);
    (*num_devices)++;
}

int main() {
    int sock, num_devices = 0;
    struct sockaddr_in server;
    char buffer[MAX_BUFFER] = {0}, devices[MAX_DEVICES][MAX_BUFFER];
    char *ip, *mac, *ptr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    // Setup server address
    memset(&server, '0', sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8000);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return -1;
    }

    // Receive topology data
    while (read(sock, buffer, MAX_BUFFER)) {
        ptr = strtok(buffer, ",");
        while (ptr != NULL) {
            ip = ptr;
            ptr = strtok(NULL, ",");
            mac = ptr;
            add_device(ip, mac, &num_devices, devices);
            ptr = strtok(NULL, ",");
        }
    }

    // Print network topology
    printf("Network topology:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s\n", devices[i]);
    }

    return 0;
}