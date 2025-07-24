//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define DEFAULT_PORT "21" // FTP default port
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname = NULL;
    char *username = NULL;
    char *password = NULL;
    char *path = NULL;
    char *port = DEFAULT_PORT;

    // Parse arguments from command line
    int opt;
    while ((opt = getopt(argc, argv, "h:u:p:d:o:")) != -1) {
        switch (opt) {
            case 'h':
                hostname = optarg;
                break;
            case 'u':
                username = optarg;
                break;
            case 'p':
                password = optarg;
                break;
            case 'd':
                path = optarg;
                break;
            case 'o':
                port = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s -h hostname -u username -p password -d remote_path -o port\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Make sure all mandatory arguments are provided
    if (hostname == NULL || username == NULL || password == NULL || path == NULL) {
        fprintf(stderr, "Missing mandatory arguments!\nUsage: %s -h hostname -u username -p password -d remote_path -o port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname and connect to the FTP server
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(hostname, port, &hints, &res);
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol); // client's socket
    connect(sockfd, res->ai_addr, res->ai_addrlen);

    // Receive a welcome message from the FTP server
    char recv_buffer[BUFFER_SIZE];
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    // Send the login credentials
    char auth_buffer[BUFFER_SIZE];
    sprintf(auth_buffer, "USER %s\r\n", username);
    send(sockfd, auth_buffer, strlen(auth_buffer), 0);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);
    sprintf(auth_buffer, "PASS %s\r\n", password);
    send(sockfd, auth_buffer, strlen(auth_buffer), 0);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    // Send a request to enter passive mode
    send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    // Extract the port number from the passive mode response
    char *p1 = strrchr(recv_buffer, '(');
    char *p2 = strrchr(recv_buffer, ')');
    char *p3 = strstr(p1, ",");
    char *p4 = strstr(p3 + 1, ",");
    char *p5 = strstr(p4 + 1, ",");
    int port1 = atoi(p3 + 1);
    int port2 = atoi(p4 + 1);
    int data_port = port1 * 256 + port2;

    // Connect to the FTP server's data port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(data_port);
    servaddr.sin_addr = ((struct sockaddr_in *) res->ai_addr)->sin_addr;
    int datafd = socket(AF_INET, SOCK_STREAM, 0);
    connect(datafd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    // Send a request to list the remote directory
    char list_buffer[BUFFER_SIZE];
    sprintf(list_buffer, "LIST %s\r\n", path);
    send(sockfd, list_buffer, strlen(list_buffer), 0);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    // Print the listing
    while (recv(datafd, recv_buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", recv_buffer);
    }

    // Clean up and exit
    close(datafd);
    close(sockfd);
    freeaddrinfo(res);
    return EXIT_SUCCESS;
}