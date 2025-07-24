//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void shapeShift(char* message, int length);

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
   
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
   
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    char message[1024] = {0};

    while(1){
        valread = read( new_socket , buffer, 1024);
        if(strcmp(buffer, "exit") == 0){
            break;
        }
        shapeShift(buffer, strlen(buffer));
        printf("Received Message: %s", buffer);
        send(new_socket , buffer , strlen(buffer) , 0 );    
    }

    close(server_fd);
    return 0;
}

void shapeShift(char* message, int length){
    for(int i = 0; i < length; i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = message[i] + 32;
        }
        else if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = message[i] - 32;
        }
        else{
            continue;
        }
    }
}