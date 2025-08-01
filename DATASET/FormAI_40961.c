//FormAI DATASET v1.0 Category: Simple Web Server ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//Function to handle request from client
void handle_request(int client_socket)
{
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>\n";
    send(client_socket, response, strlen(response), 0);
}

//Main function
int main(int argc, char *argv[])
{
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    //Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc, 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c)))
    {
        puts("Connection accepted");

        //Receive a message from client
        while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0)
        {
            //handle the request
            handle_request(client_sock);

            //clear the message buffer
            memset(client_message, 0, sizeof(client_message));
        }

        if (read_size == 0)
        {
            puts("Client disconnected");
            fflush(stdout);
        }
        else if (read_size == -1)
        {
            perror("recv failed");
        }
    }

    return 0;
}