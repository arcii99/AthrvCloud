//FormAI DATASET v1.0 Category: Port Scanner ; Style: creative
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) { // make sure only one argument (IP Address or Domain name) is entered
        printf("Invalid number of arguments. Please provide only one IP Address or Domain name.");
        return 1;
    }
  
    char *target = argv[1]; // assign target IP Address or Domain name to a variable
    int sock; // declare socket variable
    sock = socket(AF_INET, SOCK_STREAM, 0); // set up the socket
  
    if(sock < 0) { // check if socket creation was successful
        printf("Socket creation error");
        return 1;
    }
  
    printf("Port scanning... \n"); // Message indicating that port scanning has started
  
    struct sockaddr_in target_sock; // declare struct for target socket information
    target_sock.sin_family = AF_INET;
    target_sock.sin_addr.s_addr = inet_addr(target); // convert IP address from string to struct format
    int socket_status, port; // declare variables for socket status and port
 
    for(port = 1; port <= 65535; port++) { // loop through all 65535 ports 
        target_sock.sin_port = htons(port); // convert port number to network byte order
  
        socket_status = connect(sock, (struct sockaddr *)&target_sock, sizeof target_sock); // check if port is open
  
        if(socket_status == 0) { // if port is open, print a message
            printf("Port %d is open\n", port);
        }
        close(sock); // close the socket to check next port
        sock = socket(AF_INET, SOCK_STREAM, 0); // set up a new socket for the next port
    }
  
    printf("\n Port scanning complete. \n"); // Message indicating that port scanning has completed
    return 0; // return 0 to indicate successful execution
}