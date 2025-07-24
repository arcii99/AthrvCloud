//FormAI DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in target;
    int start_port, end_port, i, result;

    if(argc < 4)
    {
        printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        return 1;
    }

    memset(&target, 0, sizeof(target));   //clear the target struct

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    for(i = start_port; i <= end_port; i++)
    {
        target.sin_port = htons(i);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if(sock < 0)
        {
            perror("socket() failed");
            return 1;
        }

        result = connect(sock, (struct sockaddr *)&target, sizeof(target));
        if(result == 0)
        {
            printf("Port %d is open.\n", i);
        }

        close(sock);
    }

    printf("Scan completed!\n");

    return 0;
}