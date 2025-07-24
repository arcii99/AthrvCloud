//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pthread.h>

#define PORT 8080

void *handle_connection(void *);

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
      
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Forcefully attaching socket to the PORT
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind the socket to the given address
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    puts("Server running on port 8080");
      
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                           (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_connection, 
                             (void *)&new_socket) < 0) {
            perror("could not create thread");
        }
    }
    return 0;
}

void *handle_connection(void *socket_desc) {
    int sock = *(int*)socket_desc;
    int read_size;
    char message[1000];
    char *hello = "Hello from server";
     
    // Send welcome message to the client
    write(sock , hello , strlen(hello));
     
    // Receive message from the client
    while ((read_size = recv(sock , message , 1000 , 0)) > 0) {
        // Send message back to the client
        write(sock , message , strlen(message));
    }
      
    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }
    // Free the socket pointer
    free(socket_desc);     
    return NULL;
}