//FormAI DATASET v1.0 Category: Database simulation ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>

#define MAX_CLIENTS 100

int client_socket[MAX_CLIENTS];
int client_count = 0;

void add_client(int socket){
    if(client_count == MAX_CLIENTS){
        printf("Chatroom full. no space for anymore clients\n");
        return;
    }
    client_socket[client_count++] = socket;
}

void remove_client(int index){
    close(client_socket[index]);
    while(index < client_count - 1){
        client_socket[index] = client_socket[index + 1];
        index++;
    }
    client_count--;
}

int main(){
    int server_socket, new_socket, max_sd, sd, activity, val_read, bytes_sent;
    struct sockaddr_in server_address, client_address;

    char message[1024];
    char response[1024];
    char client_name[1024];
    
    memset(message, 0, sizeof(message));
    memset(client_name, 0, sizeof(client_name));

    //create server socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Socket creation error\n");
        return -1;
    }

    //set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8765);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind server socket to address
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        printf("Binding error\n");
        return -1;
    }

    //listen for incoming connections
    if(listen(server_socket, 10) < 0){
        printf("Listening error\n");
        return -1;
    }

    //set maximum file descriptor value
    max_sd = server_socket;

    fd_set read_fds;

    while(1){
        //clear file descriptor set
        FD_ZERO(&read_fds);

        //add server socket to set
        FD_SET(server_socket, &read_fds);

        //add client sockets to set
        for(int i=0; i<client_count; i++){
            FD_SET(client_socket[i], &read_fds);
        }

        //wait for clients to become active
        activity = select(max_sd + 1, &read_fds, NULL, NULL, NULL);

        if((activity < 0) && (errno != EINTR)){
            printf("Select error\n");
        }

        //if server socket is active, accept new connection
        if(FD_ISSET(server_socket, &read_fds)){
            if((new_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&client_address)) < 0){
                printf("Accept error\n");
                return -1;
            }

            //add new client to client list
            add_client(new_socket);

            //send welcome message to new client
            strcpy(message, "Welcome to the chatroom!\n");
            bytes_sent = send(new_socket, message, strlen(message), 0);

            //broadcast to all clients that new client has joined
            strcpy(message, "A new client has joined the chatroom!\n");
            for(int i=0; i<client_count; i++){
                bytes_sent = send(client_socket[i], message, strlen(message), 0);
            }

            //update the maximum file descriptor value
            if(new_socket > max_sd){
                max_sd = new_socket;
            }
        }

        //check for client activity
        for(int i=0; i<client_count; i++){
            sd = client_socket[i];

            if(FD_ISSET(sd, &read_fds)){
                //check if client has disconnected
                if((val_read = read(sd, client_name, 1024)) == 0){
                    //broadcast to all clients that this client has disconnected
                    strcpy(message, "Client ");
                    strcat(message, client_name);
                    strcat(message, " has disconnected.\n");
                    for(int j=0; j<client_count; j++){
                        bytes_sent = send(client_socket[j], message, strlen(message), 0);
                    }
                    //remove client from list
                    remove_client(i);
                }
                else{
                    //check if client sends message
                    memset(message, 0, sizeof(message));
                    fgets(response, 1024, stdin);
                    response[strcspn(response, "\n")] = '\0';
                    strcpy(message, client_name);
                    strcat(message, ": ");
                    strcat(message, response);
                    strcat(message, "\n");

                    //broadcast message to all clients
                    for(int j=0; j<client_count; j++){
                        if(client_socket[j] != sd){
                            bytes_sent = send(client_socket[j], message, strlen(message), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}