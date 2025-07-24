//FormAI DATASET v1.0 Category: Socket programming ; Style: Donald Knuth
// Sample C Socket Program for client-server communication

#include <stdio.h>              // for standard input/output operations
#include <stdlib.h>             // for system exit function
#include <sys/socket.h>         // for socket(), bind(), and connect() functions
#include <sys/types.h>          // for data types used in system calls
#include <netinet/in.h>         // for internet domain address structures
#include <string.h>             // for memset() function

#define BUFFER_SIZE 256         // constant for buffer size
#define PORT 8080               // constant for port number

int main()
{
    int sockfd;                 // file descriptor for socket
    struct sockaddr_in server_addr;     // server address structure
    
    // creating a socket with AF_INET (IPv4) domain and SOCK_STREAM (TCP) type
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // initializing server address structure with 0s
    memset(&server_addr, 0, sizeof(server_addr));
    
    // settings for server address structure
    server_addr.sin_family = AF_INET;        // IP version 4
    server_addr.sin_port = htons(PORT);      // port number, converted to network byte order
    server_addr.sin_addr.s_addr = INADDR_ANY;    // IP address

    // connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }
    
    // send data to server
    char buffer[BUFFER_SIZE] = "Hello from client!";
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    
    // receive data from server
    memset(buffer, 0, sizeof(buffer));      // clear buffer
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    
    // print server response
    printf("Server says: %s\n", buffer);
    
    // close the socket
    close(sockfd);
    
    return 0;
}