//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void url_parser(char url[],char server_ip[], int *port, char url_path[]){
    //parse url to extract the server ip, port number(if any) and the url path 
    char *ptr;
    char temp_url[strlen(url)];
    strcpy(temp_url, url);
    ptr = strtok(temp_url, "/"); //extract server address and port number
    strcpy(server_ip, ptr);

    ptr = strtok(NULL, "/"); //extract the first section after the "/". if it's a port number, extract it
    if(ptr != NULL && atoi(ptr) != 0){
        *port = atoi(ptr);
        ptr = strtok(NULL, ""); //extract the remaining url path after the port number
      }else{
         strcpy(url_path,"/");
      }
    if(ptr != NULL){
        strcat(url_path, ptr);
      }
}

int main(int argc, char *argv[]){

    int local_socket_fd, remote_socket_fd, client_fd;
    int port_number, client_addr_len, remote_addr_len;
    struct sockaddr_in server_addr, client_addr, remote_addr;
    char buffer[4096], server_ip[100], url[4096], url_path[4096], request[8192];
    int bytes, i;
    int enable = 1;

    //initialize the server address and port number
    bzero(&server_addr, sizeof(server_addr));
    port_number = 8080; //default proxy port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port_number);

    //create local socket and set socket options
    local_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(local_socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    bind(local_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(local_socket_fd, 10);

    //main loop for accepting client connections and proxying
    while(1){
        //accept connection from client
        client_addr_len = sizeof(client_addr);
        client_fd = accept(local_socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        bzero(buffer, sizeof(buffer));
        bzero(url,sizeof(url));
        bzero(url_path, sizeof(url_path));
        bzero(request, sizeof(request));

        //receive request from client
        bytes = read(client_fd, buffer, sizeof(buffer)-1);     
        sscanf(buffer, " %*[A-Z] %s ",url); //fetch the url from the request
        url_parser(url, server_ip, &port_number, url_path);
        printf("Server IP: %s\nPort Number: %d\nURL Path: %s\n",server_ip,port_number,url_path);

        //create remote socket and connect to the server
        remote_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(port_number);

        if(inet_pton(AF_INET,server_ip,&remote_addr.sin_addr)<=0){
            printf("Invalid Remote Address\n");
            continue;
        }

        if(connect(remote_socket_fd, (struct sockaddr *)&remote_addr,sizeof(remote_addr))<0){
            printf("Connection Failed\n");
            continue;
        }

        //create request to be sent to the server
        if(strlen(url_path)>0){
            sprintf(request, "GET %s HTTP/1.0\nHost: %s:%d\n\n",url_path, server_ip, port_number);
        }else{
            sprintf(request, "GET / HTTP/1.0\nHost: %s:%d\n\n", server_ip, port_number);
        }
        printf("%s\n",request);

        //forward request to the server and receive response
        write(remote_socket_fd,request,sizeof(request));
        bytes=0;
        while(bytes=read(remote_socket_fd,buffer,sizeof(buffer))){
            if(bytes<0){
                printf("Request Failed\n");
                break;
            }
            write(client_fd,buffer,bytes);
            bzero(buffer,sizeof(buffer));
        }

        close(remote_socket_fd);
        close(client_fd);
    }
    return 0;
}