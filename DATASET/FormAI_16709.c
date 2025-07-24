//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
     
    //Check if user provided enough arguments
    if(argc < 2)
    {
        printf("Please provide a hostname or an IP address\n");
        exit(1);
    }

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);

    if (sock == -1)
    {
        printf("Could not create socket\n");
    }
     
    //Fill in server details
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
     
    //Scan for ports
    int i;
    for(i = 1; i <= 65535; i++) {
        
        //Fill in the server port for each iteration
        server.sin_port = htons(i);
         
        //Connect to server at specified port
        if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            //Port is closed or filtered
            continue;
        }
        else
        {
            //Port is open and accepting connections
            printf("Port %d is open\n" , i);
        }
        
        //Close the socket
        close(sock);
         
        //Create new socket for next port scan
        sock = socket(AF_INET , SOCK_STREAM , 0);
    }
     
    return 0;
}