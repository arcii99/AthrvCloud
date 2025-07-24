//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

#define MAX_BUFFER_SIZE 1024 

int main(int argc, char *argv[]) 
{ 
    int socket_desc; 
    struct sockaddr_in server; 
    char *server_ip, *username, *password; 
    char recv_buffer[MAX_BUFFER_SIZE]; 
    int bytes_received; 
    char send_buffer[MAX_BUFFER_SIZE], *command; 

    if(argc < 4) 
    { 
        printf("Usage: %s <server_ip> <username> <password>\n", argv[0]); 
        return 1; 
    } 

    server_ip = argv[1]; 
    username = argv[2]; 
    password = argv[3]; 

    socket_desc = socket(AF_INET, SOCK_STREAM, 0); 
     
    if(socket_desc == -1) 
    { 
        printf("Error: Could not create socket\n"); 
        return 1; 
    } 

    server.sin_addr.s_addr = inet_addr(server_ip); 
    server.sin_family = AF_INET; 
    server.sin_port = htons(110); 

    if(connect(socket_desc, (struct sockaddr *)&server , sizeof(server)) < 0) 
    { 
        printf("Error: Connection failed\n"); 
        return 1; 
    } 

    memset(recv_buffer, '\0', MAX_BUFFER_SIZE); 
    bytes_received = recv(socket_desc, recv_buffer, MAX_BUFFER_SIZE, 0); 
    if(bytes_received < 0) 
    { 
        printf("Error: Response not received from server\n"); 
        return 1; 
    } 
    printf("%s\n", recv_buffer); 

    sprintf(send_buffer, "USER %s\r\n", username); 
    send(socket_desc, send_buffer, strlen(send_buffer), 0); 

    memset(recv_buffer, '\0', MAX_BUFFER_SIZE); 
    bytes_received = recv(socket_desc, recv_buffer, MAX_BUFFER_SIZE, 0); 
    if(bytes_received < 0) 
    { 
        printf("Error: Response not received from server\n"); 
        return 1; 
    } 
    printf("%s\n", recv_buffer); 

    sprintf(send_buffer, "PASS %s\r\n", password); 
    send(socket_desc, send_buffer, strlen(send_buffer), 0); 

    memset(recv_buffer, '\0', MAX_BUFFER_SIZE); 
    bytes_received = recv(socket_desc, recv_buffer, MAX_BUFFER_SIZE, 0); 
    if(bytes_received < 0) 
    { 
        printf("Error: Response not received from server\n"); 
        return 1; 
    } 
    printf("%s\n", recv_buffer); 

    sprintf(send_buffer, "LIST\r\n"); 
    send(socket_desc, send_buffer, strlen(send_buffer), 0); 

    memset(recv_buffer, '\0', MAX_BUFFER_SIZE); 
    bytes_received = recv(socket_desc, recv_buffer, MAX_BUFFER_SIZE, 0); 
    if(bytes_received < 0) 
    { 
        printf("Error: Response not received from server\n"); 
        return 1; 
    } 
    printf("%s\n", recv_buffer); 

    sprintf(send_buffer, "QUIT\r\n"); 
    send(socket_desc, send_buffer, strlen(send_buffer), 0); 

    memset(recv_buffer, '\0', MAX_BUFFER_SIZE); 
    bytes_received = recv(socket_desc, recv_buffer, MAX_BUFFER_SIZE, 0); 
    if(bytes_received < 0) 
    { 
        printf("Error: Response not received from server\n"); 
        return 1; 
    } 
    printf("%s\n", recv_buffer); 

    close(socket_desc); 
    return 0; 
}