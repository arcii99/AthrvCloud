//FormAI DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 9000
#define MAX_BUFF_SIZE 1024

typedef struct {
    int fd;
    uint16_t port;
    char ip[16];
} client_t;

int create_server(const char* port){
    int serv_sock, yes=1;
    struct addrinfo hint,*servinfo,*p;
    memset(&hint,0,sizeof hint);
    hint.ai_family=AF_UNSPEC;
    hint.ai_socktype=SOCK_STREAM;
    hint.ai_flags=AI_PASSIVE;

    getaddrinfo(NULL,port,&hint,&servinfo);

    for(p=servinfo;p!=NULL;p=p->ai_next){
        serv_sock=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if(serv_sock==-1){
            perror("Socket Error");
            continue;
        }

        if(setsockopt(serv_sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof yes)==-1){
            perror("Setsockopt Error");
            exit(1);
        }

        if(bind(serv_sock,p->ai_addr,p->ai_addrlen)==-1){
            close(serv_sock);
            perror("Bind Error");
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo);

    if(p==NULL){
        fprintf(stderr,"Server: Failed to bind to any address\n");
        exit(2);
    }

    if(listen(serv_sock, 10) == -1){
        perror("Listen Error");
        exit(2);
    }

    return serv_sock;
}

client_t* create_client(const char* ip, const char* port){
    int client_sock, status;
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve server address and port
    if ((status = getaddrinfo(ip, port, &hints, &servinfo)) != 0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    // loop through all the results and create socket
    for (p = servinfo; p != NULL; p = p->ai_next){
        if ((client_sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1){
            perror("client: socket");
            continue;
        }

        if (connect(client_sock, p->ai_addr, p->ai_addrlen) == -1){
            close(client_sock);
            perror("client: connect");
            exit(1);
        }

        break;
    }

    // if p is NULL, means failed to connect
    if (p == NULL){
        fprintf(stderr, "client: failed to connect\n");
        exit(2);
    }

    client_t* client = (client_t*)malloc(sizeof(client_t));
    client->fd = client_sock;
    client->port = ntohs(((struct sockaddr_in *)p->ai_addr)->sin_port);
    inet_ntop(p->ai_family, &(((struct sockaddr_in *)p->ai_addr)->sin_addr), client->ip, sizeof client->ip);

    printf("Connected to %s:%d\n", client->ip, client->port);

    freeaddrinfo(servinfo);
    return client;
}

void handle_connection(int client_fd){
    int len, bytes_sent=0, bytes_received=0;
    char buff[MAX_BUFF_SIZE];
    memset(buff,0,sizeof buff);

    while(1){
        // Read data from client
        if((len = recv(client_fd, buff, sizeof buff, MSG_DONTWAIT)) == -1){
            if(errno == EWOULDBLOCK || errno == EAGAIN){
                usleep(10000);
                continue;
            }
            else{
                perror("Failed to receive data from client");
                break;
            }
        }

        if(len==0){
            printf("Client has disconnected: %s\n", strerror(errno));
            break;
        }

        bytes_received+=len;
        printf("Received from client: %s\n",buff);

        // Send data to client
        if((len = send(client_fd, buff, strlen(buff), MSG_DONTWAIT)) == -1){
            if(errno == EWOULDBLOCK || errno == EAGAIN){
                usleep(10000);
                continue;
            }
            else{
                perror("Failed to send data to client");
                break;
            }
        }

        bytes_sent+=len;
        printf("Sent to client: %s\n",buff);

        memset(buff,0,sizeof buff);
    }

    // Close connection
    close(client_fd);
    printf("Client connection closed\n");
}

int main(int argc, char **argv){
    int server_fd, client_fd, max_fd, i, num_clients=0, len, bytes_sent=0, bytes_received=0;
    char buff[MAX_BUFF_SIZE];
    memset(buff,0,sizeof buff);
    sprintf(buff,"Hello from server");

    fd_set master_fds, read_fds;
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    // Create server socket and add it to master fds
    server_fd = create_server("9000");
    FD_SET(server_fd, &master_fds);

    max_fd = server_fd;

    while(1){
        read_fds = master_fds;
        if(select(max_fd+1,&read_fds,NULL,NULL,NULL) == -1){
            perror("Select Error");
            exit(4);
        }

        for(i=0;i<=max_fd;i++){
            if(FD_ISSET(i,&read_fds)){
                if(i==server_fd){
                    // New connection, accept it and add it to master fds
                    num_clients++;
                    client_fd = accept(server_fd, NULL, NULL);
                    FD_SET(client_fd, &master_fds);
                    max_fd = (client_fd > max_fd) ? client_fd : max_fd;

                    // print the new connection information
                    printf("New connection: %d\n", client_fd);
                }
                else{
                    // Handle client request
                    handle_connection(i);
                    num_clients--;
                    FD_CLR(i, &master_fds);
                }
            }
        }
    }

    close(server_fd);
    return 0;
}