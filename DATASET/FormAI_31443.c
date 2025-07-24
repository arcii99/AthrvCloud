//FormAI DATASET v1.0 Category: Chat server ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc , char *argv[])
{
    int sock_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];

    // create socket
    sock_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (sock_desc == -1) {
        printf("Could not create socket :(");
        return 1;
    }
    puts("Socket created \\( ﾟヮﾟ)/");

    // prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    // bind
    if( bind(sock_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("bind failed :(");
        return 1;
    }
    puts("Bind done! [ง'̀-'́]ง");

    // listen
    listen(sock_desc , 3);

    // accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while( (client_sock = accept(sock_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted! \\( ﾟヮﾟ)/");

        // receive message from client
        while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
        {
            // reply to client
            write(client_sock , client_message , strlen(client_message));
            memset(client_message, 0, 2000);
        }

        if(read_size == 0)
        {
            puts("Client disconnected! (╯°□°)╯︵ ┻━┻");
            fflush(stdout);
        }
        else if(read_size == -1)
        {
            puts("recv failed :(");
            fflush(stdout);
        }
    }

    return 0;
}