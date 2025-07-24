//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
/* Programming Example:
Title: Temperature Sensor Server using Socket Programming in C

Objective:
This program creates a TCP/IP socket server for a temperature sensor device. The sensor is simulated by continuously generating random temperature values between 0 to 100 degrees Celsius. The server listens for client connections, accepts multiple client connections, and sends temperature data to each client connection upon request.

Implementation:
The program uses the following steps to implement the temperature sensor server:
1. Initialize a TCP/IP socket for the server and bind it to a specific port number.
2. Listen for client connections and accept them.
3. Create a child process for each client connection and communicate with them using a separate socket.
4. In each child process, continuously generate a random temperature value, and send it to the client upon request.
5. Handle errors and close sockets when necessary.

Program Code:
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("\nWaiting for client connection...\n");
        
        // Accept incoming client connection request
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                           (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Client connected successfully\n");
        
        // Create child process for new client connection
        int pid = fork();
        if(pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE); 
        }
        else if(pid == 0) // child process
        {
            printf("Child process created for client connection\n");
            close(server_fd); // Close listening socket in child process
            
            // Continuously generate and send simulated temperature values to client
            while(1)
            {
                memset(buffer, 0, sizeof(buffer)); // Reset buffer
                
                // Wait for client request message
                if ((valread = read(new_socket , buffer, 1024)) > 0)
                {
                    printf("Message from client: %s\n",buffer );
                    
                    // Generate random simulated temperature value in Celsius
                    srand(time(0));   // seed random number generator 
                    int temp = rand() % 101; // generate random number between 0 to 100
                    
                    // Convert temperature value to string
                    char temp_str[5];
                    sprintf(temp_str, "%d", temp);
                    
                    // Send temperature value to client
                    send(new_socket , temp_str , strlen(temp_str) , 0 );
                    printf("Temperature value sent to client: %d\n", temp);
                }
                else if(valread == 0)
                {
                    printf("Connection closed by client\n");
                    break; // exit loop if client connection is closed
                }
                else
                {
                    perror("read");
                    break; // exit loop if error occurs
                }
            }
            // Close client socket in child process
            close(new_socket);
            printf("Child process exiting...\n");
            exit(0); // exit child process when temperature sensor task is complete
        }
        else // parent process
        {
            // Close new client connection socket in parent process
            close(new_socket);
        }
    }
    // Close socket in parent process
    close(server_fd);
    printf("Server socket closed\n");
    return 0;
}