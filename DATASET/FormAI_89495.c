//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

#define BUFFER_SIZE 1024

void error_handler(char *message) 
{ 
    perror(message); 
    exit(1); 
} 

int main(int argc, char *argv[]) 
{ 
    struct sockaddr_in server_address; 
    int socket_fd; 

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        error_handler("Socket creation failed"); 

    memset(&server_address, '0', sizeof(server_address)); 
   
    // Set up server address parameters
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(21); 

    // Convert IP address from string to binary format
    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr)<=0) 
    { 
        printf("\nInvalid address or address not supported\n"); 
        return -1; 
    } 

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
        error_handler("Connection Failed"); 

    // Read server response
    char buffer[BUFFER_SIZE]; 
    read(socket_fd, buffer, BUFFER_SIZE);
    printf("%s", buffer); 

    // Send username
    char username[100];
    printf("Enter username: ");
    scanf("%s", username);
    char user_cmd[150];
    sprintf(user_cmd, "USER %s\n", username);
    send(socket_fd, user_cmd, strlen(user_cmd), 0); 

    // Read server response
    memset(buffer, 0, BUFFER_SIZE);
    read(socket_fd, buffer, BUFFER_SIZE); 
    printf("%s", buffer);

    // Send password
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    char pass_cmd[150];
    sprintf(pass_cmd, "PASS %s\n", password);
    send(socket_fd, pass_cmd, strlen(pass_cmd), 0); 

    // Read server response
    memset(buffer, 0, BUFFER_SIZE);
    read(socket_fd, buffer, BUFFER_SIZE); 
    printf("%s", buffer);

    // Enter passive mode
    send(socket_fd, "PASV\n", strlen("PASV\n"), 0); 

    // Read server response
    memset(buffer, 0, BUFFER_SIZE);
    read(socket_fd, buffer, BUFFER_SIZE); 
    printf("%s", buffer);

    // Extract IP address and port number from server response
    char ip_address[30];
    int port1, port2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", 
        &ip_address[0], &ip_address[1],
        &ip_address[2], &ip_address[3],
        &port1, &port2);
    int data_port = port1*256 + port2;

    // Connect to data port
    struct sockaddr_in data_address; 
    int data_socket_fd;
    if ((data_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        error_handler("Data socket creation failed"); 
    memset(&data_address, '0', sizeof(data_address)); 
    data_address.sin_family = AF_INET; 
    data_address.sin_port = htons(data_port);
    if(inet_pton(AF_INET, ip_address, &data_address.sin_addr)<=0) 
    { 
        printf("\nInvalid address or address not supported\n"); 
        return -1; 
    } 
    if (connect(data_socket_fd, (struct sockaddr *)&data_address, sizeof(data_address)) < 0) 
        error_handler("Data connection failed"); 

    // Download file
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    char retr_cmd[150];
    sprintf(retr_cmd, "RETR %s\n", filename);
    send(socket_fd, retr_cmd, strlen(retr_cmd), 0); 

    // Read server response
    memset(buffer, 0, BUFFER_SIZE);
    read(socket_fd, buffer, BUFFER_SIZE); 
    printf("%s", buffer);

    // Read file data from data port and save to file
    FILE *f = fopen(filename, "wb");
    int bytes_received;
    while ((bytes_received = read(data_socket_fd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytes_received, f);
    }
    fclose(f);

    // Close data connection
    close(data_socket_fd);

    // Read server response
    memset(buffer, 0, BUFFER_SIZE);
    read(socket_fd, buffer, BUFFER_SIZE); 
    printf("%s", buffer);

    // Quit
    send(socket_fd, "QUIT\n", strlen("QUIT\n"), 0); 

    // Read server response
    memset(buffer, 0, BUFFER_SIZE);
    read(socket_fd, buffer, BUFFER_SIZE); 
    printf("%s", buffer);
    close(socket_fd); 
    return 0; 
}