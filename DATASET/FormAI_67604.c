//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>

#define PORT 8888
#define MAX_BUFFER_SIZE 2000

int run_monitor(char *ip_address);

int main(int argc , char *argv[]) {
    if(argc != 2) {
        printf("Please provide IP address to monitor network QoS\n");
        return 1;
    }
    run_monitor(argv[1]);
    return 0;
}

int run_monitor(char *ip_address) {
    int sock;
    struct sockaddr_in server;
    char message[MAX_BUFFER_SIZE], server_reply[MAX_BUFFER_SIZE];
     
    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    printf("Socket created\n");
     
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons( PORT );
 
    // Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
     
    printf("Connected\n");
     
    // Monitoring loop
    while(1) {
        // Clear buffers
        memset(message, '\0', sizeof(message));
        memset(server_reply, '\0', sizeof(server_reply));
         
        // Send message to server
        strcpy(message, "GET QOS");
        if(send(sock, message, strlen(message), 0) < 0) {
            puts("Send failed");
            return 1;
        }

        // Receive message from server
        if(recv(sock, server_reply, MAX_BUFFER_SIZE, 0) < 0) {
            puts("recv failed");
            break;
        }

        // Print QoS response
        printf("Network QoS: %s\n", server_reply);

        sleep(5); // Sleep for 5 seconds before sending next request
    }

    close(sock);

    return 0;
}