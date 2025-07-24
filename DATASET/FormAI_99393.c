//FormAI DATASET v1.0 Category: Chat server ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;
    char server_message[2000];

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind failed");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");

        //Reply to the client
        strcpy(server_message , "Hello Client, I have received your connection.\n");
        send(client_sock , server_message , strlen(server_message) , 0);

        //Receive a message from client
        char client_message[2000];
        while( recv(client_sock , client_message , 2000 , 0) > 0 )
        {
            //Reply to the client
            printf("Client: %s", client_message);
            printf("Server: ");
            fgets(server_message, 2000, stdin);
            send(client_sock , server_message , strlen(server_message) , 0);
            memset(client_message, 0, 2000);
            memset(server_message, 0, 2000);
        }

        if(recv < 0)
        {
            puts("recv failed");
            break;
        }
    }

    return 0;
}