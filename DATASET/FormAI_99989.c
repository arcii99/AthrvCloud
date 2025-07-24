//FormAI DATASET v1.0 Category: Chat server ; Style: distributed
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define PORT 4444
#define BUF_SIZE 2000

int main () {
    int server_sock = 0;
    int client_sock = 0;
    char buf[BUF_SIZE];
    char * server_message = "Welcome to the chat room! Have fun.\n";
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int client_address_size = sizeof(client_address);

    memset(buf,'\0',sizeof(buf));

    // Creating socket
    server_sock = socket(AF_INET,SOCK_STREAM,0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Binding
    bind(server_sock, (struct sockaddr*)&server_address,sizeof(server_address));

    // Listening for clients
    listen(server_sock, 5);
    printf("Server running on port %d\n", PORT);

    while (1) {
        memset(buf,'\0',sizeof(buf));

        // Accepting clients
        client_sock = accept(server_sock, (struct sockaddr*)&client_address, &client_address_size);

        // Displaying data
        printf("Connection established with client: %s:%d\n",
               inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Send welcome message
        send(client_sock,server_message,strlen(server_message),0);

        // Receiving and sending messages
        while (1) {
            if(recv(client_sock,buf,BUF_SIZE,0)<=0){
                perror("Error: ");
                break;
            }
            printf("Client says: ");
            puts(buf);
            
            printf("Enter your message: ");
            fgets(buf,BUF_SIZE,stdin);

            if(strncmp(buf,"bye",3)==0)
                break;

            if(send(client_sock,buf,strlen(buf),0)<0){
                perror("Error: ");
                break;
            }
        }
        close(client_sock);
        printf("Connection closed.\n");
    }
    return 0;
}