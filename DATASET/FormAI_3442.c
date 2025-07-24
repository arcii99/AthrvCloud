//FormAI DATASET v1.0 Category: Networking ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000

int main(int argc , char *argv[])
{
    int sock, new_sock, read_size;
    struct sockaddr_in server, client;
    char message[1000], client_message[2000];

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
        return 1;
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    //Bind the socket to localhost and port 9000
    if( bind(sock,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Bind failed. Error");
        return 1;
    }
    puts("Bind done");

    //Listen for incoming connections
    listen(sock , 3);

    //Accept incoming connection
    puts("Waiting for incoming connections...");
    int c = sizeof(struct sockaddr_in);

    while((new_sock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&c)))
    {
        puts("Connection accepted");

        //Reply to the client
        strcpy(message, "Connected to server");
        send(new_sock, message, strlen(message), 0);

        while( (read_size = recv(new_sock , client_message , 2000 , 0)) > 0 )
        {
            // End of client string marker
            client_message[read_size] = '\0';

            // Send client message back to server
            send(new_sock, client_message, strlen(client_message), 0);
            puts(client_message);
        }

        if(read_size == 0)
        {
            puts("Client disconnected");
            fflush(stdout);
        }
        else if(read_size == -1)
        {
            perror("recv failed");
        }
    }
    return 0;
}