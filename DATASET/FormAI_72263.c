//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    int bind_result = bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_result < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    char buffer[1024] = {0};
    int buffer_length = 1024;
    struct sockaddr_in client_address;
    int client_address_length = sizeof(client_address);

    while (1) {

        int bytes_received = recvfrom(socket_fd, buffer, buffer_length, MSG_WAITALL, (struct sockaddr *)&client_address, &client_address_length);

        if (bytes_received > 0) {
            printf("Received %d bytes from %s:%d\n", bytes_received, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            // QoS monitoring happens here
            // ...

            // Cheerful response to the client
            char *response = "Data received and QoS monitored with pleasure!";
            sendto(socket_fd, response, strlen(response), 0, (struct sockaddr *)&client_address, client_address_length);
        }
    }

    return 0;
}