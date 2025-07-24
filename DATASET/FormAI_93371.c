//FormAI DATASET v1.0 Category: Port Scanner ; Style: visionary
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_PORTS 10000

int main(int argc, char *argv[]){
    char *ip_address;
    int starting_port, ending_port;
    int s, port;
    int count = 0;
    struct sockaddr_in server;

    if(argc != 4){
        printf("Usage: %s <IP_ADDRESS> <STARTING_PORT> <ENDING_PORT>\n", argv[0]);
        return 1;
    }
    ip_address = argv[1];
    starting_port = atoi(argv[2]);
    ending_port = atoi(argv[3]);
    
    for(port = starting_port; port <= ending_port; port++){
        if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0){
            perror("socket");
            return 1;
        }
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr(ip_address);

        if(connect(s, (struct sockaddr *)&server, sizeof(server)) == 0){
            printf("Port %d is open\n", port);
            count++;
        }
        close(s);
    }
    printf("Scan complete. Found %d open port(s)\n", count);
    return 0;
}