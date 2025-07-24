//FormAI DATASET v1.0 Category: Client Server Application ; Style: all-encompassing
/* 
 * This is a C Client Server Application that demonstrates sending messages 
 * from the client to the server and receiving the message from the server.
 * It uses TCP/IP socket communication between client and server. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080 // Port number for the server

int main(int argc, char const *argv[])
{
    int client_fd, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error: Failed to create socket\n");
        return -1;
    }

    // Set socket connection details for the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("Error: Invalid address\n");
        return -1;
    }

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error: Connection failed\n");
        return -1;
    }

    // Send message to the server
    printf("Enter message to send to server:\n");
    scanf("%[^\n]%*c", buffer);
    send(client_fd, buffer, strlen(buffer), 0);

    // Receive message from server
    valread = read(client_fd, buffer, 1024);
    printf("Server response: %s\n", buffer);
    return 0;
}