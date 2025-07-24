//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_DEVICES 50
#define MAX_DEVICE_NAME 20
#define BUFFER_SIZE 1024

struct Device {
    char name[MAX_DEVICE_NAME];
    char ip[INET_ADDRSTRLEN];
};

void map_network_topology(struct Device* devices, int num_devices) {
    int sock, len, n, i;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);

    for (i = 0; i < num_devices; i++) {
        if (inet_pton(AF_INET, devices[i].ip, &addr.sin_addr) <= 0) {
            printf("Invalid IP address: %s\n", devices[i].ip);
            continue;
        }

        // Create socket
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Failed to create socket for device: %s\n", devices[i].name);
            continue;
        }

        // Connect to device
        if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
            printf("Failed to connect to device: %s\n", devices[i].name);
            continue;
        }

        // Send request
        char request[] = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n";
        if (send(sock, request, strlen(request), 0) < 0) {
            printf("Failed to send request to device: %s\n", devices[i].name);
            continue;
        }

        // Receive response
        memset(buffer, 0, sizeof(buffer));
        if ((n = recv(sock, buffer, sizeof(buffer)-1 ,0)) < 0) {
            printf("Failed to receive response from device: %s\n", devices[i].name);
            continue;
        }

        // Parse response to get device name
        char device_name[MAX_DEVICE_NAME];
        char* ptr;
        if ((ptr = strstr(buffer, "Server: ")) == NULL) {
            printf("Failed to parse response from device: %s\n", devices[i].name);
            continue;
        }
        ptr += strlen("Server: ");
        len = strcspn(ptr, "\r\n");
        strncpy(device_name, ptr, len);
        device_name[len] = '\0';

        // Close socket
        close(sock);

        // Print mapping
        printf("Device %s with IP Address %s is connected to Device %s\n", devices[i].name, devices[i].ip, device_name);
    }
}

int main() {
    struct Device devices[MAX_DEVICES] = {
        {"Router", "192.168.1.1"},
        {"Switch 1", "192.168.1.2"},
        {"Switch 2", "192.168.1.3"},
        {"Printer", "192.168.1.4"},
        {"Server", "192.168.1.5"},
        {"Computer 1", "192.168.1.6"},
        {"Computer 2", "192.168.1.7"}
    };
    int num_devices = 7;

    map_network_topology(devices, num_devices);

    return 0;
}