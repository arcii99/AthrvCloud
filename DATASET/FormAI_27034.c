//FormAI DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf ("Usage: %s <hostname> <starting port> <ending port>\n", argv[0]);
        exit (1);
    }
    
    struct sockaddr_in s_addr;
    int s_socket, i, start_port, end_port, result, b_connect;
    char *hostname;
    hostname = argv[1];
    
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);
    
    memset(&s_addr, '0', sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, hostname, &s_addr.sin_addr) <= 0) {
        printf("Invalid hostname/IP address\n");
        return 1;
    }
    
    for (i=start_port;i<=end_port;i++) {
        s_socket = socket (AF_INET, SOCK_STREAM, 0);
        s_addr.sin_port = htons(i);
        result = connect (s_socket, (struct sockaddr *)&s_addr, sizeof(s_addr));
        if (result == 0) {
            printf("Port %d: OPEN\n",i);
            b_connect = close(s_socket);
            if (b_connect < 0) {
                printf("Error: Closing socket\n");
                return 1;
            }
        }
    }
    
    printf("Scan Completed!\n");
    return 0;
}