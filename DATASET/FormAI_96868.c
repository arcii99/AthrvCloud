//FormAI DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUMBER 1337

static char* get_value(char* message, char* var_name) {
    // helper function to get values from GET requests
    char* found = strstr(message, var_name);
    if (found == NULL) return NULL;
    int var_len = strlen(var_name);
    int value_len = 0;
    while (*(found + var_len + value_len) != ' ') value_len++; 
    char* result = calloc(value_len + 1, sizeof(char));
    strncpy(result, found + var_len, value_len);
    return result;
}

int main(int argc, char** argv) {
    // initialize socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // bind socket to port
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT_NUMBER),
        .sin_addr.s_addr = INADDR_ANY
    };
    bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    
    // listen to incoming connections
    listen(sockfd, 10);
    
    // handle incoming connections
    while(1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_size);
        
        // read request
        char buffer[1024];
        int bytes_read = read(client_sockfd, buffer, sizeof(buffer));
        
        // parse request
        char* method = strtok(buffer, " ");
        char* path = strtok(NULL, " ");
        char* protocol = strtok(NULL, "\r\n");
        
        // handle GET requests
        if (strcmp(method, "GET") == 0) {
            char response[1024];
            char* content = "Hello World!";
            
            // check if there is a query string
            char* query_start = strchr(path, '?');
            if (query_start != NULL) {
                char* name = get_value(query_start, "name=");
                if (name != NULL) {
                    sprintf(content, "Hello, %s!", name);
                    free(name);
                } 
            }
            
            // send response
            sprintf(response, "%s 200 OK\nContent-Type:text/html\nContent-Length:%d\n\n%s", protocol, strlen(content), content);
            write(client_sockfd, response, strlen(response));
        }
        
        // close connection
        close(client_sockfd);
    }
    
    // close socket
    close(sockfd);
    return 0;
}