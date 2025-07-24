//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <arpa/inet.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <unistd.h>  
#include <errno.h>  
  
#define PORT 8080  
#define MAXLINE 1024  
  
int main() {  
        int listenfd, connfd, nready;  
        struct sockaddr_in servaddr;  
        char buffer[MAXLINE];  
        fd_set readfds;  
          
        listenfd = socket(AF_INET, SOCK_STREAM, 0);  
        memset(&servaddr, 0, sizeof(servaddr));    
        servaddr.sin_family = AF_INET;  
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);      
        servaddr.sin_port = htons(PORT);    
        bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));  
        listen(listenfd, 5);    
  
        int maxfd = listenfd;  
        int maxi = -1;  
        int clientfd[FD_SETSIZE] = { 0, -1 };  
          
        for(int i = 0; i<FD_SETSIZE; i++) {  
            clientfd[i] = -1;  
        }  
  
        fd_set allset;  
        FD_ZERO(&allset);  
        FD_SET(listenfd, &allset);    
  
        while(1) {  
            readfds = allset;  
  
            nready = select(maxfd+1, &readfds, NULL, NULL, NULL);    
  
            if(FD_ISSET(listenfd, &readfds)) {    
                connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);  
                  
                int i;  
                for (i = 0; i < FD_SETSIZE; i++) {  
                    if (clientfd[i] < 0) {  
                        clientfd[i] = connfd;  
                        break;  
                    }  
                }  
  
                if (i == FD_SETSIZE) {  
                    fprintf(stderr,"too many clients");  
                    exit(1);  
                }  
  
                printf("New connection from %s:%d, clientfd: %d\n", inet_ntoa(servaddr.sin_addr), ntohs(clientfd[i]), clientfd[i]);    
                FD_SET(connfd, &allset);  
  
                if (connfd > maxfd)   
                    maxfd = connfd;              
                if (i > maxi)  
                    maxi = i;                          
                if (--nready <= 0)  
                    continue;  
            }  
              
            for (int i = 0; i <= maxi; i++) { // check all clients for data    
                bzero(buffer, MAXLINE);    
                if ( (connfd = clientfd[i]) < 0)  
                        continue;    
                if (FD_ISSET(connfd, &readfds)) {    
                    int nread = read(connfd, buffer, sizeof(buffer));    
                    if (nread == 0) {  
                        printf("close connection from client%d\n", connfd);  
                        close(connfd);  
                        clientfd[i] = -1;  
                        FD_CLR(connfd, &allset);  
                    }  
                    else {  
                        printf("receive message from client%d: %s\n", connfd, buffer);    
                        write(connfd, buffer, strlen(buffer));  
                    }  
  
                    if (--nready <= 0)  
                        break;  
                }  
            }  
        }  
  
        return 0;  
}