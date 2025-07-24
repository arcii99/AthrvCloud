//FormAI DATASET v1.0 Category: Firewall ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

void block_ip(char *ip_address);
void block_port(int port);
int check_ip_block(char *ip_address);
int check_port_block(int port);

int main() {
    int sockfd, connfd, len, enable = 1;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];
    bzero(&servaddr, sizeof(servaddr));
    
    //create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Socket creation failed!");
        exit(0);
    }
    //set socket options
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) == -1) {
        perror("Error setting socket options");
        exit(0);
    }
    //configure servaddr
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5000);

    //bind socket
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        perror("Socket bind failed!");
        exit(0);
    }

    //listen to incoming connections
    if(listen(sockfd, 10) != 0) {
        perror("Listen failed!");
        exit(0);
    }

    printf("Server running at port 5000\n");
    
    while(1) {
        len = sizeof(cliaddr);
        //wait for incoming connections
        connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
        if(connfd < 0) {
            perror("Accept failed!");
            exit(0);
        }
        //get client details
        char client_ip[128];
        inet_ntop(AF_INET, &(cliaddr.sin_addr), client_ip, INET_ADDRSTRLEN);
        int client_port = ntohs(cliaddr.sin_port);
        
        //check if client ip is blocked
        if(check_ip_block(client_ip)) {
            printf("Connection from %s:%d blocked by firewall\n", client_ip, client_port);
            close(connfd);
            continue;
        }
        //check if client port is blocked
        if(check_port_block(client_port)) {
            printf("Connection from %s:%d on blocked port %d\n", client_ip, client_port, client_port);
            close(connfd);
            continue;
        }

        printf("Connection from %s:%d\n", client_ip, client_port);
        send(connfd, "Welcome to my server\n", 21, 0);

        //receive data from client
        bzero(buffer, 1024);
        read(connfd, buffer, 1024);
        printf("Received message from %s:%d : %s", client_ip, client_port, buffer);

        close(connfd);
    }
    //close socket
    close(sockfd);
    return 0;
}

//function to block ip addresses
void block_ip(char *ip_address) {
    FILE *fp;
    char command[1000], path[30], buf[20];
    //check if iptables is installed
    if(system("which iptables") == -1) {
        printf("iptables not installed\n");
        return;
    }
    //append ip address to iptables
    sprintf(command, "iptables -A INPUT -s %s -j DROP", ip_address);
    printf("%s\n", command);
    system(command);
    //store blocked ip addresses in a file
    fp = fopen("ip_blocklist.txt", "a+");
    if(fp == NULL) {
        printf("Failed to open file\n");
        return;
    }
    fprintf(fp, "%s\n", ip_address);
    fclose(fp);
}

//function to block ports
void block_port(int port) {
    FILE *fp;
    char command[1000], path[30], buf[20];
    //check if iptables is installed
    if(system("which iptables") == -1) {
        printf("iptables not installed\n");
        return;
    }
    //append port number to iptables
    sprintf(command, "iptables -A INPUT -p tcp --dport %d -j DROP", port);
    printf("%s\n", command);
    system(command);
    //store blocked port numbers in a file
    fp = fopen("port_blocklist.txt", "a+");
    if(fp == NULL) {
        printf("Failed to open file\n");
        return;
    }
    fprintf(fp, "%d\n", port);
    fclose(fp);
}

//function to check if ip is blocked
int check_ip_block(char *ip_address) {
    FILE *fp;
    char line[128];
    //check if ip_blocklist.txt file exists
    if( access( "ip_blocklist.txt", F_OK ) == -1 ) {
        return 0;
    }
    fp = fopen("ip_blocklist.txt", "r");
    if(fp == NULL) {
        printf("Failed to open file\n");
        return 0;
    }
    //read through file and check if ip matches any blocked ip
    while(fgets(line, sizeof(line), fp)) {
        strtok(line, "\n");
        if(strcmp(line, ip_address) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

//function to check if port is blocked
int check_port_block(int port) {
    FILE *fp;
    char line[128];
    //check if port_blocklist.txt file exists
    if( access( "port_blocklist.txt", F_OK ) == -1 ) {
        return 0;
    }
    fp = fopen("port_blocklist.txt", "r");
    if(fp == NULL) {
        printf("Failed to open file\n");
        return 0;
    }
    //read through file and check if port matches any blocked port
    while(fgets(line, sizeof(line), fp)) {
        strtok(line, "\n");
        int blocked_port = atoi(line);
        if(blocked_port == port) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}