//FormAI DATASET v1.0 Category: Firewall ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUFF 256
#define FIREWALL_IP "192.168.1.100"          // Firewall IP address
#define SERVER_IP "192.168.1.200"            // Server IP address
#define FIREWALL_PORT 8888                  // Firewall Port number
#define SERVER_PORT 8080                    // Server Port number

int main() {
    int sock_fd, conn_fd, recv_len, send_len;
    char buffer[MAX_BUFF];
    struct sockaddr_in firewall, server, client;
    
    // Creating the socket for communication between firewall and server
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting Firewall address and port number
    firewall.sin_family = AF_INET;
    inet_pton(AF_INET, FIREWALL_IP, &(firewall.sin_addr));
    firewall.sin_port = htons(FIREWALL_PORT);

    // Binding Firewall socket to Firewall address and port
    if(bind(sock_fd, (struct sockaddr *)&firewall, sizeof(firewall)) == -1) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening on the Firewall socket
    if(listen(sock_fd, 5) == -1) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }
    printf("Firewall is Listening at %s:%d\n", FIREWALL_IP, FIREWALL_PORT);
    
    // Accepting connection from Server, to establish secure connection with Firewall
    socklen_t client_len = sizeof(client);
    conn_fd = accept(sock_fd, (struct sockaddr *)&client, &client_len);
    if(conn_fd == -1) {
        perror("Socket accept failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s:%d connected to Firewall\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    
    // Setting Server address and port number
    server.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &(server.sin_addr));
    server.sin_port = htons(SERVER_PORT);

    // Creating the socket for communication between Firewall and Server
    int server_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (server_sock == -1) {
        perror("Could not create socket");
        return 1;
    }

    // Connect to remote Server
    if (connect(server_sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to Server at %s:%d\n", SERVER_IP, SERVER_PORT);
    
    while(1) {
        memset(buffer, 0, MAX_BUFF);
        // Receiving data from Server
        recv_len = recv(server_sock, buffer, MAX_BUFF, 0);
        if(recv_len == 0) {
            printf("Server Disconnected!\n");
            break;
        }
        else if(recv_len < 0) {
            printf("Error receiving data from Server");
            break;
        }
        // Processing the received data
        printf("From Server: %s\n", buffer);
        // Forwarding the data to Server
        send_len = send(conn_fd, buffer, recv_len, 0);
        if(send_len <= 0) {
            printf("Error forwarding data to Firewall");
            break;
        }
        printf("Forwarded %d bytes data to Firewall\n", send_len);
        
        memset(buffer, 0, MAX_BUFF);
        // Receiving data from Client through Firewall
        recv_len = recv(conn_fd, buffer, MAX_BUFF, 0);
        if(recv_len == 0) {
            printf("Client Disconnected!\n");
            break;
        }
        else if(recv_len < 0) {
            printf("Error receiving data from Firewall");
            break;
        }
        // Processing the received data
        printf("From Client: %s\n", buffer);
        // Forwarding the data to Server
        send_len = send(server_sock, buffer, recv_len, 0);
        if(send_len <= 0) {
            printf("Error forwarding data to Server");
            break;
        }
        printf("Forwarded %d bytes data to Server\n", send_len);
    }
    
    // Closing the Firewall and Server sockets
    close(conn_fd);
    close(server_sock);
    close(sock_fd);
    return 0;
}