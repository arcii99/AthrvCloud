//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

#define PORT 8080    // The port number to connect

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *msg = "QoS Check", buffer[1024] = {0};

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Setup the sockaddr_in structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect the socket
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send the QoS Check message
    send(sock , msg , strlen(msg) , 0 );
    printf("QoS Check message sent\n");
    valread = read( sock , buffer, 1024);

    // Get the current timestamp
    time_t curr_time;
    curr_time = time(NULL);

    // Print the response message
    printf("%s\n",buffer );

    // Calculate the elapsed time and print
    double time_diff = difftime(time(NULL), curr_time);
    printf("Elapsed time: %f seconds\n", time_diff);

    return 0;
}