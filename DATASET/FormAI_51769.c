//FormAI DATASET v1.0 Category: Chat server ; Style: mind-bending
//Welcome to the Matrix Chat Server!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
    int server_socket, opt=1, pid;
    struct sockaddr_in server_address, client_address;
    socklen_t slen=sizeof(client_address);
    char client_message[BUFFER_SIZE];
    int client_count=0, i, j, k;

    //create the socket
    server_socket=socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket<0){
        printf("\nSocket creation failed. Exiting from the Matrix...");
        exit(EXIT_FAILURE);
    }
    //set socket options
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(int));

    //configure the server address
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(8080);
    server_address.sin_addr.s_addr=INADDR_ANY;

    //bind the socket to the specified address and port number
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address))<0){
        printf("\nSocket binding failed. Exiting from the Matrix...");
        exit(EXIT_FAILURE);
    }

    //start listening for incoming connections
    if(listen(server_socket, MAX_CLIENTS)<0){
        printf("\nListening failed. Exiting from the Matrix...");
        exit(EXIT_FAILURE);
    }

    printf("\nWelcome to the Matrix Chat Server!\nWaiting for clients to connect...\n");

    while(1){
        //accept incoming connections
        int client_socket=accept(server_socket, (struct sockaddr *)&client_address, &slen);
        if(client_socket<0){
            printf("\nFailed to accept incoming connection. Exiting from the Matrix...");
            exit(EXIT_FAILURE);
        }

        //fork a new process to handle the client
        pid=fork();
        if(pid<0){
            printf("\nFailed to fork process. Exiting from the Matrix...");
            exit(EXIT_FAILURE);
        }
        else if(pid==0){//child process
            close(server_socket);
            printf("\nClient %d connected to the Matrix server...\n", client_count++);
            while(1){
                //read the client message
                memset(client_message, '\0', BUFFER_SIZE);
                int message_len=read(client_socket, client_message, BUFFER_SIZE);
                if(message_len<0){
                    printf("\nFailed to read message from client. Disconnecting...");
                    break;
                }
                else if(message_len==0){
                    printf("\nClient %d has disconnected from the Matrix server.\n", client_count-1);
                    break;
                }
                else{//broadcast the message to other clients
                    printf("\nClient %d sent: %s", client_count-1, client_message);
                    for(i=0; i<client_count; i++){
                        if(i==client_count-1)//skip broadcasting message to the sender
                            continue;
                        k=write(i, client_message, strlen(client_message));
                        if(k<0){
                            printf("\nFailed to send message to client %d. Disconnecting...", i);
                            break;
                        }
                    }
                    if(i<client_count)
                        break;
                }
            }
            close(client_socket);
            printf("\nChild process %d has disconnected from the Matrix...\n", getpid());
            exit(EXIT_SUCCESS);
        }
        else{//parent process
            close(client_socket);
        }
    }
    return 0;
}