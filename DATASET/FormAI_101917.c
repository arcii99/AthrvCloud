//FormAI DATASET v1.0 Category: Chat server ; Style: puzzling
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>  
#include <arpa/inet.h> 
#include <unistd.h> 

int main(int argc, char *argv[]) 
{ 

    char msg[] = "I am thinking of a number between 1 and 100. Try guessing it!\n"; 
    char congrats[] = "Congratulations! You've guessed the number!\n"; 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    int num = rand() % 100 + 1; 

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(8080); 

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    printf("The number is %d\n", num);

    send(new_socket , msg , strlen(msg) , 0 ); 

    while(1) {

        valread = read(new_socket , buffer, 1024); 

        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }
        
        int client_num = atoi(buffer);

        if (client_num == num) {
            send(new_socket , congrats , strlen(congrats) , 0 );
            break;
        }

        else if (client_num > num) {
            char high[] = "Your guess is too high. Try guessing again.\n";
            send(new_socket , high , strlen(high) , 0 );
        }

        else {
            char low[] = "Your guess is too low. Try guessing again.\n";
            send(new_socket, low, strlen(low), 0);
        }

    }
    close(new_socket);
    close(server_fd);
    return 0; 
}