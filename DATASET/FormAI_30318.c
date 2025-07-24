//FormAI DATASET v1.0 Category: Chat server ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>

#define MAX_CLIENTS 30
#define BUFFER_SIZE 1024

int main(int argc,char *argv[])
{

    int server_socket,client_socket;
    struct sockaddr_in server_address,client_address;
    int address_length=sizeof(server_address);

    server_socket=socket(AF_INET,SOCK_STREAM,0);

    if(server_socket==-1){

        perror("Error in creating the socket");
        exit(EXIT_FAILURE);

}

    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_address.sin_port=htons(8080);

    int flag=1;
    int set_socket_option=setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR,&flag,sizeof(flag));

    if(set_socket_option==-1){

        perror("Error in setting the socket option");
        exit(EXIT_FAILURE);

}
    int bind_status=bind(server_socket,(struct sockaddr *)&server_address,sizeof(server_address));

    if(bind_status<0){

        perror("Error in binding the socket");
        exit(EXIT_FAILURE);

}

    printf("Server Running on Port : 8080\n");


    if(listen(server_socket,1)==-1){

        perror("Error in starting the listening mode");
        exit(EXIT_FAILURE);

}

    fd_set read_fds;
    fd_set master_fds;
    int client_list[MAX_CLIENTS]={0};
    int max_socket=server_socket;

    FD_ZERO(&master_fds);
    FD_SET(server_socket,&master_fds);

    while(1){

        read_fds=master_fds;
        if(select(max_socket+1,&read_fds,NULL,NULL,NULL)==-1){

            perror("Error in select");
            exit(EXIT_FAILURE);

        }

        for(int i=0;i<=max_socket;i++){

            if(FD_ISSET(i,&read_fds)){

                if(i==server_socket){

                    client_socket=accept(server_socket,(struct sockaddr *)&client_address,&address_length);

                    if(client_socket<0){

                        perror("Error in accepting the client connection");
                        exit(EXIT_FAILURE);

                    }

                    printf("New Client Connected From : %s , Port : %d\n",inet_ntoa(client_address.sin_addr),ntohs(client_address.sin_port));

                    for(int j=0;j<MAX_CLIENTS;j++){

                        if(client_list[j]==0){

                            client_list[j]=client_socket;
                            break;

                        }

                    }

                    FD_SET(client_socket,&master_fds);

                    if(client_socket>max_socket){

                        max_socket=client_socket;

                    }

                }
                else{

                    char buffer[BUFFER_SIZE]={0};
                    int read_value;
                    memset(buffer,0,sizeof(buffer));

                    read_value=read(i,buffer,sizeof(buffer));

                    if(read_value==0){

                        printf("Client Disconnected\n");

                        for(int j=0;j<MAX_CLIENTS;j++){

                            if(client_list[j]==i){

                                client_list[j]=0;
                                break;

                            }

                        }

                        FD_CLR(i,&master_fds);

                        close(i);

                    }
                    else{

                        printf("Message : %s",buffer);

                        for(int j=0;j<MAX_CLIENTS;j++){

                            if(client_list[j]!=0 && client_list[j]!=i){

                                write(client_list[j],buffer,strlen(buffer));

                            }

                        }

                    }

                }

            }

        }

    }

    return 0;

}