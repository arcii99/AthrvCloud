//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
// Romeo and Juliet: A Simple HTTP Proxy

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#define BUFFER_SIZE 80960
#define REQUEST_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, client_len, port;
    struct sockaddr_in proxy_addr, client_addr;
    char req_buffer[REQUEST_SIZE], res_buffer[BUFFER_SIZE];
    char mal_site[] = "http://www.poisonous.com";
    char good_site[] = "http://www.veggies.com";
    
    // Check for correct number of arguments.
    if(argc != 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        return -1;
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error creating socket.\n");
        return -1;
    }

    // Setup the proxy server address structure
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    port = atoi(argv[1]);
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(port);
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the specified address and port
    if(bind(sockfd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        printf("Error binding socket to address.\n");
        close(sockfd);
        return -1;
    }

    // Start listening for incoming connections
    listen(sockfd, 5);
    memset(&client_addr, 0, sizeof(client_addr));
    printf("Waiting for connections on port %d ...\n", port);

    while(1) {
        // Accept a new connection
        client_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
        if(new_sockfd < 0) {
            printf("Error accepting new connection.\n");
        } else {
            printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }

        // Receive the HTTP request from the browser/client
        memset(req_buffer, 0, sizeof(req_buffer));
        if(recv(new_sockfd, req_buffer, REQUEST_SIZE, 0) < 0) {
            printf("Error receiving request from browser/client.\n");
            close(new_sockfd);
            continue;
        }

        // Check if the request is for a dangerous website and replace it with a safe website
        if(strstr(req_buffer, mal_site) != NULL) {
            char* pos = strstr(req_buffer, mal_site);
            strncpy(pos, good_site, strlen(good_site));
        }

        printf("Modified request buffer:\n%s\n", req_buffer);

        // Forward the modified request to the actual server
        int server_sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in remote_addr;
        memset(&remote_addr, 0, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(80);
        inet_pton(AF_INET, "127.0.0.1", &(remote_addr.sin_addr));
        connect(server_sock, (struct sockaddr*)&remote_addr, sizeof(remote_addr));
        if(send(server_sock, req_buffer, strlen(req_buffer), 0) < 0) {
            printf("Error sending request to server.\n");
            close(server_sock);
            continue;
        }

        // Receive the response from the actual server
        memset(res_buffer, 0, sizeof(res_buffer));
        if(recv(server_sock, res_buffer, BUFFER_SIZE, 0) < 0) {
            printf("Error receiving response from server.\n");
            close(server_sock);
            continue;
        }

        printf("Modified response buffer:\n%s\n", res_buffer);

        // Forward the response to the browser/client
        if(send(new_sockfd, res_buffer, strlen(res_buffer), 0) < 0) {
            printf("Error sending response to browser/client.\n");
            close(new_sockfd);
            continue;
        }

        // Close the socket connections
        close(server_sock);
        close(new_sockfd);
    }

    return 0;
}