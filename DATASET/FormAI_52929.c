//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 6666

int main() {
    int client_fd;
    struct sockaddr_in server_addr;
    char *scan_request = "scan";
    int len = strlen(scan_request);
    char buffer[1024] = {0};
    int valread;

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("Invalid address\n");
        return -1;
    }

    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    send(client_fd, scan_request, len, 0);

    valread = read(client_fd, buffer, 1024);
    printf("%s", buffer);
    close(client_fd);
    return 0;
}