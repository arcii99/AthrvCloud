//FormAI DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char* argv[]) {
    int server_fd, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket Failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt Failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket
    if(bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if(listen(server_fd, 3) < 0) {
        perror("Listen Failed");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        int new_socket;
        struct sockaddr_in client_address;
        
        printf("\nWaiting for connection...\n");
        fflush(stdout);
        
        // Accept incoming connections
        if((new_socket = accept(server_fd, (struct sockaddr*) &client_address, (socklen_t*) &addrlen)) < 0) {
            perror("Accept Failed");
            exit(EXIT_FAILURE);
        }
        
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_address.sin_addr), client_ip, INET_ADDRSTRLEN);
        printf("Connection established with %s:%d\n", client_ip, ntohs(client_address.sin_port));
        
        // Validate client IP
        if(strcmp(client_ip, "192.168.1.10") == 0) {
            printf("Access Denied: Authorized client!\n");
            close(new_socket);
            continue;
        }
        
        // Handle incoming messages
        char buffer[1024] = {0};
        int read_val;
        while((read_val = read(new_socket, buffer, 1024)) > 0) {
            printf("Message received from %s:%d: %s\n", client_ip, ntohs(client_address.sin_port), buffer);
            
            // Validate incoming message
            if(strlen(buffer) < 2) {
                printf("Invalid Message: Minimum 2 characters required!\n");
                continue;
            }
            
            // Filter incoming message
            char filtered[1024] = {0};
            int i, j = 0;
            for(i = 0; buffer[i] != '\0'; i++) {
                if(buffer[i] >= 'A' && buffer[i] <= 'Z') {
                    filtered[j++] = buffer[i] - 'A' + 'a';
                } else if(buffer[i] >= 'a' && buffer[i] <= 'z') {
                    filtered[j++] = buffer[i];
                }
            }
            
            printf("Filtered message: %s\n", filtered);
        }
        
        if(read_val == 0) {
            printf("Connection closed by client.\n");
        } else {
            perror("Read Failed");
        }
        
        close(new_socket);
    }
    
    return 0;
}