//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <ctype.h>

#define PORT 8080
#define MAX_BUFFER 1024

int main(int argc, char const *argv[]) 
{
    int sock = 0;
    struct sockaddr_in server_address;
    char *message = "scan_network";
    char buffer[MAX_BUFFER] = {0};

    // Creating the socket for server
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Initializing the server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0) 
    {
        printf("\n Invalid address/ Address not supported \n");
        return -1;
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        printf("\n Connection Failed \n");
        return -1;
    }

    // Sending scan message to server
    send(sock , message , strlen(message) , 0 );
    printf("Scan message sent to server\n");

    // Printing the wireless network scan results
    while (read(sock, buffer, MAX_BUFFER))
    {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}