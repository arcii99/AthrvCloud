//FormAI DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void startServer() {
    int serverfd, new_socket, opt=1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Attaching socket to the port 8080
    if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    // Bind the socket to the port 8080
    if (bind(serverfd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming requests
    if (listen(serverfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d\n", PORT);
      
    // Accept incoming connections
    if ((new_socket = accept(serverfd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Welcome message for new client
    char *welcome = "Welcome to the server!\n";
    send(new_socket, welcome, strlen(welcome), 0 );
    sleep(2);

    // Send system information to client
    char *sys_info = "System Information:\n\n";
    send(new_socket, sys_info, strlen(sys_info), 0 );
    char *hostname = "Hostname: ";
    send(new_socket, hostname, strlen(hostname), 0 );
    char hostname_val[1024];
    gethostname(hostname_val, 1024);
    send(new_socket, hostname_val, strlen(hostname_val), 0 );
    char *os_type = "\nOperating System Type: ";
    send(new_socket, os_type, strlen(os_type), 0 );
    char os_type_val[1024] = "Linux"; // assume Linux OS
    send(new_socket, os_type_val, strlen(os_type_val), 0 );
    char *cpu_info = "\nCPU Information: \n";
    send(new_socket, cpu_info, strlen(cpu_info), 0 );
    char cpu_info_val[1024] = "Intel Core i5"; // assume i5
    send(new_socket, cpu_info_val, strlen(cpu_info_val), 0 );
    char *ram_info = "\nRAM Information: \n";
    send(new_socket, ram_info, strlen(ram_info), 0 );
    char ram_info_val[1024] = "8 GB"; // assume 8GB
    send(new_socket, ram_info_val, strlen(ram_info_val), 0 );

    // Close the socket
    close(new_socket);
    close(serverfd);
}

int main() {
    startServer();
    return 0;
}