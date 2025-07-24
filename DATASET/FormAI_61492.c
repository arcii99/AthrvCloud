//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

void cheer(char* message) {
    printf("\n\nWoo hoo! %s\n\n",message);
}

int main(int argc, char *argv[]) 
{ 
    cheer("Let's scan some ports!"); 

    if (argc < 2) {
        cheer("Oopsie! Looks like you didn't enter an IP address. Try again.\n");
        exit(1); 
    }

    // Create a socket
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        cheer("Aww, the socket couldn't be created. Try again.\n");
        exit(1);
    }

    // Set timeout
    struct timeval tv;
    tv.tv_sec = 3;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    // Set up address struct
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(0);
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);
    memset(target_addr.sin_zero, '\0', sizeof target_addr.sin_zero);

    // Connect
    if (connect(sock, (struct sockaddr *)&target_addr, sizeof target_addr) == -1) {
        cheer("Uh oh, couldn't connect. Either the IP address is invalid or the machine is not online. Try again.\n");
        exit(1);
    }

    // Scan ports
    int start_port = 1;
    int end_port = 65535;

    cheer("Ports that are open:");

    for (int i = start_port; i <= end_port; i++) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr.s_addr = inet_addr(argv[1]);
        memset(addr.sin_zero, '\0', sizeof addr.sin_zero);

        if (connect(sock, (struct sockaddr *)&addr, sizeof addr) == 0) {
            printf("Port %d is open\n", i);
        } else {
            continue;
        }
    }

    // Close socket
    close(sock);

    cheer("That was fun! Let's scan more ports next time!");
    return 0; 
}