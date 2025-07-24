//FormAI DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>

// Defining the MAX_SERVERS value as a constant
#define MAX_SERVERS 10

// Defining the Server struct for storing server information
typedef struct Server {
    char name[20];
    char ip[15];
    int port;
    int status;
} Server;

// Function for printing the server details
void printServerDetails(Server server) {
    printf("Name: %s\n", server.name);
    printf("IP: %s\n", server.ip);
    printf("Port: %d\n", server.port);
    if (server.status == 1) {
        printf("Status: Online\n");
    } else {
        printf("Status: Offline\n");
    }
}

int main() {
    // Initializing the servers array with some default values
    Server servers[MAX_SERVERS] = {
        {"Server A", "192.168.0.1", 80, 1},
        {"Server B", "192.168.0.2", 8080, 0},
        {"Server C", "192.168.0.3", 443, 1},
        {"Server D", "192.168.0.4", 22, 1},
        {"Server E", "192.168.0.5", 3306, 0},
        {"Server F", "192.168.0.6", 1433, 1},
        {"Server G", "192.168.0.7", 27017, 0},
        {"Server H", "192.168.0.8", 8080, 1},
        {"Server I", "192.168.0.9", 21, 0},
        {"Server J", "192.168.0.10", 9000, 1}
    };

    // Looping through all the servers and printing their details
    for (int i = 0; i < MAX_SERVERS; i++) {
        printf("\nServer %d Details:\n", i+1);
        printServerDetails(servers[i]);
    }

    // Changing the first server's status to offline
    servers[0].status = 0;

    // Printing the updated details of the first server
    printf("\nServer 1 Details (Updated):\n");
    printServerDetails(servers[0]);

    return 0;
}