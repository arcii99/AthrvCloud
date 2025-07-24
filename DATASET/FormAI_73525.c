//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER 1024

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: ./topology_mapper <ip_address>\n");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    inet_aton(argv[1], &server_address.sin_addr);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Could not create socket.\n");
        return 1;
    }

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Could not connect to server.\n");
        return 1;
    }

    char buffer[MAX_BUFFER];
    snprintf(buffer, MAX_BUFFER, "topology");
    if (send(socket_fd, buffer, MAX_BUFFER, 0) < 0) {
        printf("Could not send request to server.\n");
        return 1;
    }

    if (recv(socket_fd, buffer, MAX_BUFFER, 0) < 0) {
        printf("Could not receive response from server.\n");
        return 1;
    }

    printf("Network Topology:\n%s", buffer);

    close(socket_fd);
    
    return 0;
}