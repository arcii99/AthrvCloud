//FormAI DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535 // maximum number of ports 

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int socket_fd, err_check;
    struct sockaddr_in target;

    // create the socket 
    socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socket_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    
    // fill in the target address information
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(host);
    memset(&(target.sin_zero), '\0', sizeof(target.sin_zero));

    // iterate through ports and check if they are open
    for(int i = 1; i < MAX_PORTS; i++) {
        target.sin_port = htons(i);
        err_check = connect(socket_fd, (struct sockaddr *) &target, sizeof(target));
        if(err_check == 0) {
            printf("Port %d is open on %s\n", i, host);
        }
    }

    // close the socket
    close(socket_fd);
    return 0;
}