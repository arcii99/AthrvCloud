//FormAI DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
/* The Case of the Missing Chat Server */

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

//Client Structure
typedef struct client{
    int sock_id;
    struct sockaddr_in client_address;
}Client;

//Detective Clause
#define CLIENT_LIMIT 10

//Client List
Client clients[CLIENT_LIMIT];
int client_count = 0;

//Connection Function
void create_server(){

    //Create socket
    int sock_id = socket(AF_INET,SOCK_STREAM,0);
    if(sock_id == -1){
        puts("The game's afoot! Could not create a socket!!");
        return;
    }

    //Set server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( 8877 ); //Sherlock's favorite number

    //Bind the socket to the address and port
    if(bind(sock_id,(struct sockaddr *)&server_address,sizeof(server_address)) < 0){
        puts("The game's afoot! Could not bind the socket to the address!!");
        return;
    }

    //Listen for incoming connections
    listen(sock_id,3);

    //Sherlock Holmes waits for a client
    puts("The game's afoot! The server is listening for incoming connections..");

    //Accept incoming connections
    struct sockaddr_in client;
    int client_length = sizeof(struct sockaddr_in);
    int client_sock;

    while( (client_sock = accept(sock_id,(struct sockaddr *)&client,(socklen_t*)&client_length)) ){

        //Check if client limit is reached
        if(client_count == CLIENT_LIMIT){
            puts("The game's afoot! Client limit reached..Please try again later.");
            continue;
        }

        //Add new client to client list
        clients[client_count].sock_id = client_sock;
        clients[client_count].client_address = client;

        puts("The game's afoot! New client connected..");

        client_count++;
    }
}

//Where it all starts
int main(int argc , char *argv[]){
    create_server();
    return 0;
}