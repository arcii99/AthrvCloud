//FormAI DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

void scanPort(char* ipAddress, int portNum){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in targetAddress;
    targetAddress.sin_family = AF_INET;
    targetAddress.sin_addr.s_addr = inet_addr(ipAddress);
    targetAddress.sin_port = htons(portNum);
    int connectionStatus = connect(sock, (struct sockaddr *) &targetAddress, sizeof(targetAddress));
    if(connectionStatus == 0){
        printf("Port %d is open on %s\n", portNum, ipAddress);
        close(sock);
    }
}

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }
    
    char* ipAddress = argv[1];
    for(int i = 1; i <= 65535; i++){
        scanPort(ipAddress, i);
    }
    
    printf("Port scanning complete\n");
    return 0;
}