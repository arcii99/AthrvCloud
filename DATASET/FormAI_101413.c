//FormAI DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>      /* standard input/output library */ 
#include <sys/socket.h> /* socket library */ 
#include <arpa/inet.h>  /* Internet library */ 
#include <stdlib.h>     /* standard library */
#include <unistd.h>     /* Unix-like operating system API */ 

int main(int argc, char *argv[]) {
    int socket_desc, port;      /* the socket and the port number */
    struct sockaddr_in server;  /* socket struct for the server */ 
    
    /* Check arguments */
    if(argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    /* Create a socket */
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    /* Set up the server socket struct */
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    
    /* Check for open ports */
    for(port=1; port<=65535; port++) {
        server.sin_port = htons(port);
        
        /* Connect to the server */
        if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d - Open\n", port);
        }
        close(socket_desc);
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    }

    return 0;
}