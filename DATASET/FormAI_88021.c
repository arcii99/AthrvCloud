//FormAI DATASET v1.0 Category: Firewall ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FIREWALL_PORT 8888      //Port number for firewall server
#define MAX_PACKET_SIZE 1024    //Maximum Packet size

//Structure for Firewall Rule
struct Firewall_Rule
{
    char source_ip[16];
    char dest_ip[16];
    int source_port;
    int dest_port;
};

//Function to check if packet matches a Firewall Rule
int check_firewall_rule(char *packet, struct Firewall_Rule *rule)
{
    //Extract source IP, Destination IP, Source Port and Destination Port from the packet
    char source_ip[16], dest_ip[16];
    int source_port, dest_port;
    sscanf(packet, "%s %d %s %d", source_ip, &source_port, dest_ip, &dest_port);

    //Check if packet matches the given Firewall Rule
    if(strcmp(source_ip, rule->source_ip)==0 && strcmp(dest_ip, rule->dest_ip)==0 && source_port==rule->source_port && dest_port==rule->dest_port)
        return 1;
    return 0;
}

int main()
{
    //Create a socket for Firewall Server
    int server_fd;
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Socket creation error.\n");
        return 0;
    }

    //Set Socket Options
    int opt = 1;
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        printf("Setsockopt error.\n");
        return 0;
    }

    //Bind the socket to a port
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(FIREWALL_PORT);
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Bind error.\n");
        return 0;
    }

    //Start Listening on the socket
    if(listen(server_fd, 3) < 0)
    {
        printf("Listen error.\n");
        return 0;
    }

    //Add Firewall Rules
    struct Firewall_Rule rules[3];
    strcpy(rules[0].source_ip, "192.168.0.1");
    strcpy(rules[0].dest_ip, "10.0.0.1");
    rules[0].source_port = 1234;
    rules[0].dest_port = 5678;
    strcpy(rules[1].source_ip, "10.0.0.2");
    strcpy(rules[1].dest_ip, "192.168.0.2");
    rules[1].source_port = 4321;
    rules[1].dest_port = 8765;
    strcpy(rules[2].source_ip, "172.16.0.1");
    strcpy(rules[2].dest_ip, "10.0.0.3");
    rules[2].source_port = 9999;
    rules[2].dest_port = 1111;

    //Start Loop to handle incoming packets
    while(1)
    {
        //Accept Connection from Client
        int client_fd;
        if((client_fd = accept(server_fd, (struct sockaddr *)NULL, NULL)) < 0)
        {
            printf("Accept error.\n");
            continue;
        }

        //Receive Packet from Client
        char packet[MAX_PACKET_SIZE];
        int read_bytes = read(client_fd, packet, sizeof(packet));
        if(read_bytes <= 0)
        {
            printf("Read error.\n");
            continue;
        }

        //Check the Packet against each Firewall Rule
        int matched = 0;
        for(int i=0; i<3; i++)
        {
            if(check_firewall_rule(packet, &rules[i]))
            {
                printf("Packet Matched Firewall Rule.\n");
                matched = 1;
                break;
            }
        }

        //If Packet does not match any Firewall Rule, Drop it
        if(!matched)
        {
            printf("Packet Dropped.\n");
            close(client_fd);
            continue;
        }

        //If Packet matches a Firewall Rule, Forward it to Destination
        char *dest_ip, *source_ip;
        int dest_port, source_port;
        sscanf(packet, "%s %d %s %d", source_ip, &source_port, dest_ip, &dest_port);

        //Create Connection to Destination
        int dest_fd;
        if((dest_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            printf("Destination Socket creation error.\n");
            continue;
        }
        struct sockaddr_in dest_address;
        memset(&dest_address, 0, sizeof(dest_address));
        dest_address.sin_family = AF_INET;
        dest_address.sin_port = htons(dest_port);
        if(inet_pton(AF_INET, dest_ip, &dest_address.sin_addr)<=0)
        {
            printf("Invalid Destination IP.\n");
            close(dest_fd);
            continue;
        }
        if(connect(dest_fd, (struct sockaddr *)&dest_address, sizeof(dest_address)) < 0)
        {
            printf("Destination Connect error.\n");
            close(dest_fd);
            continue;
        }

        //Forward Packet to Destination
        int write_bytes = write(dest_fd, packet, strlen(packet));
        if(write_bytes <= 0)
        {
            printf("Write error.\n");
            close(dest_fd);
            continue;
        }

        //Close Connection to Destination
        close(dest_fd);

        //Close Connection to Client
        close(client_fd);
    }

    //Close Socket
    close(server_fd);

    return 0;
}