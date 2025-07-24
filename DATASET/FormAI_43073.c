//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage:\n");
    printf("%s -a [IP address] [-p [port]]\n", program_name);
}

int main(int argc, char *argv[]) {
    int option;
    char *address = NULL;
    int port = DEFAULT_PORT;

    while ((option = getopt(argc, argv, "a:p:")) != -1) {
        switch (option) {
            case 'a':
                address = optarg;
                break;
            case 'p':
                port = atoi(optarg);
                if (port <= 0 || port > 65535) {
                    printf("Invalid port number.\n");
                    return 1;
                }
                break;
            default:
                print_usage(argv[0]);
                return 1;
        }
    }

    if (!address) {
        print_usage(argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, address, &server_addr.sin_addr) != 1) {
        printf("Invalid IP address.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    printf("Connected to server.\n");

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received %d bytes from server.\n", bytes_received);
        //TODO: Add QoS monitoring code here
        memset(buffer, 0, sizeof(buffer));
    }

    if (bytes_received == 0) {
        printf("Connection closed by server.\n");
    } else if (bytes_received < 0) {
        printf("Error receiving data from server: %s\n", strerror(errno));
    }

    close(sock);

    return 0;
}