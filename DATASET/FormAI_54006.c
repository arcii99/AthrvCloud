//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080  
#define RESPONSE "<html><head><title>Hello World</title></head><body><p>Hello World!</p></body></html>"

int main() { 

    int sockfd, new_sockfd; 
    struct sockaddr_in server_addr, client_addr; 
    int opt = 1; 
    char buffer[2048] = {0}; 
    int addr_len = sizeof(server_addr); 

    // create socket file descriptor 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) { 
        printf("Error creating socket\n"); 
        return -1; 
    } 

    // set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        printf("Error setting socket options\n"); 
        return -1; 
    }
    
    // configure server address structure 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT); 

    // bind server to address 
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) { 
        printf("Error binding socket to address\n"); 
        return -1; 
    } 

    // listen for incoming connections 
    if (listen(sockfd, 3) < 0) { 
        printf("Error listening for incoming connections\n"); 
        return -1; 
    }

    printf("Server running on port %d...\n", PORT);

    // accept incoming connection and serve message
    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len); 
        if (new_sockfd < 0) { 
            printf("Error accepting incoming connection\n"); 
            return -1; 
        } 
        
        printf("Incoming connection accepted\n");
        
        memset(buffer, 0, sizeof(buffer));
        
        // receive client message
        read(new_sockfd, buffer, 2048); 
        printf("%s\n", buffer); 
        
        // send response
        char* response_header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
        write(new_sockfd, response_header, strlen(response_header)); 
        write(new_sockfd, RESPONSE, sizeof(RESPONSE)); 
        close(new_sockfd); 
    }
    
    close(sockfd); 
    return 0; 
}