//FormAI DATASET v1.0 Category: Networking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int socket_desc, client_sock, c, read_size, port_number;
    struct sockaddr_in server, client;
    char client_message[2000];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1){
        puts("Could not create socket");
        return 1;
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    //Create socket, add surrealism with some colors
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0){
        puts("\033[1;31mBind failed\033[0m");
        return 1;
    }

    puts("\033[1;34mWaiting for incoming connections...\033[0m");
    listen(socket_desc, 3);

    while (1){
        c = sizeof(struct sockaddr_in);
        client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
        if (client_sock < 0){
            puts("Accept failed");
            return 1;
        }
        puts("\033[1;32mConnection accepted\033[0m");

        //Receive a message from client and surrealismify it
        while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0){
            //Surrealismify message
            for (int i=0; i<read_size; i++){
                if (i % 2 == 0){
                    printf("\033[1;38;5;%dm%c\033[0m", 200+i, client_message[i]);
                }
                else{
                    printf("\033[1;38;5;%dm%c\033[0m", 100+i, client_message[i]);
                }
            }
            fflush(stdout);
        }

        if (read_size == 0){
            puts("Client disconnected");
            fflush(stdout);
        }
        else if (read_size == -1){
            puts("Error reading from socket");
        }
    }

    return 0;
}