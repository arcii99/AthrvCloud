//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

void scan_port(const char *ip_addr, int port_num)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(port_num);
    
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0)
        printf("Port %d is open.\n", port_num);
    else
        printf("Port %d is closed.\n", port_num);
    
    close(sock);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s IP_ADDRESS PORT_NUMBER\n", argv[0]);
        return 1;
    }
    
    char *ip_addr = argv[1];
    int port_num = atoi(argv[2]);
    
    scan_port(ip_addr, port_num);
    
    return 0;
}