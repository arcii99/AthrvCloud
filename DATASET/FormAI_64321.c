//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <time.h>

#define SERVER_PORT 5000
#define BUFFER_SIZE 1024

bool check_network_status(int sock) {
    char buffer[BUFFER_SIZE];
    char *message = "ping";
    struct sockaddr_storage client_socket;
    socklen_t client_socket_len;
    
    memset(&client_socket, 0, sizeof(client_socket));
    client_socket_len = sizeof(client_socket);
    
    if (sendto(sock, message, strlen(message), 0, (struct sockaddr *) &client_socket, client_socket_len) == -1) {
        printf("Error: could not send ping message\n");
        close(sock);
        return false;
    }
    
    if (recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client_socket, &client_socket_len) == -1) {
        printf("Error: could not receive ping response\n");
        close(sock);
        return false;
    }
    
    if (strcmp(buffer, "pong") == 0) {
        return true;
    } else {
        printf("Error: received invalid pong response\n");
        close(sock);
        return false;
    }
}

int main() {
    struct sockaddr_in server_address;
    socklen_t server_address_len = sizeof(server_address);
    int server_socket, recv_len;
    char buffer[BUFFER_SIZE];
    char *response = "pong";
    
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        printf("Error: could not create socket\n");
        return 1;
    }
    
    memset(&server_address, 0, server_address_len);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(server_socket, (struct sockaddr *) &server_address, server_address_len) == -1) {
        printf("Error: could not bind socket\n");
        close(server_socket);
        return 1;
    }
    
    while (true) {
        printf("Waiting for ping...\n");
        memset(buffer, 0, BUFFER_SIZE);
        recv_len = recvfrom(server_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &server_address, &server_address_len);

        if (recv_len == -1) {
            printf("Error: could not receive message\n");
            break;
        }
        
        if (strcmp(buffer, "ping") == 0) {
            printf("Received ping\n");
            if (sendto(server_socket, response, strlen(response), 0, (struct sockaddr *) &server_address, server_address_len) == -1) {
                printf("Error: could not send pong message\n");
                break;
            }
        }
    }
    
    close(server_socket);
    return 0;
}