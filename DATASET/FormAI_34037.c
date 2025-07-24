//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#define SA struct sockaddr

void ftp(int sockfd, char buff[])
{
    char filename[50],ack[10],size[20];
    int n=-1;
    FILE *fp;
    recv(sockfd,filename,sizeof(filename),0);
    printf("\nFTP Request Received for file: %s\n",filename);
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("\n[ERROR] File not found!\n");
        send(sockfd,"File not found!",sizeof("File not found!"),0);
        return;
    }
    else
    {
        printf("\n[INFO] File opened successfully.\n");
        send(sockfd,"READY",sizeof("READY"),0);
        printf("\n[INFO] Begin file transfer.\n");
        fseek(fp,0,SEEK_SET);
        while(n!=0)
        {
            bzero(buff,sizeof(buff));
            n=fread(buff,1,sizeof(buff),fp);
            if(n<=0)
                break;
            send(sockfd,buff,n,0);
        }
        fclose(fp);
        printf("\n[INFO] File transfer completed successfully.\n");
    }
    return;
}

int main()
{
    int sockfd,connfd,len;
    struct sockaddr_in servaddr, client;
    char buff[1024];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("[ERROR] Socket creation failed!\n");
        exit(0);
    }
    else
        printf("[INFO] Socket created successfully!\n");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(21);

    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("[ERROR] Socket bind failed!\n");
        exit(0);
    }
    else
        printf("[INFO] Socket binded successfully!\n");

    if ((listen(sockfd, 5)) != 0)
    {
        printf("[ERROR] Listen failed!\n");
    }
    else
        printf("[INFO] Server listening!\n");

    len = sizeof(client);
    connfd = accept(sockfd, (SA*)&client, &len);
    if (connfd < 0)
    {
        printf("[ERROR] Server accept failed!\n");
        exit(0);
    }
    else
        printf("[INFO] Server accept the client!\n");

    while (1)
    {
        bzero(buff, sizeof(buff));
        recv(connfd, buff, sizeof(buff), 0);
        if (strncmp("GET", buff, 3) == 0)
        {
            ftp(connfd,buff);
        }
        else if (strncmp("QUIT", buff, 4) == 0)
        {
            printf("\n[INFO] FTP client exited.\n");
            break;
        }
        else
        {
            printf("\n[ERROR] Wrong input command\n");
        }
        bzero(buff, sizeof(buff));
    }

    close(sockfd);
    return 0;
}