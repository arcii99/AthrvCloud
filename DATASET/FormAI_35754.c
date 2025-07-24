//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5

void *connection_handler(void *);

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, clients[MAX_CLIENTS];
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
     
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
     
    // Bind the socket to given address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d...\n", PORT);

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
     
    // Initialize all client sockets to 0
    for(int i = 0; i < MAX_CLIENTS; i++){
        clients[i] = 0;
    }
     
    while(1)
    {
        // Wait for new connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("New connection , socket fd is %d , ip is : %s , port : %d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
         
        // Find the first available client socket
        int client_idx = -1;
        for(int i = 0; i < MAX_CLIENTS; i++){
            if(clients[i] == 0){
                client_idx = i;
                break;
            }
        }

        // If no client socket is available, reject the connection
        if(client_idx == -1){
            printf("Maximum number of clients reached. Connection rejected.\n");
            close(new_socket);
            continue;
        }

        // Add the new client socket to the clients array
        clients[client_idx] = new_socket;

        // Create a new thread for the new connection
        pthread_t thread_id;
        if( pthread_create( &thread_id , NULL ,  connection_handler , (void*) &clients[client_idx]) < 0)
        {
            perror("could not create thread");
            exit(EXIT_FAILURE);
        }
    }
     
    return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    // Get the socket descriptor
    int sock = *(int*)socket_desc;
    int valread;
    char buffer[1024] = {0};
    char *html_response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Hello World!</h1>";

    // Send the HTTP response to the client
    write(sock , html_response , strlen(html_response));
    printf("HTTP response sent to client\n");

    // Close the client socket and free up space in the clients array
    close(sock);
    *(int*)socket_desc = 0;
    pthread_exit(NULL);
}