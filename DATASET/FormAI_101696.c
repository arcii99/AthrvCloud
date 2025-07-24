//FormAI DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define HTTP_STATUS_OK 200
#define HTTP_STATUS_NOT_FOUND 404
#define HTTP_CONTENT_HTML "text/html"
#define SERVER_NAME "SimpleCWebServer/1.0"

char *get_file_extension(const char *filename) {
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) {
        return "";
    }
    return dot + 1;
}

void send_http_response(int sock_fd, int status_code, const char *content_type, const char *content) {
    char response[1024];
    char http_header[512];

    sprintf(response, "<html><head><title>%d %s</title></head><body>%s</body></html>", status_code, (status_code == HTTP_STATUS_OK) ? "OK" : "Not Found", content);
    sprintf(http_header, "HTTP/1.1 %d %s\r\nServer: %s\r\nContent-Type: %s\r\nContent-Length: %ld\r\nConnection: close\r\n\r\n", 
            status_code, (status_code == HTTP_STATUS_OK) ? "OK" : "Not Found", SERVER_NAME, content_type, strlen(response));
    
    write(sock_fd, http_header, strlen(http_header));
    write(sock_fd, response, strlen(response));
}

int main(int argc, char *argv[]) {
    int server_fd, client_fd, opt = 1, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    //Create TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    //Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }
    
    //Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8000);
    
    //Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    //Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    
    //Accept incoming connection
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    
    //Read request data
    valread = read(client_fd, buffer, 1024);
    
    //Parse request
    char http_method[16], http_path[256];
    sscanf(buffer, "%s %s", http_method, http_path);
    
    //Serve file
    if (strcmp(http_method, "GET") == 0) {
        char filename[512];
        sprintf(filename, "public%s", http_path);
        
        if (access(filename, F_OK) != -1) {
            int file_fd = open(filename, O_RDONLY);
            struct stat file_stat;
            fstat(file_fd, &file_stat);
            char *file_ext = get_file_extension(filename);
            
            char *content_type = HTTP_CONTENT_HTML;
            if (strcmp(file_ext, "png") == 0) {
                content_type = "image/png";
            } else if (strcmp(file_ext, "jpg") == 0 || strcmp(file_ext, "jpeg") == 0) {
                content_type = "image/jpeg";
            }
            
            char *file_content = malloc(file_stat.st_size + 1);
            read(file_fd, file_content, file_stat.st_size);
            file_content[file_stat.st_size] = '\0';
            
            send_http_response(client_fd, HTTP_STATUS_OK, content_type, file_content);
            
            free(file_content);
            close(file_fd);
        } else {
            char *error_msg = "Oops! The requested file could not be found.";
            send_http_response(client_fd, HTTP_STATUS_NOT_FOUND, HTTP_CONTENT_HTML, error_msg);
        }
    } else {
        char *error_msg = "Invalid HTTP request method.";
        send_http_response(client_fd, HTTP_STATUS_NOT_FOUND, HTTP_CONTENT_HTML, error_msg);
    }
    
    //Clean-up
    close(client_fd);
    close(server_fd);
    
    return 0;
}