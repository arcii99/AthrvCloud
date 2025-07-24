//FormAI DATASET v1.0 Category: Networking ; Style: energetic
//Welcome to the Energetic C Networking Example Program!

//First let's include the essential libraries
#include <stdio.h>      //for standard input/output
#include <stdlib.h>     //for memory allocation/freeing
#include <string.h>     //for string manipulation
#include <sys/socket.h> //for socket related functions
#include <netinet/in.h> //for internet-related functions
#include <unistd.h>     //for read/write functions

//Now let's define some constants
#define PORT 8080
#define MAX_MSG_LEN 1024

//The main program starts here
int main(int argc, char const *argv[])
{
    int server_fd, new_socket;                     //Declaring socket file descriptors
    struct sockaddr_in address;                     //Declaring Internet socket address structure
    int opt = 1;                                    //Option variable for setsockopt
    int addrlen = sizeof(address);                  //Length of address structure
    char buffer[MAX_MSG_LEN] = {0};                 //Buffer to store incoming messages
    char *hello = "Hello from the server!";          //Message to send to the client

    //Creating a TCP socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                   &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    //Setting server address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    //Binding the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    //Listening to incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    //Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    //Reading from client and sending a message back
    int valread = read(new_socket, buffer, MAX_MSG_LEN);
    printf("Received message from client: %s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent to client\n");

    return 0;
}