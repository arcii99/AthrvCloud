//FormAI DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 1024
#define CONFIG_FILE "config.txt"

void send_data(int client_sock, char *response) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", strlen(response));
    strcat(buffer, response);
    send(client_sock, buffer, strlen(buffer), 0);
}

int main() {
    int server_sock, client_sock, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int port = DEFAULT_PORT;
    
    // Read config file
    FILE *config_file = fopen(CONFIG_FILE, "r");
    if (config_file) {
        char config_str[BUFFER_SIZE];
        if (fgets(config_str, BUFFER_SIZE, config_file) != NULL) {
            char *token = strtok(config_str, " ");
            int i = 0;
            while (token) {
                if (i == 0) {
                    port = atoi(token);
                }
                token = strtok(NULL, " ");
                i++;
            }
        }
        fclose(config_file);
    }
    
    // Create server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }
    
    // Bind server socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not bind socket to port %d\n", port);
        return 1;
    }
    
    // Listen for connections
    listen(server_sock, 5);
    
    printf("Server started on port %d\n", port);
    
    while (1) {
        client_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
        if (client_sock < 0) {
            printf("Error: Could not accept connection\n");
            continue;
        }
        
        // Process request
        recv(client_sock, buffer, BUFFER_SIZE, 0);
        printf("%s\n", buffer);
        
        char *response = "<html><head><title>My Web Page</title></head><body><h1>Hello, World!</h1></body></html>";
        send_data(client_sock, response);
        
        close(client_sock);
    }
    
    close(server_sock);
    return 0;
}