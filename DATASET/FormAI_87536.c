//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#define MAX_BUFF_SIZE 4096

/* Function to trim whitespace from beginning and end of a string */
char *trim(char *str) {
    while (isspace(*str)) str++;
    if (*str == 0) return str;
    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end+1) = 0;
    return str;
}

/* Function to send and receive data to and from the server */
void send_recv(int client_socket, const char *message) {
    char buffer[MAX_BUFF_SIZE];
    memset(buffer, 0, sizeof(buffer));
    send(client_socket, message, strlen(message), 0);
    recv(client_socket, buffer, MAX_BUFF_SIZE, 0);
    printf("%s", buffer);
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    //Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    printf("Socket created\n");

    //Set server address details
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);

    //Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }
    printf("Connected to server\n");

    //Receive welcome message from server
    char buffer[MAX_BUFF_SIZE];
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, MAX_BUFF_SIZE, 0);
    printf("%s", buffer);

    //Send username and password to server
    send_recv(client_socket, "USER anonymous\r\n");
    send_recv(client_socket, "PASS password\r\n");

    //Send command to change directory
    send_recv(client_socket, "CWD /\r\n");

    //Send command to list files in directory
    send_recv(client_socket, "LIST\r\n");

    //Receive file list from server
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, MAX_BUFF_SIZE, 0);
    printf("%s", buffer);

    //Send command to close connection
    send_recv(client_socket, "QUIT\r\n");

    //Close socket
    close(client_socket);

    return 0;
}