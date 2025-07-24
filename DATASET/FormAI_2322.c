//FormAI DATASET v1.0 Category: Networking ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080

int establish_connection(){
    int sock = 0;
    struct sockaddr_in serv_addr;

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Error: Socket creation failed \n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
        printf("\n Error: Invalid address or address not supported \n");
        exit(1);
    }

    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("\n Error: Connection failed \n");
        exit(1);
    }

    return sock;
}

void recursive_send(int sock, char message[1024]){
    if(strcmp(message, "exit") == 0){
        printf("\n Exiting \n");
        close(sock);
        exit(0);
    }
    
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    printf("\n Enter your message: ");
    fgets(buffer, 1024, stdin);

    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    recv(sock, buffer, 1024, 0);
    printf("Server response: %s", buffer);

    recursive_send(sock, message);
}

int main(){
    int sock = establish_connection();
    char message[1024] = "start";

    recursive_send(sock, message);

    return 0;
}