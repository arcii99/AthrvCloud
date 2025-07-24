//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
//Function Prototypes
void scanport(char* host,int port);
int main(int argc, char* argv[]){
    if(argc!=3){
        printf("Usage: %s <ip address> <port range>\n",argv[0]);
        return 1;
    }
    char* ip=argv[1];
    int start_port=atoi(strtok(argv[2],"-"));
    int end_port=atoi(strtok(NULL,"-"));
    printf("Starting port scanner on host %s from port %d to %d\n",ip,start_port,end_port);
    for(int port=start_port;port<=end_port;port++){
        scanport(ip,port);
        usleep(1000);
    }
    return 0;
}
void scanport(char* host,int port){
    struct sockaddr_in target;
    int sock=socket(AF_INET,SOCK_STREAM,0);
    target.sin_family=AF_INET;
    target.sin_port=htons(port);
    target.sin_addr.s_addr=inet_addr(host);
    if(connect(sock,(struct sockaddr*)&target,sizeof(target))==0){
        printf("Port %d - Open\n",port);
    }
    close(sock);
}