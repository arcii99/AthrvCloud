//FormAI DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
int main(int argc, char *argv[]) {
    printf("Welcome to the Grateful Port Scanner! \n");
    printf("Enter IP address to scan: ");
    char *ip_address = malloc(16);
    scanf("%s", ip_address);
 
    printf("Enter starting port number: ");
    int start_port;
    scanf("%d", &start_port);
 
    printf("Enter ending port number: ");
    int end_port;
    scanf("%d", &end_port);
 
    // creating a socket to connect to the target IP address
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        printf("Error: could not create socket!");
        free(ip_address);
        return 1;
    }
 
    // finding out which ports are open
    printf("Scanning ports %d to %d on %s... \n\n", start_port, end_port, ip_address);
    for (int port = start_port; port <= end_port; port++) {
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip_address);
        server.sin_port = htons(port);
 
        // connect to the target port
        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) >= 0) {
            printf("Port %d is open. \n", port);
        }
    }
 
    // closing the socket and free memory
    close(sock);
    free(ip_address);
    printf("\nScan complete! \n");
    return 0;
}