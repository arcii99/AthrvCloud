//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    int sock, n, signal;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];
    bool connected = false;

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }
 
    // set server address and port
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("192.168.0.1");
    server.sin_port = htons(80);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server");
        return EXIT_FAILURE;
    }

    connected = true;

    while (connected) {
        // send request
        sprintf(buffer, "GET / HTTP/1.1\r\n\r\n");
        n = send(sock, buffer, strlen(buffer), 0);

        if (n < 0) {
            perror("Failed to send request");
            break;
        }

        // receive response
        memset(response, 0, BUFFER_SIZE);
        n = recv(sock, response, BUFFER_SIZE, 0);

        if (n <= 0) {
            perror("Failed to receive response");
            break;
        }

        // extract signal strength from response
        char *signal_ptr = strstr(response, "signal strength: ");

        if (signal_ptr != NULL) {
            sscanf(signal_ptr + strlen("signal strength: "), "%d", &signal);
            printf("Signal Strength: %d dBm\n", signal);
        }

        // wait for a while
        sleep(1);
    }

    // close socket
    close(sock);

    return EXIT_SUCCESS;
}