//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 65536 // Maximum buffer size for incoming requests and responses

// Struct to store the client socket and requested server information
struct client_request {
    int client_sock;
    char* server_name;
    int server_port;
};

// Function to handle client requests and proxy them to the requested server
void* handle_client_request(void* arg) {
    // Get the client socket and requested server information from the input argument
    struct client_request* request = (struct client_request*)arg;
    int client_sock = request->client_sock;
    char* server_name = request->server_name;
    int server_port = request->server_port;

    // Connect to the requested server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    struct hostent* server = gethostbyname(server_name);
    if(server == NULL) {
        perror("Error looking up server address");
        close(client_sock);
        free(request);
        return NULL;
    }
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0) {
        perror("Error creating server socket");
        close(client_sock);
        free(request);
        return NULL;
    }
    if(connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(server_sock);
        close(client_sock);
        free(request);
        return NULL;
    }

    // Proxy the client request to the server
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    int bytes_read = recv(client_sock, buffer, MAX_BUFFER_SIZE - 1, 0);
    if(bytes_read < 0) {
        perror("Error reading client request");
        close(server_sock);
        close(client_sock);
        free(request);
        return NULL;
    }
    buffer[bytes_read] = '\0';
    if(send(server_sock, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending client request to server");
        close(server_sock);
        close(client_sock);
        free(request);
        return NULL;
    }

    // Receive the server response and proxy it back to the client
    memset(buffer, 0, MAX_BUFFER_SIZE);
    bytes_read = recv(server_sock, buffer, MAX_BUFFER_SIZE - 1, 0);
    if(bytes_read < 0) {
        perror("Error reading server response");
        close(server_sock);
        close(client_sock);
        free(request);
        return NULL;
    }
    buffer[bytes_read] = '\0';
    if(send(client_sock, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending server response to client");
        close(server_sock);
        close(client_sock);
        free(request);
        return NULL;
    }

    // Close the sockets and free the memory allocated for the request information
    close(server_sock);
    close(client_sock);
    free(request);

    return NULL;
}

int main(int argc, char** argv) {
    // Parse the command-line arguments to get the proxy server port number
    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[1]);

    // Create a socket for the proxy server to listen on
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0) {
        perror("Error creating server socket");
        return 1;
    }

    // Set the socket options to allow immediate reuse of the socket address
    int reuse_addr = 1;
    if(setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) < 0) {
        perror("Error setting socket options");
        close(server_sock);
        return 1;
    }

    // Bind the socket to the local address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if(bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        close(server_sock);
        return 1;
    }

    // Listen for incoming client connections
    if(listen(server_sock, SOMAXCONN) < 0) {
        perror("Error listening for incoming connections");
        close(server_sock);
        return 1;
    }

    // Loop to accept and handle incoming client requests
    while(1) {
        // Accept the incoming client connection and create a new thread to handle the request
        int client_sock = accept(server_sock, NULL, NULL);
        if(client_sock < 0) {
            perror("Error accepting incoming connection");
            continue;
        }
        struct client_request* request = (struct client_request*)malloc(sizeof(struct client_request));
        char buffer[MAX_BUFFER_SIZE];
        memset(buffer, 0, MAX_BUFFER_SIZE);
        int bytes_read = recv(client_sock, buffer, MAX_BUFFER_SIZE - 1, 0);
        if(bytes_read <= 0) {
            printf("Error reading client request");
            continue;
        }
        // Parse the client HTTP request to extract the server hostname and port number
        char* host_start = strstr(buffer, "Host: ") + strlen("Host: ");
        char* host_end = strstr(host_start, "\r\n");
        char* hostname = strndup(host_start, host_end - host_start);
        char* port_start = strstr(hostname, ":");
        if(port_start != NULL) {
            *port_start = '\0';
            ++port_start;
            request->server_port = atoi(port_start);
        } else {
            request->server_port = 80;
        }
        request->server_name = hostname;
        request->client_sock = client_sock;
        pthread_t request_thread;
        if(pthread_create(&request_thread, NULL, handle_client_request, (void*)request) != 0) {
            perror("Error creating request thread");
            close(client_sock);
            free(request);
            continue;
        }
    }

    // Close the server socket
    close(server_sock);

    return 0;
}