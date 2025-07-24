//FormAI DATASET v1.0 Category: Port Scanner ; Style: funny
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        return -1;
    }
    
    char *target = argv[1];
    int start_port = 1, end_port = 65535;
    
    printf("Scanning ports on %s from port %d to port %d...\n\n", target, start_port, end_port);
    
    for(int port = start_port; port <= end_port; port++)
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in sa;
        sa.sin_family = AF_INET;
        sa.sin_port = htons(port);
        inet_pton(AF_INET, target, &sa.sin_addr);

        int result = connect(sock, (struct sockaddr*)&sa, sizeof(sa));
        if(result == 0) 
        {
            printf("Port %d: Open\n", port);
            
            // Let's have some fun!
            printf("Executing malicious code on target...\n");
            printf("Oh wait, this is a port scanner. False alarm!\n\n");
        }
        
        close(sock);
    }

    printf("Scan complete!\n");
    return 0;
}