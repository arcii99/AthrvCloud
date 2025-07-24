//FormAI DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CONN 10 // Max number of simultaneous connections
#define PORT_NUM 8888 // Port number for listening

// Function to handle client requests
void handle_request(int connfd) {
    char resp[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n<!DOCTYPE html><html><body><h1>Hello World!</h1></body></html>\r\n";
    write(connfd, resp, strlen(resp)); // Sends response to client
    close(connfd); // Closes connection
}

// Function to create and run server
void init_server() {
    int listenfd, connfd, pid;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;

    // Creates socket for listening
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Sets socket options
    int enable = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

    // Sets up server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT_NUM);

    // Binds the socket to the server address
    if(bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listens for incoming connections
    if(listen(listenfd, MAX_CONN) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server running on port %d\n", PORT_NUM);

    while(1) {
        // Accepts incoming connection
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &cliaddr_len);
        if(connfd == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        
        pid = fork(); // Forks process to handle client request

        if(pid == -1) {
            printf("Error creating child process\n");
            continue;
        } else if(pid == 0) { // Child process
            close(listenfd); // Closes listening socket
            handle_request(connfd); // Handles client request
            exit(0);
        } else { // Parent process
            close(connfd); // Closes connection
        }
    }
}

int main() {
    init_server(); // Calls function to create and run server
    return 0;
}