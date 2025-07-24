//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000

struct device {
    char name[20];
    char ip[15];
    char mac[18];
};

int main(int argc, char *argv[]) {
    struct device devices[10];
    int device_count = 0;
    int i, j;
    int sock;
    struct sockaddr_in server;
    char *message, server_reply[2000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket\n");
    }
    printf("Socket created\n");

    // Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("192.168.1.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    printf("Connected to server\n");

    //Send some data
    message = "GET /devices HTTP/1.1\r\n\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed\n");
        return 1;
    }

    printf("Data sent\n");

    //Receive a response from the server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }

    printf("Reply received\n");
    printf("%s\n", server_reply);

    // Parse response for device information
    char *token, *str;
    str = server_reply;

    while ((token = strtok_r(str, "\n", &str))) {
        if (strstr(token, "DEVICE") != NULL) {
            // Extract device information
            char *name, *ip, *mac;
            name = strtok(token, " ");
            ip = strtok(NULL, " ");
            mac = strtok(NULL, " ");

            // Add device to array
            strcpy(devices[device_count].name, name);
            strcpy(devices[device_count].ip, ip);
            strcpy(devices[device_count].mac, mac);
            device_count++;
        }
    }

    // Print device information
    printf("\nTotal %d devices found:\n\n", device_count);
    for (i = 0; i < device_count; i++) {
        printf("Name: %s\n", devices[i].name);
        printf("IP: %s\n", devices[i].ip);
        printf("MAC: %s\n", devices[i].mac);
        printf("\n");
    }

    // Close socket
    close(sock);

    return 0;
}