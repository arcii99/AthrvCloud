//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 512

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {

    if(argc < 4) {
        printf("Usage: %s FTP_SERVER_ADDRESS USERNAME PASSWORD\n", argv[0]);
        exit(1);
    }

    const char *server_address = argv[1];
    const char *user_name = argv[2];
    const char *password = argv[3];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("Error opening socket.");
    }

    // Connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(21);
    if(inet_pton(AF_INET, server_address, &server.sin_addr) < 0) {
        error("Error: Invalid address.");
    }

    if(connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        error("Error: Connection failed.");
    }

    // Read response from server
    char server_response[BUFFER_SIZE];
    if(read(sockfd, server_response, sizeof(server_response)) < 0) {
        error("Error: Failed to read response from server.");
    }
    printf("Server response: %s\n", server_response); 

    // Send username
    char user[BUFFER_SIZE];
    sprintf(user, "USER %s\r\n", user_name);
    if(send(sockfd, user, strlen(user), 0) < 0) {
        error("Error: Failed to send username.");
    }

    // Read response from server
    if(read(sockfd, server_response, sizeof(server_response)) < 0) {
        error("Error: Failed to read response from server.");
    }
    printf("Server response: %s\n", server_response); 

    // Send password
    char pass[BUFFER_SIZE];
    sprintf(pass, "PASS %s\r\n", password);
    if(send(sockfd, pass, strlen(pass), 0) < 0) {
        error("Error: Failed to send password.");
    }

    // Read response from server
    if(read(sockfd, server_response, sizeof(server_response)) < 0) {
        error("Error: Failed to read response from server.");
    }
    printf("Server response: %s\n", server_response); 

    // Enter passive mode
    if(send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0) < 0) {
        error("Error: Failed to enter passive mode.");
    }

    // Read response from server
    if(read(sockfd, server_response, sizeof(server_response)) < 0) {
        error("Error: Failed to read response from server.");
    }
    printf("Server response: %s\n", server_response); 

    // Get IP address and port number for data transfer
    char *ip_address, *tok;
    int port_number;
    strtok_r(server_response, "(", &tok);
    ip_address = strtok_r(NULL, ")", &tok);
    strtok_r(NULL, "(", &tok);
    strtok_r(NULL, ",", &tok);
    strtok_r(NULL, ",", &tok);
    strtok_r(NULL, ",", &tok);
    port_number = atoi(strtok_r(NULL, ",", &tok)) * 256;
    port_number += atoi(strtok_r(NULL, ",", &tok));
    printf("IP address: %s\n", ip_address);
    printf("Port number: %d\n", port_number);

    // Create data socket
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(data_sockfd < 0) {
        error("Error opening data socket.");
    }

    // Connect to data socket
    struct sockaddr_in data_server;
    data_server.sin_family = AF_INET;
    data_server.sin_port = htons(port_number);
    if(inet_pton(AF_INET, ip_address, &data_server.sin_addr) < 0) {
        error("Error: Invalid address.");
    }

    if(connect(data_sockfd, (struct sockaddr *) &data_server, sizeof(data_server)) < 0) {
        error("Error: Connection failed.");
    }

    // Retrieve file list
    if(send(sockfd, "NLST\r\n", strlen("NLST\r\n"), 0) < 0) {
        error("Error: Failed to retrieve file list.");
    }

    // Read file list from server
    char file_list[BUFFER_SIZE];
    memset(file_list, 0, sizeof(file_list));
    if(read(data_sockfd, file_list, sizeof(file_list)) < 0) {
        error("Error: Failed to read file list from server.");
    }
    printf("File list:\n%s", file_list);

    // Close data socket
    close(data_sockfd);

    // Quit connection
    if(send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        error("Error: Failed to quit connection.");
    }

    // Read response from server
    if(read(sockfd, server_response, sizeof(server_response)) < 0) {
        error("Error: Failed to read response from server.");
    }
    printf("Server response: %s\n", server_response); 

    // Close socket
    close(sockfd);

    return 0;
}