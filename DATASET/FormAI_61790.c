//FormAI DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000], response[2000], *ptr, *end;
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }
    puts("Socket created");
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    
    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    puts("Bind done");
    
    // Listen
    listen(socket_desc, 3);
    
    // Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");
        
        // Receive a message from client
        memset(client_message, '\0', sizeof client_message);
        if (read_size = recv(client_sock, client_message, 2000, 0) > 0) {
            // Parse client request to get filename
            char *filename = strtok(client_message, " ");
            filename = strtok(NULL, " ");
            char filepath[100];
            sprintf(filepath, ".%s", filename);
            
            // Open file to send to client
            FILE *fp;
            fp = fopen(filepath, "r");
            if (fp == NULL) {
                // If file not found, send error message
                strcpy(response, "HTTP/1.1 404 Not Found\r\n\r\n");
            } else {
                // If file found, read file contents and send to client
                fseek(fp, 0, SEEK_END);
                long fsize = ftell(fp);
                fseek(fp, 0, SEEK_SET);
                
                sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n", fsize);
                int len = strlen(response);
                
                ptr = response + len;
                end = response + sizeof(response);
                
                while(!feof(fp) && ptr < end) {
                    *ptr++ = fgetc(fp);
                }
                fclose(fp);
            }
            
            // Send response to client
            write(client_sock, response, strlen(response));
        }
        
        // Clear response and client_message array
        memset(response, '\0', sizeof response);
        memset(client_message, '\0', sizeof client_message);
        
        close(client_sock);
        puts("Client disconnected");
    }
    
    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }
    
    return 0;
}