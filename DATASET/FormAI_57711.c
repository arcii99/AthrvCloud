//FormAI DATASET v1.0 Category: Chat server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

// A post-apocalyptic themed chat server program

#define PORT 8080

int server_fd, new_socket, valread;
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);
char buffer[1024] = {0};

int main(int argc, char const *argv[]) {

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }
    
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    }

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }
    
    if (listen(server_fd, 3) < 0) { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }
    
    while (1) {
        
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        }
    
        char *client_ip = inet_ntoa(address.sin_addr);
        
        printf("\nA survivor has joined the chat: %s:%d", client_ip, ntohs(address.sin_port));
        
        // Send the welcome message to the survivor
        char welcome_message[] = {"\nYou have entered the chat. Welcome survivor!\n\n"};
        send(new_socket, welcome_message, strlen(welcome_message), 0);
            
        // Infinite chat loop
        while(1) {
            
            memset(buffer, 0, 1024);
            
            valread = read(new_socket, buffer, 1024); 
            
            // Check if the survivor wants to quit
            if (strncmp(buffer, "bye", 3) == 0) {
                
                printf("\nA survivor has quit the chat: %s:%d\n", client_ip, ntohs(address.sin_port));
                
                // Send the quit message to the survivor
                char quit_message[] = {"\nYou have left the chat. Goodbye survivor!\n\n"};
                send(new_socket, quit_message, strlen(quit_message), 0);
                break;
            
            } else {
                
                // Broadcast the survivor's message
                printf("%s:%d: %s", client_ip, ntohs(address.sin_port), buffer);
                send(new_socket, buffer, strlen(buffer), 0);
            
            }
            
        }
        
        close(new_socket);
    
    }

    return 0;
}