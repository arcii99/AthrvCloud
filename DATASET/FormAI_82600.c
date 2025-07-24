//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 5555

int main(){

    int socket_desc;
    struct sockaddr_in server_addr;
    char *message, server_reply[2000];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1)
    {
        printf("Cannot create socket.\n");
        return 1;
    }

    //Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    //Connection to the server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection failed.\n");
        return 1;
    }

    printf("Connected to the server.\n");

    //Receive a reply from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0)
    {
        printf("Receive failed.\n");
    }

    printf("Server message: %s\n",server_reply);

    //Send a message to server
    message = "H4cK th3 pl4n3t!";
    if (send(socket_desc, message, strlen(message), 0) < 0)
    {
        printf("Send failed.\n");
        return 1;
    }

    printf("Message sent to server.\n");

    //Receive a reply from server
    if (recv(socket_desc, server_reply, 2000, 0) < 0)
    {
        printf("Receive failed.\n");
    }

    printf("Server message: %s\n",server_reply);

    //Close the socket
    close(socket_desc);

    printf("Disconnected from server.\n");

    return 0;
}