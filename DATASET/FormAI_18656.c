//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
// C program for building an FTP client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXLINE 1024

void ftp_client(int sockfd)
{
    char sendline[MAXLINE], recvline[MAXLINE];

    // Send the username to the FTP server
    sprintf(sendline, "USER anonymous\r\n"); 
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    // Send the password to the FTP server
    sprintf(sendline, "PASS password\r\n"); 
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    // Change the FTP directory to the specified path
    sprintf(sendline, "CWD /Users/dev/null\r\n"); 
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    // Send the command to fetch the file
    sprintf(sendline, "RETR file.txt\r\n");
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    // Open the file to write the contents to
    FILE *fp;
    fp = fopen("file.txt", "w");

    // Read the file from the server and write its contents to the local file
    while(read(sockfd, recvline, MAXLINE) > 0)
    {
        fputs(recvline, fp);

        // End loop if the file transfer is complete
        if(strstr(recvline, "226 Transfer complete") != NULL)
            break;
    }

    // Close the file and the socket
    fclose(fp);
    close(sockfd);
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(21);

    // Connect to the server
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Call the FTP client function
    ftp_client(sockfd);

    return 0;
}