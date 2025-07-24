//FormAI DATASET v1.0 Category: Socket programming ; Style: Romeo and Juliet
/* Romeo and Juliet Socket Programming Example
 * Author: Your Name
 * Date: Today's Date
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main() {
    int server_fd, new_socket, val_read;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from the other side\n";
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Dear Romeo, I cannot create a socket. I am not worthy...\n");
        return -1;
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Dear Juliet, I cannot set socket options. I am but a fool...\n");
        return -1;
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Dear Romeo, I cannot bind the socket. Art thou angry with me?\n");
        return -1;
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Dear Juliet, I cannot listen for incoming connections. Please forgive me...\n");
        return -1;
    }
    
    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        printf("Dear Romeo, I cannot accept thy connection. My heart is heavy...\n");
        return -1;
    }
    
    // Read from the client socket
    val_read = read(new_socket, buffer, 1024);
    printf("Dear Juliet, I have received thy message: %s\n", buffer);
    
    // Send a message back to the client
    send(new_socket, hello, strlen(hello), 0);
    printf("Dear Romeo, I have sent thee a message. Pray, did'st thou receive it?\n");
    
    return 0;
}