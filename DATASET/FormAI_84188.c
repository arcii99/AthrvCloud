//FormAI DATASET v1.0 Category: Client Server Application ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

#define MY_PORT 12345
#define MAXLINE 1024

int main()
{
        struct sockaddr_in serv_addr;
        char sendline[MAXLINE], recvline[MAXLINE];
        int sockfd;

        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
                perror("socket failed");
                exit(1);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(MY_PORT);

        if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        {
                perror("inet_pton error");
                exit(1);
        }

        if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
                perror("connect failed");
                exit(1);
        }

        printf("Connection established!\n");
        printf("Type 'exit' to close the connection.\n");

        while(1)
        {
                printf("Enter the message: ");
                fgets(sendline,MAXLINE,stdin);

                if(send(sockfd,sendline,strlen(sendline),0) < 0)
                {
                        perror("send error");
                        exit(1);
                }

                if(strcmp(sendline, "exit\n") == 0)
                {
                        printf("Closing Connection.\n");
                        close(sockfd);
                        exit(0);
                }

                if(recv(sockfd,recvline,MAXLINE,0) < 0)
                {
                        perror("recv error");
                        exit(1);
                }

                printf("Server: %s",recvline);
                memset(&sendline, 0, sizeof(sendline));
                memset(&recvline, 0, sizeof(recvline));
        }

        return 0;
}