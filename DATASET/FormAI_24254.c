//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <ifaddrs.h>

#define PORT 8080

// Function to print IP address in human readable form
void printIpAddress(char *hostname, struct in_addr **addrList) {
    printf("%s : ", hostname);
    for(int i=0; addrList[i]!=NULL; i++) {
        printf("%s ", inet_ntoa(*addrList[i]));
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct ifaddrs *ifAddrStruct = NULL;
    struct ifaddrs *ifa = NULL;
    void *addrPtr = NULL;
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
    char hostname[1024];

    if(gethostname(hostname, 1024) !=0 ) {
        perror("gethostname");
        return 1;
    }
    printf("Hostname: %s\n", hostname);

    if(getifaddrs(&ifAddrStruct) == -1) {
        perror("getifaddrs");
        return 1;
    }

    int count=0;
    printf("\n==== IP Addresses of this machine ====\n");
    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family==AF_INET) { // check it is IP4
            addrPtr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            struct in_addr **addrList = (struct in_addr **) &addrPtr;
            printIpAddress(ifa->ifa_name, addrList);
            count++;
        }
    }
    printf("==== Total number of IPs found: %d ====\n\n", count);

    freeifaddrs(ifAddrStruct);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket creation failed:");
        exit(0);
    }
    printf("\nSocket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        perror("socket bind failed:");
        exit(0);
    }
    printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        perror("listen failed:");
        exit(0);
    }
    printf("Server listening..\n");

    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
    if (connfd < 0) {
        perror("server accept failed:");
        exit(0);
    }
    printf("server accept the client...\n");

    // read the message from client
    char buffer[1024] = {0};
    int valread = read(connfd, buffer, 1024);

    // print the message received from client
    printf("From client: %s\n", buffer);

    // send message to client
    char *hello = "Hello client! I am the Network Topology Mapper";
    write(connfd, hello, strlen(hello));
    printf("Message sent...\n");

    // close the socket
    close(sockfd);

    return 0;
}