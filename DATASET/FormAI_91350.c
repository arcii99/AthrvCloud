//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 12345
#define MAX_CONN 10

int main(){
    int sock_fd, conn_fd, cli_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int opt = 1;

    // Creating socket file descriptor
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if(setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("Setsockopt failed!");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Binding socket to the specified port
    if(bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("Socket binding failed!");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if(listen(sock_fd, MAX_CONN) < 0){
        perror("Error listening for incoming connections!");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections on port %d.\n", PORT);

    while(1){
        cli_len = sizeof(cli_addr);

        // Accepting incoming connections
        if((conn_fd = accept(sock_fd, (struct sockaddr *)&cli_addr, (socklen_t *)&cli_len)) < 0){
            perror("Error accepting incoming connection!");
            exit(EXIT_FAILURE);
        }

        printf("Incoming connection request accepted.\n");

        // Receiving data from the client
        if((read(conn_fd, buffer, 1024)) < 0){
            perror("Error receiving data from client!");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buffer);

        // Converting the message to upper case
        for(int i=0; i<strlen(buffer); i++){
            if(buffer[i] >= 'a' && buffer[i] <= 'z')
                buffer[i] -= 32;
        }

        // Sending the modified message back to the client
        if((write(conn_fd, buffer, strlen(buffer))) < 0){
            perror("Error sending data to client!");
            exit(EXIT_FAILURE);
        }

        printf("Sent modified message to client.\n");

        // Closing the connection
        close(conn_fd);
        printf("Connection closed with client.\n");
    }

    return 0;
}