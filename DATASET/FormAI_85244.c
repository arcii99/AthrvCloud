//FormAI DATASET v1.0 Category: Simple Web Server ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<memory.h>
#include<unistd.h>

#define BUFFER_SIZE 2048
#define PORT_NUMBER 8080
#define HTML_PATH "/var/www/html"

int main()
{
    int server_fd, client_fd, opt = 1, count, i, read_size, file_size;
    char response[BUFFER_SIZE], buffer[BUFFER_SIZE], file_path[BUFFER_SIZE], *file_data;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    // bind the socket to the given IP and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // start listening on the socket
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started...\n");

    while(1) {
        // accept incoming connections
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_length)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected...\n");

        // read request from client
        memset(buffer, 0, BUFFER_SIZE);
        read_size = read(client_fd, buffer, BUFFER_SIZE);
        printf("Received request from client: %s\n", buffer);

        // extract requested file path from the request
        i = 0;
        while(buffer[i] != ' ') {
            i++;
        }
        i++;
        count = 0;
        while(buffer[i+count] != ' ') {
            file_path[count] = buffer[i+count];
            count++;
        }
        file_path[count] = '\0';

        // generate file path by adding the html root directory path
        char file_path_with_root[strlen(HTML_PATH) + strlen(file_path)];
        strcpy(file_path_with_root, HTML_PATH);
        strcat(file_path_with_root, file_path);

        // read contents of requested file and generate response
        FILE *file_pointer = fopen(file_path_with_root, "rb");
        if(file_pointer == NULL) {
            sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: 23\r\n\r\n<body>404 Not Found</body>\r\n");
            write(client_fd, response, strlen(response));
        }
        else {
            fseek(file_pointer, 0, SEEK_END);
            file_size = ftell(file_pointer);
            fseek(file_pointer, 0, SEEK_SET);
            file_data = malloc(file_size * sizeof(char));
            fread(file_data, sizeof(char), file_size, file_pointer);
            sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s\r\n", file_size, file_data);
            write(client_fd, response, strlen(response));
            fclose(file_pointer);
            free(file_data);
        }

        printf("Response sent to client...\n");
        close(client_fd);
    }
    
    return 0;
}