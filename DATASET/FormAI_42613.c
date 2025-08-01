//FormAI DATASET v1.0 Category: Networking ; Style: complete
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[200], server_reply[200];
    
    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
 
    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
     
    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s", message);
         
        //Send some data
        if( send(sock, message, strlen(message), 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        //Receive a reply from the server
        if( recv(sock, server_reply, 200, 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        printf("Server reply : %s\n", server_reply);
        memset(server_reply, 0, 200);
    }
     
    close(sock);
    return 0;
}