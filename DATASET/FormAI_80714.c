//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multiplayer
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define PORT 8080 
#define MAXPLAYERS 10 
#define BUFFER_SIZE 1024 

int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[BUFFER_SIZE] = {0}; 
    char response[BUFFER_SIZE] = {0}; 
    char player_names[MAXPLAYERS][BUFFER_SIZE]; 
    int players[MAXPLAYERS] = {0}; 
    int player_count = 0; 

    // create socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // set socket options to reuse address and port 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 

    // bind the socket to the address and port 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // start listening for client connections 
    if (listen(server_fd, MAXPLAYERS) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    // wait for player connections and add them to the game 
    while (player_count < MAXPLAYERS) 
    { 
        printf("Waiting for player %d...\n", player_count+1); 
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 
        players[player_count] = new_socket; 
        read(new_socket, buffer, BUFFER_SIZE); 
        strcpy(player_names[player_count], buffer); 
        printf("%s connected!\n", player_names[player_count]); 
        player_count++; 
    } 

    // send start message to all players 
    for (int i=0; i<player_count; i++) 
    { 
        sprintf(response, "Starting game with players:"); 
        for (int j=0; j<player_count; j++) 
        { 
            sprintf(buffer, " %s", player_names[j]); 
            strcat(response, buffer); 
        } 
        strcat(response, "\n"); 
        send(players[i], response, strlen(response), 0); 
    } 

    // start game loop 
    int turn = 0; 
    int playernum; 
    while(1) 
    { 
        playernum = turn % player_count; 
        memset(buffer, 0, BUFFER_SIZE); 
        sprintf(buffer, "It's your turn, %s!", player_names[playernum]); 
        send(players[playernum], buffer, strlen(buffer), 0); 
        memset(buffer, 0, BUFFER_SIZE); 
        read(players[playernum], buffer, BUFFER_SIZE); 
        sprintf(response, "%s played: %s", player_names[playernum], buffer); 
        printf("%s\n", response); 
        for (int i=0; i<player_count; i++) 
        { 
            if (i != playernum) 
            { 
                send(players[i], response, strlen(response), 0); 
            } 
        } 
        turn++; 
    } 
    return 0; 
}