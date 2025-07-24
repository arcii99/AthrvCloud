//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>

#define MAX 65535
#define PROXY_PORT 8888

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc,char **argv){
    int sockfd,newsockfd,n=0,flag=0,opt=1;
    char buffer[MAX],t[MAX],url[MAX],ip[MAX],req[MAX];
    struct sockaddr_in serv_addr,client_addr;
    socklen_t client_len;
    memset(buffer,0,MAX);
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0) error("Error Socket Failed");
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) error("setsockopt");
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr= htonl(INADDR_ANY);
    serv_addr.sin_port=htons(PROXY_PORT);
    if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0) error("Binding Error");
    if(listen(sockfd,10)<0) error("Listen Error");
    printf("Starting HTTP Proxy...\n");
    while(1){
        client_len=sizeof(client_addr);
        if((newsockfd=accept(sockfd,(struct sockaddr*)&client_addr,&client_len))<0) error("Accept Error");
        memset(buffer,0,MAX);
        n=read(newsockfd,buffer,MAX);
        if(n<0) error("Read Error");
        else{
            sscanf(buffer,"%s %s %s",t,url,&req);
            if(strcmp(t,"GET")!=0) printf("Invalid Method : %s\n",t);
            else{
                printf("Request URL : %s\n",url);
                char *hostname=strchr(url,'/'); //find the first occurrence of / 
                hostname++; //incremented to skip /
                // find end of the hostname
                char *endpoint = strchr(hostname, '/');
                if(endpoint==NULL){
                    endpoint=hostname+strlen(hostname);
                }
                //get hostname and endpoint
                memcpy(url,hostname,endpoint-hostname);
                url[endpoint-hostname]='\0';
                sprintf(ip,"%s",inet_ntoa((struct in_addr) *((struct in_addr*)gethostbyname(url)->h_addr_list[0])));
                sprintf(buffer,"%s /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n",t,endpoint,req,url);
                printf("Forwarding Request to %s\n",ip);
            }
            struct sockaddr_in server_addr;
            int sockfd1=socket(AF_INET, SOCK_STREAM, 0);
            bzero((char*)&server_addr,sizeof(server_addr));
            server_addr.sin_family=AF_INET;
            server_addr.sin_port=htons(80);
            if(inet_aton(ip,&server_addr.sin_addr)==0){
                error("Error Converting hostname");
            }
            if(connect(sockfd1,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
                error("Error Connecting to Remote Server");
            }
            if(write(sockfd1,buffer,strlen(buffer))<0){
                error("Error Writing to Remote Server");
            }
            memset(buffer,0,MAX);
            while(read(sockfd1,buffer,MAX)>0){
                if(write(newsockfd,buffer,strlen(buffer))<0){
                    error("Error Writing Response to Client");
                }
                memset(buffer,0,MAX);
            }
            close(sockfd1);
            close(newsockfd);
        }
    }
return 0;
}