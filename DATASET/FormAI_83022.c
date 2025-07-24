//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

#define IP "127.0.0.1" // IP address of the target
#define START_PORT 3000 // Starting port for the scan
#define END_PORT 3100 // Ending port for the scan

int main() {
    int socket_descriptor; // Holds the socket descriptor
    struct sockaddr_in server; // Stores the server properties
    char *message, server_reply[2000]; // message stores the raw message to be sent and server_reply stores the server's reply
    
    // Create a socket
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_descriptor == -1) {
        printf("Could not create socket!");
        return 1;
    }

    // Prepare the sockaddr_in server structure
    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_family = AF_INET;
    
    // Scan all the ports in the range
    for(int port = START_PORT; port <= END_PORT; ++port) {
        server.sin_port = htons(port);
        
        // Connect to the server
        if(connect(socket_descriptor, (struct sockaddr *)&server, sizeof(server)) < 0) {
            printf("Port %d is closed.\n", port);
            continue;
        }
        else {
            printf("Port %d is open.\n", port);
        }
    }

    return 0;
}