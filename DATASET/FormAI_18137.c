//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define BUFFERSIZE 1024

int main()
{
    int sockfd = 0;
    char buffer[BUFFERSIZE];
    struct sockaddr_in serv_addr;
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }
    
    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        return 1;
    }
    
    char *username = "USERNAME";
    char *password = "PASSWORD";
    
    // Send Username
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFERSIZE, 0);
    printf("%s", buffer);
    
    // Send Password
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFERSIZE, 0);
    printf("%s", buffer);

    // Send PASV command
    sprintf(buffer, "PASV\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFERSIZE, 0);
    printf("%s", buffer);
    
    // Send RETR command 
    sprintf(buffer, "RETR %s\r\n", "FILE_NAME");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFERSIZE, 0);
    printf("%s", buffer);
    
    // Receive file contents
    FILE *fp = fopen("FILE_NAME", "w");
    while(1) {
        int recv_len = recv(sockfd, buffer, BUFFERSIZE, 0);
        if(recv_len<=0) break;
        fwrite(buffer, 1, recv_len, fp);
    }
    fclose(fp);

    close(sockfd);
    return 0;
}