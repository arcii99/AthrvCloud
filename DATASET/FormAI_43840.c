//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAXLINE 1024

int main()
{
    int sockfd;
    char buffer[MAXLINE], filename[MAXLINE];
    struct sockaddr_in servaddr;
    struct hostent *host;
    int port;

    printf("Enter server address: ");
    fgets(buffer, MAXLINE, stdin);
    host = gethostbyname(buffer);
    if (!host)
    {
        printf("Error: Unable to resolve host\n");
        exit(0);
    }
    printf("Enter server port number: ");
    scanf("%d", &port);
    getchar(); //remove newline character from stdin

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error: Unable to create socket\n");
        exit(0);
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy((void *)&servaddr.sin_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Error: Unable to connect to server\n");
        exit(0);
    }

    printf("Connected to server successfully.\n");
    printf("Enter filename: ");
    fgets(filename, MAXLINE, stdin);
    filename[strlen(filename) - 1] = 0; //remove newline character

    char get_cmd[MAXLINE];
    sprintf(get_cmd, "GET %s\n", filename);
    send(sockfd, get_cmd, strlen(get_cmd), 0); //send GET command to server

    char response[MAXLINE];
    recv(sockfd, response, MAXLINE, 0); //receive response from server
    if (strncmp(response, "ERROR", 5) == 0)
    {
        printf("Error: File not found\n");
        exit(0);
    }

    FILE *fp;
    fp = fopen(filename, "wb"); //open file to write
    int bytes_read = 0;
    int total_bytes_read = 0;

    while (1)
    {
        bytes_read = recv(sockfd, buffer, sizeof(buffer), 0); //read data from socket
        if (bytes_read == 0) //no more data to read
        {
            printf("File received successfully.\n");
            break;
        }
        fwrite(buffer, 1, bytes_read, fp); //write data to file
        total_bytes_read += bytes_read;
    }
    printf("Total bytes received: %d\n", total_bytes_read);
    fclose(fp); //close file
    close(sockfd); //close socket
    return 0;
}