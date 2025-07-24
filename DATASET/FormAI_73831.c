//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
//FTP Client Program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    
    int client_socket, data_socket;                   
    struct sockaddr_in server_address, data_address;    
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int response_code;
    int bytes_sent, bytes_received;
    long int filesize;
    FILE *file;
    
    /* create TCP socket */
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error: creating socket");
        exit(1);
    }
    
    /* specify server address */
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(21);
    
    /* connect to server */
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error: connecting to server");
        exit(1);
    }
    
    /* receive welcome message */
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_received < 0) {
        perror("Error: receiving message from server");
        exit(1);
    }
    printf("%s", buffer);
    
    /* send username */
    printf("Username: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    sprintf(command, "USER %s", buffer);
    bytes_sent = write(client_socket, command, strlen(command));
    if (bytes_sent < 0) {
        perror("Error: sending message to server");
        exit(1);
    }
    
    /* receive username response */
    memset(response, 0, BUFFER_SIZE);
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_received < 0) {
        perror("Error: receiving message from server");
        exit(1);
    }
    strcpy(response, buffer);
    response_code = atoi(strtok(buffer, " "));
    printf("%s", response);
    
    /* send password */
    printf("Password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    sprintf(command, "PASS %s", buffer);
    bytes_sent = write(client_socket, command, strlen(command));
    if (bytes_sent < 0) {
        perror("Error: sending password to server");
        exit(1);
    }
    
    /* receive password response */
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_received < 0) {
        perror("Error: receiving message from server");
        exit(1);
    }
    response_code = atoi(strtok(buffer, " "));
    if (response_code != 230) {
        printf("%s", buffer);
        exit(1);
    }
    
    /* enter passive mode */
    bytes_sent = write(client_socket, "PASV\r\n", strlen("PASV\r\n"));
    if (bytes_sent < 0) {
        perror("Error: sending PASV command to server");
        exit(1);
    }
    
    /* receive passive mode response */
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_received < 0) {
        perror("Error: receiving message from server");
        exit(1);
    }
    response_code = atoi(strtok(buffer, " "));
    if (response_code != 227) {
        printf("%s", buffer);
        exit(1);
    }
    strtok(buffer, "(");
    strtok(NULL, "(");
    strtok(NULL, "(");
    strtok(NULL, "(");
    sscanf(strtok(NULL, "("), "%d,%d,%d,%d,%d,%d", (int*) &data_address.sin_addr.s_addr + 0, 
            (int*) &data_address.sin_addr.s_addr + 1, (int*) &data_address.sin_addr.s_addr + 2, 
            (int*) &data_address.sin_addr.s_addr + 3, &data_address.sin_port, &data_address.sin_port + 1);
    
    /* open data connection */
    data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket < 0) {
        perror("Error: creating data socket");
        exit(1);
    }
    if (connect(data_socket, (struct sockaddr*) &data_address, sizeof(data_address)) < 0) {
        perror("Error: connecting to data connection");
        exit(1);
    }
    
    /* send RETR command */
    printf("Download file: ");
    fgets(filename, BUFFER_SIZE, stdin);
    filename[strlen(filename) - 1] = '\0';
    sprintf(command, "RETR %s\r\n", filename);
    bytes_sent = write(client_socket, command, strlen(command));
    if (bytes_sent < 0) {
        perror("Error: sending RETR command to server");
        exit(1);
    }
    
    /* receive RETR response */
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_received < 0) {
        perror("Error: receiving message from server");
        exit(1);
    }
    response_code = atoi(strtok(buffer, " "));
    if (response_code != 150) {
        printf("%s", buffer);
        exit(1);
    }

    /* receive file */
    file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error: opening file for writing");
        exit(1);
    }
    memset(buffer, 0, BUFFER_SIZE);
    while ((bytes_received = read(data_socket, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }
    fclose(file);
    
    /* receive RETR response */
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_received < 0) {
        perror("Error: receiving message from server");
        exit(1);
    }
    printf("%s", buffer);
    
    /* close data connection */
    close(data_socket);
    
    /* exit */
    close(client_socket);
    printf("FTP client disconnecting...\n");
    
    return 0;
}