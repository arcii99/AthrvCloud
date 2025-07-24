//FormAI DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    struct sockaddr_in server_address, client_address;
    int server_socket, client_socket, addr_len, length_read, opt = 1, received_data_len;
    char buffer[BUFFER_SIZE];

    //Creating a socket
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket == -1) {
        perror("Unable to create a socket");
        exit(EXIT_FAILURE);
    }

    //Block unwanted ports
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Unable to set socket options");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8080);

    //Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Unable to bind the socket to the address and port");
        exit(EXIT_FAILURE);
    }

    //Listening to incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Unable to listen to incoming connections");
        exit(EXIT_FAILURE);
    }

    //Accepting incoming connections
    addr_len = sizeof(client_address);
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&addr_len))) {
        printf("Connection established from the IP Address: %s and Port Number: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        //Reading incoming packets
        received_data_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (received_data_len < 0) {
            perror("Unable to receive a packet");
            exit(EXIT_FAILURE);
        }
        printf("Data Received from the IP Address: %s and Port Number: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        printf("%s\n", buffer);

        //Block packets containing specific content
        if (strstr(buffer, "bad content") != NULL) {
            printf("Blocked bad data from the IP Address: %s and Port Number: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            close(client_socket);
            continue;
        }

        //Sending response packets
        length_read = read(client_socket, buffer, BUFFER_SIZE);
        send(client_socket, buffer, length_read, 0);
        printf("Response Sent to the IP Address: %s and Port Number: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        //Closing the client socket
        close(client_socket);
    }

    //Closing the server socket
    close(server_socket);
    return 0;
}