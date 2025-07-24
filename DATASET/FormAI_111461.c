//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>


#define MAX_CLIENTS 50 // Maximum number of client connections
#define BUFFER_SIZE 2048 // Maximum buffer size


// Global variables
struct client {
    bool in_use;
    int client_socket;
    int server_socket;
    char buffer[BUFFER_SIZE];
    int buffer_size;
    bool closed;
};

struct client clients[MAX_CLIENTS];
fd_set readfds; // File Descriptor Set for select() system call
int max_sd; // Maximum socket descriptor to be monitored


// Function prototypes
static void handle_sigint(int sig);
static void initiate_clients();
static void add_client(int client_socket);
static void remove_client(int client_socket);
static int forward_data(int client_socket, int server_socket);
static void run();


int main(int argc, char* argv[]) {
    // Install signal handler for SIGINT (Ctrl+C)
    struct sigaction sigint_handler;
    memset(&sigint_handler, 0, sizeof(sigint_handler));
    sigint_handler.sa_handler = handle_sigint;
    sigaction(SIGINT, &sigint_handler, NULL);
    
    // initialize clients
    initiate_clients();
    
    // start the proxy server
    run();
    
    return EXIT_SUCCESS;
}


// Signal handler for SIGINT (Ctrl+C)
static void handle_sigint(int sig) {
    (void) sig; // Silence the unused parameter warning
    
    // close all client connections
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].in_use) {
            close(clients[i].client_socket);
            clients[i].in_use = false;
        }
    }
    
    // terminate the program
    exit(EXIT_SUCCESS);
}


// Initialize clients
static void initiate_clients() {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].in_use = false;
    }
}


// Add a client to the list of clients
static void add_client(int client_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (!clients[i].in_use) {
            clients[i].in_use = true;
            clients[i].client_socket = client_socket;
            clients[i].server_socket = -1;
            clients[i].buffer_size = 0;
            clients[i].closed = false;
            return;
        }
    }
    
    // If there are no free client slots, close the new connection
    close(client_socket);
}


// Remove a client from the list of clients
static void remove_client(int client_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].client_socket == client_socket) {
            if (clients[i].server_socket >= 0) {
                close(clients[i].server_socket);
            }
            clients[i].in_use = false;
            break;
        }
    }
}


// Forward data from client to server or vice versa
static int forward_data(int source_socket, int destination_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(source_socket, buffer, sizeof(buffer), 0);
    
    if (bytes_read < 0) {
        // If recv() returned an error
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
            // If there is no more data to be read from source socket, return 0
            return 0;
        } else {
            // If there was some other error, return -1 to indicate a failure
            return -1;
        }
    } else if (bytes_read == 0) {
        // If the source socket was closed
        return -1;
    } else {
        // Forward the data to the destination socket
        send(destination_socket, buffer, bytes_read, 0);
        return bytes_read;
    }
}


// Main function to run the proxy server
static void run() {
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (proxy_socket < 0) {
        perror("Failed to create a socket for the proxy server");
        exit(EXIT_FAILURE);
    }
    
    // Set the socket to non-blocking mode
    fcntl(proxy_socket, F_SETFL, O_NONBLOCK);
    
    // Prepare the address structure for binding
    struct sockaddr_in proxy_address;
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(8080);
    
    // Bind the socket to the specified address and port
    if (bind(proxy_socket, (struct sockaddr*)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Failed to bind the socket to the specified address and port");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming client connections
    if (listen(proxy_socket, 5) < 0) {
        perror("Failed to start listening for incoming client connections");
        exit(EXIT_FAILURE);
    }
    
    // Set the maximum socket descriptor to be monitored
    max_sd = proxy_socket;
    
    // Print a message to indicate that the proxy server is running
    printf("Proxy server is running on port %d\n", ntohs(proxy_address.sin_port));
    
    while (true) {
        // Wait for activity on any of the monitored sockets
        FD_ZERO(&readfds);
        FD_SET(proxy_socket, &readfds);
        
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].in_use) {
                FD_SET(clients[i].client_socket, &readfds);
                
                if (clients[i].server_socket >= 0) {
                    FD_SET(clients[i].server_socket, &readfds);
                }
                
                if (max_sd < clients[i].client_socket) {
                    max_sd = clients[i].client_socket;
                }
                
                if (max_sd < clients[i].server_socket) {
                    max_sd = clients[i].server_socket;
                }
            }
        }
        
        int activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        
        if (activity < 0) {
            if (errno != EINTR) {
                perror("Failed to wait for activity on sockets");
            }
        } else {
            // If there is activity on the proxy server socket, accept the new connection
            if (FD_ISSET(proxy_socket, &readfds)) {
                int client_socket = accept(proxy_socket, NULL, NULL);
                
                if (client_socket < 0) {
                    if (errno == EWOULDBLOCK || errno == EAGAIN) {
                        // If there are no more connections to accept, continue to check the existing connections
                        continue;
                    } else {
                        perror("Failed to accept a new client connection");
                    }
                } else {
                    // Add the new client to the list of clients
                    add_client(client_socket);
                    
                    // Print a message to indicate that a new client has connected
                   printf("Client connected (socket %d)\n", client_socket);
                }
            }
            
            // Forward data between the clients and their target servers (as long as the sockets are valid and not closed)
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].in_use && !clients[i].closed) {
                    
                    // If there is activity on the client socket, forward data from client to server
                    if (FD_ISSET(clients[i].client_socket, &readfds)) {
                        
                        // if a client is fresh connection
                        if (clients[i].server_socket < 0) {
                            // Extract the request URL from the client's buffer
                            char url[1000];
                            sscanf(clients[i].buffer, "GET %s HTTP/1.1", url);
                            
                            // Create a new socket for the target server
                            int server_socket = socket(AF_INET, SOCK_STREAM, 0);
                            
                            if (server_socket < 0) {
                                perror("Failed to create a socket for the target server");
                            } else {
                                // Connect to the target server
                                struct hostent* server = gethostbyname(url);
                                
                                if (!server) {
                                    perror("Failed to get server address");
                                } else {
                                    struct sockaddr_in server_address;
                                    memset(&server_address, 0, sizeof(server_address));
                                    server_address.sin_family = AF_INET;
                                    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
                                    server_address.sin_port = htons(80);
                                    
                                    if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
                                        perror("Failed to connect to target server");
                                        close(server_socket);
                                    } else {
                                        // Set the socket to non-blocking mode
                                        fcntl(server_socket, F_SETFL, O_NONBLOCK);
                                        
                                        // Add the new server socket to the list of monitored sockets
                                        clients[i].server_socket = server_socket;
                                        
                                        // Print a message to indicate that a new server connection has been established
                                        printf("Connected to server (socket %d)\n", server_socket);
                                    }
                                }
                            }
                        } else {
                            forward_data(clients[i].client_socket, clients[i].server_socket);
                        }
                        
                    }
                    
                    // If there is activity on the server socket, forward data from server to client
                    if (FD_ISSET(clients[i].server_socket, &readfds)) {
                        int result = forward_data(clients[i].server_socket, clients[i].client_socket);
                        
                        if (result < 0) {
                            // If there was an error or the server socket was closed, mark the connection as closed
                            clients[i].closed = true;
                            printf("Server connection closed (socket %d)\n", clients[i].server_socket);
                        }
                    }
                }
            }
        }
    }
}