//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

/*
* A simple port scanner program that checks for open ports on a given IP address.
* Written by Chatbot using C programming language.
*/

int main(int argc, char *argv[]) {

    // make sure the user input is correct.
    if (argc != 2) {
        printf("Usage: %s [IP address]\n", argv[0]);
        return 0;
    }

    // get the IP address to scan from the user
    char *ip = argv[1];

    // loop through all the ports and check if they are open
    for (int port = 1; port <= 65535; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        // make the socket non-blocking
        fcntl(sock, F_SETFL, O_NONBLOCK);

        // create the socket address structure
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_aton(ip, &addr.sin_addr);

        // connect to the socket
        int status = connect(sock, (struct sockaddr *)&addr, sizeof(addr));

        // check if the connection was successful
        if (status == 0) {
            printf("[+] Port %d is open.\n", port);
        }

        // close the socket
        close(sock);
    }

    // print a message to let the user know the scan is complete
    printf("[-] Scan complete.\n");

    return 0;
}