//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
//FTP Client Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_desc, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    //create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Error creating socket...\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        printf("Error connecting to FTP server...\n");
        exit(EXIT_FAILURE);
    }

    //listen for server response
    if ((n = read(socket_desc, buffer, BUFFER_SIZE)) < 0) {
        printf("Error reading from FTP server...\n");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    while (1) {
        printf("Enter FTP command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        //send FTP command to server
        if(send(socket_desc, buffer, strlen(buffer), 0) < 0) {
            printf("Error sending FTP command...\n");
            exit(EXIT_FAILURE);
        }

        //listen for server response
        if ((n = read(socket_desc, buffer, BUFFER_SIZE)) < 0) {
            printf("Error reading from FTP server...\n");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';
        printf("%s", buffer);

        //check for quit command
        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        }
    }

    //clean up resources
    close(socket_desc);
    return 0;
}