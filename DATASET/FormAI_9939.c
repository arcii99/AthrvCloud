//FormAI DATASET v1.0 Category: Firewall ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define PORT 1234
#define MAX_BUFFER_SIZE 1024
#define MAX_CLIENTS 10

struct client{
    int socket_fd;
    char ip_address[16]; // since IPv4 is of length 16
    int port;
};

typedef struct client Client;

Client clients[MAX_CLIENTS];

int main(){
    //initialize the clients
    int i;
    for(i = 0; i < MAX_CLIENTS; i++){
        clients[i].socket_fd = 0;
        strcpy(clients[i].ip_address,"");
        clients[i].port = 0;
    }
    
    //create a socket
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket_fd < 0) {
        perror("ERROR: Could not create socket.\n");
        exit(-1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket with the server address
    if(bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        perror("ERROR: Bind failed.\n");
        exit(-1);
    }
    
    // Listen for incoming connections
    if(listen(server_socket_fd , MAX_CLIENTS) < 0){
        perror("ERROR: Listen failed.\n");
        exit(-1);
    }
    
    // Accept an incoming connection
    socklen_t client_address_size = sizeof(client_address);
    while((client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_size ))) {
        char buffer[MAX_BUFFER_SIZE];
        memset(buffer, 0, sizeof(buffer));

        //Get client information;
        char client_ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_address.sin_addr), client_ip_address, INET_ADDRSTRLEN);
        int client_port = ntohs(client_address.sin_port);

        //Record client information
        int index = -1;
        for(i = 0; i < MAX_CLIENTS; i++){
            if(clients[i].socket_fd == 0){
                index = i;
                clients[index].socket_fd = client_socket_fd;
                strcpy(clients[index].ip_address, client_ip_address);
                clients[index].port = client_port;
                break;
            }
        }
        
        //If no space available to store
        if(index == -1){
            printf("WARNING: Maximum clients reached. Connection closed for client %s:%d.\n", client_ip_address, client_port);
            close(client_socket_fd);
            continue;
        }
        
        //accept connection
        printf("INFO: Connection established with client %s:%d.\n", client_ip_address, client_port);
        
        //Record connection time
        time_t now = time(NULL);
        char *formatted_time = ctime(&now);
        formatted_time[strlen(formatted_time)-1] = '\0';
        printf("INFO: Connection established with client %s:%d at %s.\n", client_ip_address, client_port, formatted_time);

        pid_t child_pid;
        child_pid = fork();
        if (child_pid < 0) {
            printf("ERROR: Could not fork process.\n");
            exit(-1);
        }
        
        if (child_pid == 0){
            //Child process
            close(server_socket_fd);
            
            //Add firewall rules here
            
            while(1){
                memset(buffer, 0, sizeof(buffer));
                int bytes_received = recv(client_socket_fd, buffer, sizeof(buffer), 0);

                if(bytes_received <= 0){
                    printf("WARNING: Connection lost with client %s:%d.\n", clients[index].ip_address, clients[index].port);
                    close(client_socket_fd);
                    clients[index].socket_fd = 0;
                    break;
                }

                printf("INFO: Data received from client %s:%d : %s\n", clients[index].ip_address, clients[index].port, buffer);
                fflush(stdout);

                //Add response here

            }
            exit(0);
        }
        else{
            //Parent process
            close(client_socket_fd);
        }
    }
    close(server_socket_fd);

    return 0;
}