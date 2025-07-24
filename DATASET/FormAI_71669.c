//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 666

int main(){
    printf("Welcome to the networking world, I'm your chatbot TCP server\n\n");

    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    char server_message[256] = "Hey there! I'm your TCP server, what's your name?\n";
    send(client_socket, server_message, sizeof(server_message), 0);

    char client_response[256];
    recv(client_socket, &client_response, sizeof(client_response), 0);
    
    printf("Client says: %s\n", client_response);
    sleep(1);
    printf("Hmmm, that's an interesting name. Do you like programming?\n");
    sleep(1);

    char *programming_question = "Do you like programming?\n";
    send(client_socket, programming_question, sizeof(programming_question), 0);
    
    char programming_answer[256];
    recv(client_socket, &programming_answer, sizeof(programming_answer), 0);
    
    if (strcmp(programming_answer, "Yes") == 0){
        printf("Awesome, me too!\n");
    }
    else{
        printf("Too bad, programming is the best!\n");
    }
    
    close(client_socket);
    close(server_socket);

    return 0;
}