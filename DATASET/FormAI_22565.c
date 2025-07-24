//FormAI DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from the other side";
    char buffer[1024] = {0};
    
    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error \n");
        return -1;
    }
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address / Address not supported \n");
        return -1;
    }
    
    // connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection Failed \n");
        return -1;
    }
    
    int i;
    for (i = 0; i < 3; i++) {
        // send message to server
        send(sock, hello, strlen(hello), 0);
        printf("Message sent to server. \n");
        
        // receive message from server
        valread = read(sock, buffer, 1024);
        printf("Server response: %s\n", buffer);
        
        sleep(2);
    }
    
    printf("Goodbye! \n");
    return 0;
}