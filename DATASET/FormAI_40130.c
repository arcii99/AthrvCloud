//FormAI DATASET v1.0 Category: Port Scanner ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<errno.h>
#include<string.h>
#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(char *ip, int port)
{
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(ip);

    int sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sd < 0)
    {
        printf("Socket creation failed!\n");
        return;
    }

    if(connect(sd, (struct sockaddr *)&target, sizeof(target)) == 0)
    {
        printf("%d OPEN\n", port);
    }
    else
    {
        printf("%d CLOSED\n", port);
    }

    close(sd);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    printf("Scanning ports...\n\n");

    for(int port = MIN_PORT; port <= MAX_PORT; port++)
    {
        usleep(5000);
        scan_port(argv[1], port);
    }

    printf("\nScan finished!\n");

    return 0;
}