//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1000
#define PORT 8080
#define SERVER_IP "127.0.0.1"


int main(int argc, char *argv[])
{
    int client_socket, n;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    clock_t start, finish;
    float time_taken;
    long int size;
    
    // Create a socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr)<=0){
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        printf("\nConnection Failed \n");
        return -1;
    }
    
    // Send data to server
    char *message = "Hello server, I am client";
    send(client_socket, message, strlen(message), 0 );
    
    // Receive data from server
    memset(buffer, 0, sizeof(buffer));
    n = read(client_socket, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    
    // Send data to server
    message = "Please send the test file size";
    send(client_socket, message, strlen(message), 0 );
    
    // Receive data from server
    memset(buffer, 0, sizeof(buffer));
    n = read(client_socket, buffer, BUFFER_SIZE);
    size = atol(buffer);
    
    // Send data to server
    message = "Ready to start download";
    send(client_socket, message, strlen(message), 0 );
    
    // Receive data from server and measure time taken
    start = clock();
    long int total_bytes = 0;
    while(total_bytes < size){
        memset(buffer, 0, sizeof(buffer));
        n = read(client_socket, buffer, BUFFER_SIZE);
        total_bytes += n;
    }
    finish = clock();
    time_taken = (float)(finish - start)/CLOCKS_PER_SEC;
    
    // Calculate and display download speed
    float speed = (size/(1024*1024))/time_taken; // in MB/s
    printf("\nDownload completed successfully in %f seconds, with speed of %f MB/s", time_taken, speed);
    
    // Close socket
    close(client_socket);
    return 0;
}