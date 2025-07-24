//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXSIZE 1024

// Function to create a new socket
int createSocket()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    return sockfd;
}

// Function to connect to FTP server
void connectToServer(int sockfd, char* hostname, int port)
{
    struct sockaddr_in serverAddr;
    memset(&serverAddr, '\0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serverAddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }
}

// Function to receive message from FTP server
void receiveMessage(int sockfd, char* buffer)
{
    memset(buffer, '\0', MAXSIZE);

    if (recv(sockfd, buffer, MAXSIZE, 0) == -1)
    {
        perror("Error receiving message");
        exit(1);
    }
}

// Function to send message to FTP server
void sendMessage(int sockfd, char* message)
{
    if (send(sockfd, message, strlen(message), 0) == -1)
    {
        perror("Error sending message");
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    // Check if all required arguments are provided
    if (argc != 4)
    {
        printf("Usage: ./ftpclient <server-ip> <username> <password>\n");
        exit(1);
    }

    // Parse command line arguments
    char* hostname = argv[1];
    int port = 21;
    char* username = argv[2];
    char* password = argv[3];

    // Create socket and connect to FTP server
    int sockfd = createSocket();
    connectToServer(sockfd, hostname, port);

    char buffer[MAXSIZE] = "";

    // Receive welcome message from FTP server
    receiveMessage(sockfd, buffer);
    printf("%s\n", buffer);

    // Send username
    char* message = malloc(MAXSIZE);
    sprintf(message, "USER %s\r\n", username);
    sendMessage(sockfd, message);
    receiveMessage(sockfd, buffer);
    printf("%s\n", buffer);

    // Send password
    sprintf(message, "PASS %s\r\n", password);
    sendMessage(sockfd, message);
    receiveMessage(sockfd, buffer);
    printf("%s\n", buffer);

    // Send PASV command to enter passive mode
    sendMessage(sockfd, "PASV\r\n");
    receiveMessage(sockfd, buffer);

    // Parse IP address and port from server's response to PASV command
    char ipAddress[16] = "";
    int p1, p2;

    if (sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &p1, &p2, &p2, &p2, &p2, &p2) == 6)
    {
        sprintf(ipAddress, "%d.%d.%d.%d", p1, p2, p2, p2);
    }

    int dataPort = p2*256 + p2;

    // Create data socket and connect to FTP server in passive mode
    int dataSocket = createSocket();
    connectToServer(dataSocket, ipAddress, dataPort);

    // Send LIST command to list files on server
    sendMessage(sockfd, "LIST\r\n");
    receiveMessage(sockfd, buffer);

    // Print list of files received from server
    printf("%s\n", buffer);

    // Close data socket and main socket
    close(dataSocket);
    close(sockfd);

    return 0;
}