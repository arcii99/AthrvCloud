//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define PORT 8080  // default port number
#define MAX_CLIENTS 5  // maximum number of clients
#define BUFSIZE 1024  // size of buffer used for sending and receiving data

volatile sig_atomic_t stop = 0;  // flag for stopping the program

// function to handle SIGINT signal and stop the program gracefully
void sigint_handler(int sig)
{
    stop = 1;
}

// main function
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, client_sockets[MAX_CLIENTS], client_count = 0; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[BUFSIZE] = {0}; 

    // create a TCP socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // set socket options to reuse the address and port number
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    // initialize the server address structure
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    // bind the socket to the address and port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // listen for incoming connections from clients
    if (listen(server_fd, MAX_CLIENTS) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Server is listening on port %d\n", PORT);

    // set up signal handler for SIGINT signal
    signal(SIGINT, sigint_handler);

    // wait for incoming connections and handle them
    while (!stop) 
    { 
        // check if there are any new incoming connections from clients
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 

        // add the new client socket to the list of client sockets
        client_sockets[client_count++] = new_socket;

        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port)); 

        // send a welcome message to the client
        snprintf(buffer, BUFSIZE, "Welcome to the server!\n");
        send(new_socket, buffer, strlen(buffer), 0); 

        // receive data from the client and send it back to all other clients
        while (!stop) 
        {   
            // clear the buffer
            memset(buffer, 0, BUFSIZE);

            // receive data from the client
            int bytes_received = recv(new_socket, buffer, BUFSIZE, 0);
            if (bytes_received <= 0)
            {
                // client disconnected
                printf("Client %s:%d disconnected\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                break;
            }

            // print the received data
            printf("Received data from %s:%d: %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);

            // send the received data to all other clients
            for (int i = 0; i < client_count; i++) 
            {
                if (client_sockets[i] != new_socket) 
                {
                    send(client_sockets[i], buffer, strlen(buffer), 0);
                }
            }
        }

        // remove the client socket from the list of client sockets
        for (int i = 0; i < client_count; i++) 
        {
            if (client_sockets[i] == new_socket)
            {
                client_sockets[i] = client_sockets[--client_count];
                break;
            }
        }

        close(new_socket); 
    } 

    // close all client sockets
    for (int i = 0; i < client_count; i++)
    {
        close(client_sockets[i]);
    }

    // close the server socket
    close(server_fd);
    
    printf("Server closed\n");

    return 0; 
}