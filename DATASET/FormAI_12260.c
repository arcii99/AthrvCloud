//FormAI DATASET v1.0 Category: Simple Web Server ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

//Function to handle HTTP request and send response to the client
void handle_request(int client_socket)
{
    char buffer[1024];
    size_t bytes_read;
    memset(buffer, 0, sizeof(buffer));
    bytes_read = read(client_socket, buffer, sizeof(buffer));

    //parsing the HTTP request for the GET method
    if(bytes_read > 0)
    {
        char* method = strtok(buffer, " ");
        char* path = strtok(NULL, " ");
        char* protocol = strtok(NULL, "\r\n");

        printf("Request received for the path: %s\n", path);

        //serving the request for the index.html file
        if(strcmp(path, "/") == 0)
        {
            path = "/index.html";
        }

        //opening the file
        int fd = open(path+1, O_RDONLY);

        //file not found
        if(fd == -1)
        {
            char* response = "HTTP/1.0 404 NOT FOUND\r\n"
                            "Content-Type: text/html\r\n"
                            "\r\n"
                            "<html><body><h1>404 Not Found</h1></body></html>\r\n";

            write(client_socket, response, strlen(response));
            close(client_socket);
            return;
        }

        //file found, send the response
        else
        {
            char response_header[1024];

            sprintf(response_header, "HTTP/1.0 200 OK\r\n"
                                    "Content-Type: text/html\r\n"
                                    "\r\n");

            write(client_socket, response_header, strlen(response_header));

            while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
            {
                write(client_socket, buffer, bytes_read);
            }
        }

        //closing file descriptor
        close(fd);
        close(client_socket);
    }
}

int main(int argc, char** argv)
{
    //creating socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //error in creating socket
    if(server_socket < 0)
    {
        printf("Error creating socket\n");
        exit(0);
    }

    //server address initialization
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
   
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    //binding address and port to the socket
    int bind_status = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    //error in binding
    if(bind_status != 0)
    {
        printf("Error binding socket\n");
        exit(0);
    }

    //listening for incoming requests
    int listen_status = listen(server_socket, 10);

    //error in listening
    if(listen_status != 0)
    {
        printf("Error listening for incoming requests\n");
        exit(0);
    }

    printf("Server listening on port 8080...\n");

    //accepting incoming connections and spawning a new thread for each request
    while(1)
    {
        struct sockaddr_in client_address;
        socklen_t client_length = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_length);

        if(client_socket < 0)
        {
            printf("Error accepting incoming connection\n");
            exit(0);
        }

        handle_request(client_socket);
    }

    //closing server socket
    close(server_socket);

    return 0;
}