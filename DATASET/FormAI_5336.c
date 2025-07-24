//FormAI DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in server;
    int socket_desc;
    int current_port = 1;
    
    // Clear memory of the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);  // Get IP address from command line argument
    
    while(current_port <= 65535) {
        server.sin_port = htons(current_port);
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        
        if(socket_desc == -1) {
            printf("Could not create socket");
        }
        
        // Try to connect to the port
        if(connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
            printf("Port %d is closed \n", current_port);
            close(socket_desc);
        } else {
            printf("Port %d is open \n", current_port);
            close(socket_desc);
        }
        
        current_port++;
    }
    
    return 0;
}