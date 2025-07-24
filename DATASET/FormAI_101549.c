//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main (int argc, char *argv[]) {

    // Ensure proper usage
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Variables
    int sock;
    struct sockaddr_in target;
    char buffer[65535];
    memset(buffer, 0, sizeof(buffer));

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Could not create socket.\n");
        return 1;
    }

    // Set target address
    target.sin_family = AF_INET;
    target.sin_port = htons(80);
    inet_aton(argv[1], &target.sin_addr);

    // Connect to target
    int res = connect(sock, (struct sockaddr *)&target, sizeof(target));
    if (res < 0) {
        printf("Could not connect to %s on port 80.\n", argv[1]);
        close(sock);
        return 1;
    }
    printf("Connected to %s on port 80.\n", argv[1]);

    // Send HTTP request
    char *http_request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    sprintf(buffer, http_request, argv[1]);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response
    int num_bytes = recv(sock, buffer, sizeof(buffer), 0);
    while (num_bytes > 0) {
        printf("%.*s", num_bytes, buffer);
        memset(buffer, 0, sizeof(buffer));
        num_bytes = recv(sock, buffer, sizeof(buffer), 0);
    }

    // Close socket
    close(sock);
    return 0;
}