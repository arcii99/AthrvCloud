//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

int main(int argc, char const *argv[])
{
    int sockfd;
    struct sockaddr_in scanner_addr;
    struct sockaddr_in device_addr;
    char recv_message[1024];
    int recv_length;
    char scanner_ip[17];
    int scanner_port;
    char device_name[1024];
    char device_ip[17];
    char device_mac[18];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup scanner address
    scanner_addr.sin_family = AF_INET;
    scanner_addr.sin_addr.s_addr = INADDR_ANY;
    scanner_addr.sin_port = htons(PORT);

    // Bind the scanner socket with the scanner address
    if (bind(sockfd, (struct sockaddr *)&scanner_addr, sizeof(scanner_addr)) < 0)
    {
        perror("Bind socket failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(sockfd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Wireless Network Scanner started...\n");
    printf("Listening on port %d\n", PORT);

    while (1)
    {
        int device_sockfd;

        // Accept incoming connection
        if ((device_sockfd = accept(sockfd, (struct sockaddr *)&device_addr, (socklen_t *)&device_addr)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Device connected\n");

        // Read device name
        memset(recv_message, 0, sizeof(recv_message));
        if ((recv_length = read(device_sockfd, recv_message, 1024)) < 0)
        {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }
        recv_message[recv_length] = '\0';
        strcpy(device_name, recv_message);

        // Read device IP
        memset(recv_message, 0, sizeof(recv_message));
        if ((recv_length = read(device_sockfd, recv_message, 1024)) < 0)
        {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }
        recv_message[recv_length] = '\0';
        strcpy(device_ip, recv_message);

        // Read device MAC
        memset(recv_message, 0, sizeof(recv_message));
        if ((recv_length = read(device_sockfd, recv_message, 1024)) < 0)
        {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }
        recv_message[recv_length] = '\0';
        strcpy(device_mac, recv_message);

        // Print device info
        printf("Device name: %s\n", device_name);
        printf("Device IP: %s\n", device_ip);
        printf("Device MAC: %s\n", device_mac);

        strcpy(scanner_ip, inet_ntoa(scanner_addr.sin_addr));
        scanner_port = ntohs(scanner_addr.sin_port);

        // Send scanner info to the device
        memset(recv_message, 0, sizeof(recv_message));
        sprintf(recv_message, "Scanner IP: %s\nScanner Port: %d\n", scanner_ip, scanner_port);
        if (send(device_sockfd, recv_message, strlen(recv_message), 0) < 0)
        {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        close(device_sockfd);
    }

    return 0;
}