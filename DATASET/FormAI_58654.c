//FormAI DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>  
#include <stdlib.h>    
#include <netinet/in.h>  
#include <sys/socket.h>   
#include <arpa/inet.h>  
#include <string.h>  

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Please provide a host IP address and a port number.\nUsage: ./portscanner <host_ip> <port_number>\n");
        exit(1);
    }

    char *host_ip = argv[1];
    int port_number = atoi(argv[2]);
    int sock = 0, conn = 0;
    struct sockaddr_in serv_addr;

    // Clear the memory structure
    memset(&serv_addr, 0, sizeof(serv_addr));
  
    // Set up the socket structure
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error.\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_number);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, host_ip, &serv_addr.sin_addr)<=0) {
        printf("Invalid host IP address.\n");
        exit(1);
    }

    // Attempt to connect to the given port on the host
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Port %d on host %s is closed.\n", port_number, host_ip);
        exit(1);
    }

    // If we successfully connected, then the port is open
    printf("Port %d on host %s is open!\n", port_number, host_ip);
    close(sock);
    return 0;
}