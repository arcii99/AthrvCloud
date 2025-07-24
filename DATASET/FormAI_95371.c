//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to check error and exit program
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    // Variables to store connection details
    char host[100];
    char user[100];
    char pass[100];
    char file[100];
    int port;

    // Getting connection details from user
    printf("Enter FTP server address: ");
    scanf("%s", host);
    printf("Enter FTP server port: ");
    scanf("%d", &port);
    printf("Enter FTP username: ");
    scanf("%s", user);
    printf("Enter FTP password: ");
    scanf("%s", pass);
    printf("Enter file name to upload: ");
    scanf("%s", file);

    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Error opening socket");
    }

    // Getting host details
    struct hostent *server = gethostbyname(host);
    if (server == NULL)
    {
        error("Error, no such host exists");
    }

    // Creating server details
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, 
         server->h_length);
    serv_addr.sin_port = htons(port);

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, 
                sizeof(serv_addr)) < 0)
    {
        error("Error connecting to server");
    }

    // Logging into server
    char buffer[256];
    bzero(buffer, 256);
    sprintf(buffer, "%s\r\n", user);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        error("Error writing to socket");
    }
    bzero(buffer, 256);
    if (read(sockfd, buffer, 255) < 0)
    {
        error("Error reading from socket");
    }
    sprintf(buffer, "%s\r\n", pass);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        error("Error writing to socket");
    }
    bzero(buffer,256);
    if (read(sockfd, buffer, 255) < 0)
    {
        error("Error reading from socket");
    }

    // Opening file to upload
    FILE *fp = fopen(file, "rb");
    if (fp == NULL)
    {
        error("Error opening file");
    }

    // Uploading file to server
    bzero(buffer, 256);
    sprintf(buffer, "STOR %s\r\n", file);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        error("Error writing to socket");
    }
    bzero(buffer, 256);
    if (read(sockfd, buffer, 255) < 0)
    {
        error("Error reading from socket");
    }
    char file_buffer[256];
    bzero(file_buffer, 256);
    int n;
    while ((n = fread(file_buffer, 1, 256, fp)) > 0)
    {
        if (write(sockfd, file_buffer, n) < 0)
        {
            error("Error writing to socket");
        }
        bzero(file_buffer, 256);
    }
    fclose(fp);

    // Closing connection with server
    close(sockfd);
    return 0;
}