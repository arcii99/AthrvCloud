//FormAI DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main() {

    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[MAXLINE], response[MAXLINE];
    
    // Creating socket file descriptor
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) <= 0 ) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt Error");
        exit(EXIT_FAILURE);
    }
    
    // Clearing the memory contents 
    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    memset(buffer, '\0', sizeof(buffer));

    // Filling server address details 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Binding socket with address
    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Bind Error");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(listen_fd, 5) < 0) {
        perror("Listen Error");
        exit(EXIT_FAILURE);
    }

    // Server Startup Message
    printf("Server started Listening on port - %d\n", PORT);

    // Server loop
    while (1) {

        unsigned int client_len = sizeof(client_addr);

        // Accepting incoming request
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);

        // Check if connection established
        if (conn_fd < 0) {
            perror("Acception Error");
            exit(EXIT_FAILURE);
        }

        // Retrieve client details 
        char *client_ip = inet_ntoa(client_addr.sin_addr);
        int client_port = ntohs(client_addr.sin_port);

        // Welcome Message 
        printf("Connection established from IP : %s on port : %d\n", client_ip, client_port);

        // Read message from the client
        memset(buffer, '\0', sizeof(buffer));
        int status = read(conn_fd, buffer, MAXLINE);

        // Check if read successful
        if(status < 0) {
            perror("Error Reading Message");
            exit(EXIT_FAILURE);
        }

        // Remove New Line Characters
        buffer[strcspn(buffer, "\r\n")] = 0;

        // Generate Response
        snprintf(response, sizeof(response), "Hello %s! You have reached my web server :) ", buffer);

        // Send response 
        send(conn_fd, response, strlen(response), 0);

        // Close connection 
        close(conn_fd);
    }

    // Close listening socket 
    close(listen_fd);

    return 0;
}