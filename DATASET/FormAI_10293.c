//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define PORT 8080
#define MAXLINE 4096

int main(int argc, char** argv)
{
    // Declare variables
    int listen_fd, conn_fd, childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    char buffer[MAXLINE], web_address[MAXLINE], url[MAXLINE], method[MAXLINE], path[MAXLINE];
    struct hostent* host;
    FILE* fp;

    // Create a socket
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Couldn't create a socket");
        exit(1);
    }

    // Set the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(listen_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error: Couldn't bind the socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_fd, 10) < 0) {
        perror("Error: Couldn't listen for incoming connections");
        exit(1);
    }

    printf("Proxy server is running on port %d\n", PORT);

    // Wait for incoming connections
    while (1) {
        clilen = sizeof(cliaddr);
        conn_fd = accept(listen_fd, (struct sockaddr*)&cliaddr, &clilen);

        if (conn_fd < 0) {
            perror("Error: Couldn't accept the connection");
            exit(1);
        }

        // Fork a child process to handle the connection
        if ((childpid = fork()) < 0) {
            perror("Error: Couldn't create a child process");
            exit(1);
        } else if (childpid == 0) {
            // Handle the connection in the child process
            close(listen_fd);

            // Read the request from the client and parse it
            bzero(buffer, MAXLINE);
            read(conn_fd, buffer, MAXLINE);
            sscanf(buffer, "%s %s %s", method, url, path);

            // Parse the web address from the URL
            sscanf(url, "http://%s", web_address);

            // Get the IP address of the web address
            host = gethostbyname(web_address);

            if (host == NULL) {
                perror("Error: Couldn't get the IP address of the web address");
                exit(1);
            }

            // Create a socket to connect to the web server
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in webaddr;
            memset((char*)&webaddr, 0, sizeof(webaddr));
            webaddr.sin_family = AF_INET;
            webaddr.sin_port = htons(80);
            memcpy(&(webaddr.sin_addr), host->h_addr_list[0], sizeof(in_addr_t));

            // Connect to the web server
            if (connect(sockfd, (struct sockaddr*)&webaddr, sizeof(webaddr)) < 0) {
                perror("Error: Couldn't connect to the web server");
                exit(1);
            }

            // Send the request to the web server
            write(sockfd, buffer, strlen(buffer));

            // Forward the response from the web server to the client
            bzero(buffer, MAXLINE);
            while (read(sockfd, buffer, MAXLINE) > 0) {
                write(conn_fd, buffer, strlen(buffer));
                bzero(buffer, MAXLINE);
            }

            // Close the connection to the web server
            close(sockfd);

            // Close the connection to the client
            close(conn_fd);

            // Exit the child process
            exit(0);
        }

        // Parent process closes the connection
        close(conn_fd);

        // Wait for any child processes to exit
        while (waitpid(-1, NULL, WNOHANG) > 0);
    }

    return 0;
}