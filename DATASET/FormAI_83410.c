//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
// This program demonstrates the use of TCP/IP to establish a client-server connection
// and transfer scientific data between them.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1" // IP address of server
#define SERVER_PORT 9999      // Port number of server

void send_data(int sock, float data[], int size);
void receive_data(int sock, float data[], int size);

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Failed to create socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Failed to connect to server.\n");
        close(sock);
        return 1;
    }

    printf("Connected to server.\n");

    // Scientific data to be sent to server
    float data[] = {3.14159, 2.71828, 9.80665, 299792458};
    int size = sizeof(data) / sizeof(float);

    // Send data to server
    send_data(sock, data, size);

    // Receive data from server
    receive_data(sock, data, size);

    printf("Data received from server:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.8f\n", data[i]);
    }

    close(sock);
    return 0;
}

// Send scientific data to server
void send_data(int sock, float data[], int size)
{
    char buffer[size * sizeof(float)];
    memcpy(buffer, data, size * sizeof(float));
    send(sock, buffer, size * sizeof(float), 0);
    printf("Data sent to server.\n");
}

// Receive scientific data from server
void receive_data(int sock, float data[], int size)
{
    char buffer[size * sizeof(float)];
    recv(sock, buffer, size * sizeof(float), 0);
    memcpy(data, buffer, size * sizeof(float));
    printf("Data received from server.\n");
}